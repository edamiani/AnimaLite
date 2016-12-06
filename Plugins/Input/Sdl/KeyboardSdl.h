#ifndef __AE_INPUT_KEYBOARD_SDL__
#define __AE_INPUT_KEYBOARD_SDL__

#include "Anima/Input/Keyboard.h"

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
				mKeyCodes[AE::Input::KC_BACKSPACE] = SDLK_BACKSPACE;
				mKeyCodes[AE::Input::KC_DOWN_ARROW] = SDLK_DOWN;
				mKeyCodes[AE::Input::KC_ENTER] = SDLK_RETURN;
				mKeyCodes[AE::Input::KC_ESCAPE] = SDLK_ESCAPE;
				mKeyCodes[AE::Input::KC_F1] = SDLK_F1;
				mKeyCodes[AE::Input::KC_F2] = SDLK_F2;
				mKeyCodes[AE::Input::KC_F3] = SDLK_F3;
				mKeyCodes[AE::Input::KC_F4] = SDLK_F4;
				mKeyCodes[AE::Input::KC_F5] = SDLK_F5;
				mKeyCodes[AE::Input::KC_F6] = SDLK_F6;
				mKeyCodes[AE::Input::KC_F7] = SDLK_F7;
				mKeyCodes[AE::Input::KC_F8] = SDLK_F8;
				mKeyCodes[AE::Input::KC_F9] = SDLK_F9;
				mKeyCodes[AE::Input::KC_F10] = SDLK_F10;
				mKeyCodes[AE::Input::KC_F11] = SDLK_F11;
				mKeyCodes[AE::Input::KC_F12] = SDLK_F12;
				mKeyCodes[AE::Input::KC_LEFT_ALT] = SDLK_LALT;
				mKeyCodes[AE::Input::KC_LEFT_ARROW] = SDLK_LEFT;
				mKeyCodes[AE::Input::KC_LEFT_CONTROL] = SDLK_LCTRL;
				mKeyCodes[AE::Input::KC_LEFT_SHIFT] = SDLK_LSHIFT;
				mKeyCodes[AE::Input::KC_RIGHT_ALT] = SDLK_RALT;
				mKeyCodes[AE::Input::KC_RIGHT_ARROW] = SDLK_RIGHT;
				mKeyCodes[AE::Input::KC_RIGHT_CONTROL] = SDLK_RCTRL;
				mKeyCodes[AE::Input::KC_RIGHT_SHIFT] = SDLK_RSHIFT;
				mKeyCodes[AE::Input::KC_SPACE] = SDLK_SPACE;
				mKeyCodes[AE::Input::KC_UP_ARROW] = SDLK_UP;
				mKeyCodes[AE::Input::KC_0] = SDLK_0;
				mKeyCodes[AE::Input::KC_1] = SDLK_1;
				mKeyCodes[AE::Input::KC_2] = SDLK_2;
				mKeyCodes[AE::Input::KC_3] = SDLK_3;
				mKeyCodes[AE::Input::KC_4] = SDLK_4;
				mKeyCodes[AE::Input::KC_5] = SDLK_5;
				mKeyCodes[AE::Input::KC_6] = SDLK_6;
				mKeyCodes[AE::Input::KC_7] = SDLK_7;
				mKeyCodes[AE::Input::KC_8] = SDLK_8;
				mKeyCodes[AE::Input::KC_9] = SDLK_9;
				mKeyCodes[AE::Input::KC_A] = SDLK_a;
				mKeyCodes[AE::Input::KC_B] = SDLK_b;
				mKeyCodes[AE::Input::KC_C] = SDLK_c;
				mKeyCodes[AE::Input::KC_D] = SDLK_d;
				mKeyCodes[AE::Input::KC_E] = SDLK_e;
				mKeyCodes[AE::Input::KC_F] = SDLK_f;
				mKeyCodes[AE::Input::KC_G] = SDLK_g;
				mKeyCodes[AE::Input::KC_H] = SDLK_h;
				mKeyCodes[AE::Input::KC_I] = SDLK_i;
				mKeyCodes[AE::Input::KC_J] = SDLK_j;
				mKeyCodes[AE::Input::KC_K] = SDLK_k;
				mKeyCodes[AE::Input::KC_L] = SDLK_l;
				mKeyCodes[AE::Input::KC_M] = SDLK_m;
				mKeyCodes[AE::Input::KC_N] = SDLK_n;
				mKeyCodes[AE::Input::KC_O] = SDLK_o;
				mKeyCodes[AE::Input::KC_P] = SDLK_p;
				mKeyCodes[AE::Input::KC_Q] = SDLK_q;
				mKeyCodes[AE::Input::KC_R] = SDLK_r;
				mKeyCodes[AE::Input::KC_S] = SDLK_s;
				mKeyCodes[AE::Input::KC_T] = SDLK_t;
				mKeyCodes[AE::Input::KC_U] = SDLK_u;
				mKeyCodes[AE::Input::KC_V] = SDLK_v;
				mKeyCodes[AE::Input::KC_W] = SDLK_w;
				mKeyCodes[AE::Input::KC_X] = SDLK_x;
				mKeyCodes[AE::Input::KC_Y] = SDLK_y;
				mKeyCodes[AE::Input::KC_Z] = SDLK_z;	
			}

			virtual		~KeyboardSdl() {  }

			bool		IsKeyDown(AE::Input::KeyCode code) { return true; }
			bool		Poll() { return true; }

		private:
			std::map<AE::Input::KeyCode, int> mKeyCodes;
		};
	}
}

#endif