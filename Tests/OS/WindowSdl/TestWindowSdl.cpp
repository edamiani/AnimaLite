#include "TestWindowSdl.h"

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::initialize();

	auto *eventManager = pluginManager->registerPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->install(AE::NO_OPTIONS);

	auto *windowManager = pluginManager->registerPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);

	auto *window = windowManager->createWindow("Window Test", windowDesc);

	eventManager->registerWindowListener(window);

	window->show();

	AE::OS::EventQueue *eventQueue = eventManager->getEventQueue();

	while(eventQueue->pollEvents()) { }

	windowManager->uninstall();
	pluginManager->unregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");

	eventManager->uninstall();
	pluginManager->unregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	return 0;
}