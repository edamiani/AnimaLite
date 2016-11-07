#ifndef __AE_OS_KEY_LISTENER__
#define __AE_OS_KEY_LISTENER__

#include "Anima/OS/Event.h"
#include "Anima/Input/KeyInfo.h"

#include <memory>

namespace AE
{
	namespace OS
	{
		struct Event;

		class KeyListener
		{
		public:
			KeyListener() {}
			virtual ~KeyListener() 
			{
			}

			// Keyboard events
			virtual void OnKeyDown(const AE::OS::EventKeyboard &event) { }
			virtual void OnKeyUp(const AE::OS::EventKeyboard &event) { }
		};

		typedef std::unique_ptr<KeyListener> KeyListenerPtr;
	}
}

#endif