#include "TestWindowSdl.h"

int main(int argc, char* args[])
{
	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);

	AE::OS::Window *window = new AE::OS::WindowSdl(0, "Test", windowDesc);

	AE::OS::EventManagerSdl *eventManager = new AE::OS::EventManagerSdl();
	eventManager->registerWindowListener(window);

	AE::OS::EventQueue *eventQueue = eventManager->getEventQueue();

	window->show();

	while(eventQueue->pollEvents()) { }

	return 0;
}