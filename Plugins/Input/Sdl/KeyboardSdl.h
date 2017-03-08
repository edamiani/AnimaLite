#ifndef __AE_INPUT_KEYBOARD_SDL__
#define __AE_INPUT_KEYBOARD_SDL__

#include "Anima/Input/Keyboard.h"
#include "KeyInfoSdl.h"

#include "Plugins/Input/Sdl/KeyInfoSdl.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

#include <map>

namespace AE
{
	namespace Input
	{
		class KeyboardSdl : public AE::Input::Keyboard
		{
		public:
			KeyboardSdl() 
			{
				AE::Input::KeyInfoSdl::Initialize();
			}

			virtual		~KeyboardSdl() {  }

			virtual AE::Input::KeyCode GetKeyCode(int keyCode) { return AE::Input::KeyInfoSdl::mKeyCodes[keyCode]; }
			virtual int GetKeyCode(AE::Input::KeyCode keyCode) { return AE::Input::KeyInfoSdl::mKeyCodesSdl[keyCode]; }

			bool		IsKeyDown(AE::Input::KeyCode code) 
			{ 
				const Uint8 *state = SDL_GetKeyboardState(NULL);

				if(state[SDL_GetScancodeFromKey(AE::Input::KeyInfoSdl::mKeyCodesSdl[code])])
				{
					return true;
				}
			}

			bool		Poll() { return true; }
		};
	}
}

#endif