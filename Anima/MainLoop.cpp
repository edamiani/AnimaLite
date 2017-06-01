#include "MainLoop.h"

namespace AE
{
	MainLoop::MainLoop(AE::PluginManager *pluginManager)
		: mPluginManager(pluginManager)
	{
		AE::OS::EventManager *eventManager = mPluginManager->GetInstalledPluginByType<AE::OS::EventManager>(AE::PT_OS_EVENT_MANAGER);

		assert(eventManager != nullptr);

		mEventQueue = eventManager->GetEventQueue();
	}

	void MainLoop::Run()
	{
		while(mEventQueue->PollEvents()) 
		{

		}
	}
}