#include "Ch04-Input.h"

#include <iostream>
#include <memory>

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::Initialize();

	auto *eventManager = pluginManager->RegisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->Install(AE::NO_OPTIONS);

	auto *inputManager = pluginManager->RegisterPlugin<AE::Input::ManagerSdl>("InputSdl");
	inputManager->Install(AE::NO_OPTIONS, new AE::Input::InputManagerDesc(eventManager));

	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Event Test";

	auto window = windowManager->CreateWindow(windowDesc);

	auto testListener = std::make_unique<TestListener>();

	eventManager->RegisterWindowListener("WindowListener", testListener.get());

	window->Show();

	AE::OS::EventQueue *eventQueue = eventManager->GetEventQueue();

	//AE::Input::Joystick *joystick = inputManager->GetJoystick();
	AE::Input::Keyboard *keyboard = inputManager->GetKeyboard();
	AE::Input::Mouse *mouse = inputManager->GetMouse();

	while(eventQueue->PollEvents()) 
	{
		if(keyboard->IsKeyDown(AE::Input::KC_X))
		{
			std::cout << "X key pressed!" << std::endl;
		}
	}

	//windowManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");

	//inputManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::Input::ManagerSdl>("InputSdl");

	//eventManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	return 0;
}