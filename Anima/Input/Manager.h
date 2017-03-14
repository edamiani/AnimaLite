#ifndef __ANIMA_INPUT_MANAGER__
#define __ANIMA_INPUT_MANAGER__

#include "Joystick.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "Anima/Plugin.h"

namespace AE
{
	namespace Input
	{
		class Manager : public AE::Plugin
		{
		protected:

		public:
			Manager() : AE::Plugin(AE::PT_INPUT_MANAGER) {}
			virtual ~Manager() {}

			virtual AE::Input::Joystick*	GetJoystick(AE::uint index) = 0;
			virtual AE::Input::Keyboard*	GetKeyboard() = 0;
			virtual AE::Input::Mouse*		GetMouse() = 0;
			virtual AE::uint				GetNumJoysticks() = 0;

			/***** Inherited from AE::Plugin
			virtual bool								Install(AE::uint options) = 0;
			virtual bool								Uninstall() = 0;
			*****/
		};
	}
}

#endif