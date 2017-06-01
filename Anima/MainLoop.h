#ifndef __AE_MAIN_LOOP__
#define __AE_MAIN_LOOP__

#include "PluginManager.h"
#include "OS/EventManager.h"

#include <cassert>

namespace AE
{
	class MainLoop
	{
	public:
		MainLoop(AE::PluginManager *pluginManager);
		virtual ~MainLoop() {}

		virtual void Run();

		virtual void OnFinish() {}
		virtual void OnStart() {}
		virtual void OnUpdate() {}

	protected:
		AE::OS::EventQueue	*mEventQueue;
		AE::PluginManager	*mPluginManager;
	};
}

#endif