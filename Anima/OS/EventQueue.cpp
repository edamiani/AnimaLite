#include "Anima/OS/EventQueue.h"

//std::list<AE::OS::KeyListener *> AE::OS::EventQueue::mKeyListeners;
//std::list<AE::OS::MouseListener *> AE::OS::EventQueue::mMouseListeners;
//std::list<AE::OS::WindowListener *> AE::OS::EventQueue::mWindowListeners;

namespace AE
{
	namespace OS
	{
		EventQueue::~EventQueue()
		{
			mKeyListeners.clear();
			mMouseListeners.clear();
			mWindowListeners.clear();
		}

		void EventQueue::RegisterKeyListener(const std::string &listenerName, AE::OS::KeyListenerPtr keyListener)
		{
			mKeyListeners[listenerName] = std::move(keyListener);
		}
		
		void EventQueue::RegisterMouseListener(const std::string &listenerName, AE::OS::MouseListenerPtr mouseListener)
		{
			mMouseListeners[listenerName] = std::move(mouseListener);
		}

		void EventQueue::RegisterWindowListener(const std::string &listenerName, AE::OS::WindowListenerPtr windowListener)
		{
			mWindowListeners[listenerName] = std::move(windowListener);
		}

		void EventQueue::UnregisterKeyListener(const std::string &listenerName)
		{
			//mKeyListeners.remove(keyListener);
		}
		
		void EventQueue::UnregisterMouseListener(const std::string &listenerName)
		{
			//mMouseListeners.remove(mouseListener);
		}

		void EventQueue::UnregisterWindowListener(const std::string &listenerName)
		{
			//mWindowListeners.remove(windowListener);
		}
	}
}