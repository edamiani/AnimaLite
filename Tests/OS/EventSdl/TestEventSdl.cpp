#include "TestEventSdl.h"

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::initialize();

	auto *eventManager = pluginManager->RegisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->Install(AE::NO_OPTIONS);

	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Window Test";

	auto *window = windowManager->createWindow(windowDesc);

	eventManager->registerWindowListener(window);

	window->show();

	AE::OS::EventQueue *eventQueue = eventManager->getEventQueue();

	while(eventQueue->pollEvents()) { }

	windowManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");

	eventManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	return 0;
}