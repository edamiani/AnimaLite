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

		void EventQueue::RegisterJoystickListener(const std::string &listenerName, AE::OS::JoystickListener *joystickListener)
		{
			mJoystickListeners[listenerName] = joystickListener;
		}

		void EventQueue::RegisterKeyListener(const std::string &listenerName, AE::OS::KeyListener *keyListener)
		{
			mKeyListeners[listenerName] = keyListener;
		}
		
		void EventQueue::RegisterMouseListener(const std::string &listenerName, AE::OS::MouseListener *mouseListener)
		{
			mMouseListeners[listenerName] = mouseListener;
		}

		void EventQueue::RegisterWindowListener(const std::string &listenerName, AE::OS::WindowListener *windowListener)
		{
			mWindowListeners[listenerName] = windowListener;
		}

		void EventQueue::UnregisterJoystickListener(const std::string &listenerName)
		{
			//mKeyListeners.remove(keyListener);
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