#ifndef __AE_OS_EVENT_QUEUE__
#define __AE_OS_EVENT_QUEUE__

#include "Anima/OS/JoystickListener.h"
#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"
#include "Anima/OS/WindowListener.h"

#include <string>
#include <map>

namespace AE
{
	namespace OS
	{
		struct Event;

		class EventQueue
		{
		public:
			EventQueue() {}
			virtual ~EventQueue();

			virtual bool GetNextEvent() = 0;
			virtual bool PeekNextEvent() = 0;
			virtual bool PollEvents() = 0;
			virtual void RegisterJoystickListener(const std::string &listenerName, AE::OS::JoystickListener *keyListener);
			virtual void RegisterKeyListener(const std::string &listenerName, AE::OS::KeyListener *keyListener);
			virtual void RegisterMouseListener(const std::string &listenerName, AE::OS::MouseListener *mouseListener);
			virtual void RegisterWindowListener(const std::string &listenerName, AE::OS::WindowListener *windowListener);
			virtual void UnregisterJoystickListener(const std::string &listenerName);
			virtual void UnregisterKeyListener(const std::string &listenerName);
			virtual void UnregisterMouseListener(const std::string &listenerName);
			virtual void UnregisterWindowListener(const std::string &listenerName);
			virtual bool WaitNextEvent() = 0;

		protected:
			std::map<std::string, AE::OS::JoystickListener *>	mJoystickListeners;
			std::map<std::string, AE::OS::KeyListener *>		mKeyListeners;
			std::map<std::string, AE::OS::MouseListener *>		mMouseListeners;
			std::map<std::string, AE::OS::WindowListener *>		mWindowListeners;
		};
	}
}

#endif
