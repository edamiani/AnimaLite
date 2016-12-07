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

	auto *windowManager = pluginManager.RegisterPlugin<AE::OS::WindowManagerSdl>("WindowManager");
	windowManager->Install(AE::NO_OPTIONS);

	auto *deviceManager = pluginManager.RegisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsDeviceManager");
	deviceManager->Install(AE::NO_OPTIONS);

	auto *imageManager = pluginManager.RegisterPlugin<AE::Graphics::ImageManagerSfml>("ImageManager");
	imageManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Window Test";

	auto window = windowManager->CreateWindow(windowDesc);

	auto *deviceDriver = deviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);

	auto *deviceContext = deviceDriver->CreateDeviceContext(window);

	GameModel model;
	GameView view(model);
	GameController controller(pluginManager, model);

	eventManager->RegisterWindowListener("WindowListener", &controller);
	eventManager->RegisterKeyListener("KeyListener", &controller);
	eventManager->RegisterMouseListener("MouseListener", &controller);

	window->Show();

	auto *timer = new AE::OS::TimerSdl();
	timer->Start();


	// Run game loop
}