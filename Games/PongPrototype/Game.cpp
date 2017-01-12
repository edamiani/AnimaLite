#include "Game.h"

#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"

#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"
#include "Anima/PluginManager.h"

#include "Plugins/Graphics/Device/Sfml/ManagerSfml.h"
#include "Plugins/Graphics/Device/Sfml/TextureSfml.h"
#include "Plugins/Graphics/Image/Sfml/ImageSfml.h"
#include "Plugins/Graphics/Image/Sfml/ImageManagerSfml.h"
#include "Plugins/Input/Sdl/ManagerSdl.h"
#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/TimerSdl/TimerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"

#include <memory>

int main(int argc, char* args[])
{
	AE::PluginManager pluginManager;

	auto *eventManager = pluginManager.RegisterPlugin<AE::OS::EventManagerSdl>("EventManager");
	eventManager->Install(AE::NO_OPTIONS);

	auto *inputManager = pluginManager.RegisterPlugin<AE::Input::ManagerSdl>("InputManager");
	AE::Input::InputManagerSdlDesc inputDesc;
	inputDesc.eventManager = eventManager;
	inputManager->Install(AE::NO_OPTIONS, &inputDesc);

	auto *windowManager = pluginManager.RegisterPlugin<AE::OS::WindowManagerSdl>("WindowManager");
	windowManager->Install(AE::NO_OPTIONS);

	auto *deviceManager = pluginManager.RegisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsDeviceManager");
	deviceManager->Install(AE::NO_OPTIONS);

	auto *imageManager = pluginManager.RegisterPlugin<AE::Graphics::ImageManagerSfml>("ImageManager");		
	imageManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Pong Prototype";

	auto window = windowManager->CreateWindow(windowDesc);

	auto *deviceDriver = deviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);

	auto *deviceContext = deviceDriver->CreateDeviceContext(window);

	auto model = std::make_unique<GameModel>();
	auto view = std::make_unique<GameView>(deviceContext, model.get());
	auto controller = std::make_unique<GameController>(pluginManager, model.get());

	eventManager->RegisterWindowListener("WindowListener", controller.get());
	eventManager->RegisterKeyListener("KeyListener", controller.get());
	eventManager->RegisterMouseListener("MouseListener", controller.get());

	window->Show();

	auto timer = std::make_unique<AE::OS::TimerSdl>();
	timer->Start();

	while(controller->IsRunning())
	{
		AE::uint32 deltaTime = timer->GetIntervalFromLastMark();

		controller->Step(deltaTime);
		model->Step(deltaTime);
		view->RenderFrame(deltaTime);
	}

	return 0;
}