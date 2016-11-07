#ifndef __AE_OS_EVENT_QUEUE__
#define __AE_OS_EVENT_QUEUE__

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
			virtual void RegisterKeyListener(const std::string &listenerName, AE::OS::KeyListenerPtr keyListener);
			virtual void RegisterMouseListener(const std::string &listenerName, AE::OS::MouseListenerPtr mouseListener);
			virtual void RegisterWindowListener(const std::string &listenerName, AE::OS::WindowListenerPtr windowListener);
			virtual void UnregisterKeyListener(const std::string &listenerName);
			virtual void UnregisterMouseListener(const std::string &listenerName);
			virtual void UnregisterWindowListener(const std::string &listenerName);
			virtual bool WaitNextEvent() = 0;

		protected:
			std::map<std::string, AE::OS::KeyListenerPtr>		mKeyListeners;
			std::map<std::string, AE::OS::MouseListenerPtr>		mMouseListeners;
			std::map<std::string, AE::OS::WindowListenerPtr>	mWindowListeners;
		};
	}
}

#endif
