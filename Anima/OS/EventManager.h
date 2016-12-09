#ifndef __AE_OS_EVENT_MANAGER__
#define __AE_OS_EVENT_MANAGER__

#include "Anima/Plugin.h"
#include "Anima/OS/EventQueue.h"
#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"
#include "Anima/OS/WindowListener.h"

#include <map>

namespace AE
{
	namespace OS
	{
		class EventManager : public AE::Plugin
		{
		public:
								EventManager() : Plugin(AE::PT_OS_EVENT_MANAGER) {}
			virtual				~EventManager() {}

			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual void		RegisterKeyListener(const std::string &listenerName, AE::OS::KeyListener *keyListener) { if(mEventQueue) mEventQueue->RegisterKeyListener(listenerName, keyListener); }
			virtual void		RegisterMouseListener(const std::string &listenerName, AE::OS::MouseListener *mouseListener) { if(mEventQueue) mEventQueue->RegisterMouseListener(listenerName, mouseListener); }
			virtual void		RegisterWindowListener(const std::string &listenerName, AE::OS::WindowListener *windowListener) { if(mEventQueue) mEventQueue->RegisterWindowListener(listenerName, windowListener); }
			virtual bool		Uninstall() = 0;
			virtual void		UnregisterKeyListener(const std::string &listenerName) { if(mEventQueue) mEventQueue->UnregisterKeyListener(listenerName); }
			virtual void		UnregisterMouseListener(const std::string &listenerName) { if(mEventQueue) mEventQueue->UnregisterMouseListener(listenerName); }
			virtual void		UnregisterWindowListener(const std::string &listenerName) { if(mEventQueue) mEventQueue->UnregisterWindowListener(listenerName); }

			AE::OS::EventQueue* GetEventQueue() { return mEventQueue; }

		protected:
			AE::OS::EventQueue	*mEventQueue = nullptr;
		};
	}
}

#endif