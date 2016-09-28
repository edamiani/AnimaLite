#ifndef __AE_OS_EVENT_MANAGER__
#define __AE_OS_EVENT_MANAGER__

//#include "Anima/OS/KeyListener.h"
//#include "Anima/OS/MouseListener.h"
//#include "Anima/OS/WindowMetrics.h"
//#include "Anima/Platform.h"

#include "Anima/OS/EventQueue.h"

#include <map>

namespace AE
{
	namespace OS
	{
		class KeyListener;
		class MouseListener;
		class WindowListener;

		class EventManager
		{
		public:
			EventManager() {}
			virtual ~EventManager() {}

			virtual void registerKeyListener(AE::OS::KeyListener *keyListener) { if(mEventQueue) mEventQueue->registerKeyListener(keyListener); }
			virtual void registerMouseListener(AE::OS::MouseListener *mouseListener) { if(mEventQueue) mEventQueue->registerMouseListener(mouseListener); }
			virtual void registerWindowListener(AE::OS::WindowListener *windowListener) { if(mEventQueue) mEventQueue->registerWindowListener(windowListener); }
			virtual void unregisterKeyListener(AE::OS::KeyListener *keyListener) { if(mEventQueue) mEventQueue->unregisterKeyListener(keyListener); }
			virtual void unregisterMouseListener(AE::OS::MouseListener *mouseListener) { if(mEventQueue) mEventQueue->unregisterMouseListener(mouseListener); }
			virtual void unregisterWindowListener(AE::OS::WindowListener *windowListener) { if(mEventQueue) mEventQueue->unregisterWindowListener(windowListener); }

		protected:
			//AE::OS::WindowMetrics mWindowMetrics;
			AE::OS::EventQueue *mEventQueue = nullptr;
		};
	}
}

#endif