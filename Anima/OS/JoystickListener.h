#ifndef __AE_OS_JOYSTICK_LISTENER__
#define __AE_OS_JOYSTICK_LISTENER__

#include "Anima/OS/Event.h"

#include <memory>

namespace AE
{
	namespace OS
	{
		struct Event;

		class JoystickListener
		{
		public:
			JoystickListener() {}
			virtual ~JoystickListener() 
			{
			}

			// Keyboard events
			virtual void OnAxisMove(const AE::OS::EventJoystick &event) { }
			virtual void OnButtonDown(const AE::OS::EventJoystick &event) { }
			virtual void OnButtonUp(const AE::OS::EventJoystick &event) { }
			virtual void OnHatMove(const AE::OS::EventJoystick &event) { }
		};

		typedef std::unique_ptr<JoystickListener> JoystickListenerPtr;
	}
}

#endif