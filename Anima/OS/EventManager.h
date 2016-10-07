#ifndef __AE_OS_EVENT_MANAGER__
#define __AE_OS_EVENT_MANAGER__

#include "Anima/Plugin.h"
#include "Anima/OS/EventQueue.h"

#include <map>

namespace AE
{
	namespace OS
	{
		class KeyListener;
		class MouseListener;
		class WindowListener;

		class EventManager : public AE::Plugin
		{
		public:
								EventManager() : Plugin(AE::PT_OS_EVENT_MANAGER) {}
			virtual				~EventManager() {}

			virtual bool		Install(AE::uint options) = 0;
			virtual void		registerKeyListener(AE::OS::KeyListener *keyListener) { if(mEventQueue) mEventQueue->registerKeyListener(keyListener); }
			virtual void		registerMouseListener(AE::OS::MouseListener *mouseListener) { if(mEventQueue) mEventQueue->registerMouseListener(mouseListener); }
			virtual void		registerWindowListener(AE::OS::WindowListener *windowListener) { if(mEventQueue) mEventQueue->registerWindowListener(windowListener); }
			virtual bool		Uninstall() = 0;
			virtual void		unregisterKeyListener(AE::OS::KeyListener *keyListener) { if(mEventQueue) mEventQueue->unregisterKeyListener(keyListener); }
			virtual void		unregisterMouseListener(AE::OS::MouseListener *mouseListener) { if(mEventQueue) mEventQueue->unregisterMouseListener(mouseListener); }
			virtual void		unregisterWindowListener(AE::OS::WindowListener *windowListener) { if(mEventQueue) mEventQueue->unregisterWindowListener(windowListener); }

			AE::OS::EventQueue* getEventQueue() { return mEventQueue; }

		protected:
			AE::OS::EventQueue	*mEventQueue = nullptr;
		};
	}
}

#endif