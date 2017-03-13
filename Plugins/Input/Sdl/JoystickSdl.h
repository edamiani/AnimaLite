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
						JoystickSdl(AE::int32 id) : Joystick(id) {  }
			virtual		~JoystickSdl() {  }

			AE::int32	GetAxisValue(AE::uint axisNum) { return SDL_JoystickGetAxis(SDL_JoystickFromInstanceID(mId), axisNum); }
			AE::int32	GetHatValue(AE::uint hatNum) { return SDL_JoystickGetHat(SDL_JoystickFromInstanceID(mId), hatNum); }
			AE::int32	GetNumAxes() { return SDL_JoystickNumAxes(SDL_JoystickFromInstanceID(mId)); }
			AE::int32	GetNumButtons() { return SDL_JoystickNumButtons(SDL_JoystickFromInstanceID(mId)); }
			AE::int32	GetNumHats() { return SDL_JoystickNumHats(SDL_JoystickFromInstanceID(mId)); }
			bool		IsButtonDown(AE::uint button) { return SDL_JoystickGetButton(SDL_JoystickFromInstanceID(mId), button); }
		};
	}
}

#endif