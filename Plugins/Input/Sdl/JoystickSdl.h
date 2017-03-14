#ifndef __AE_INPUT_JOYSTICK_SDL__
#define __AE_INPUT_JOYSTICK_SDL__

#include "Anima/Types.h"
#include "Anima/Input/Joystick.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

#include <vector>

namespace AE
{
	namespace Input
	{
		class JoystickSdl : public AE::Input::Joystick
		{
		public:
			JoystickSdl(AE::int32 id) : Joystick(id) 
			{
				mSdlJoystick = SDL_JoystickFromInstanceID(id);
			}

			virtual		~JoystickSdl() {  }

			AE::int32	GetAxisValue(AE::uint axisNum) { return SDL_JoystickGetAxis(mSdlJoystick, axisNum); }
			AE::int32	GetHatValue(AE::uint hatNum) { return SDL_JoystickGetHat(mSdlJoystick, hatNum); }
			AE::int32	GetNumAxes() { return SDL_JoystickNumAxes(mSdlJoystick); }
			AE::int32	GetNumButtons() { return SDL_JoystickNumButtons(mSdlJoystick); }
			AE::int32	GetNumHats() { return SDL_JoystickNumHats(mSdlJoystick); }
			bool		IsButtonDown(AE::uint button) 
			{ 
				int result = SDL_JoystickGetButton(mSdlJoystick, button);
				return result; 
			}
			bool		Poll() { return false; }

		private:
			SDL_Joystick *mSdlJoystick;
		};
	}
}

#endif