#ifndef __AE_INPUT_KEY_INFO__
#define __AE_INPUT_KEY_INFO__

namespace AE
{
	namespace Input
	{
		enum KeyCode
		{
			KC_BACKSPACE,
			KC_DOWN_ARROW,
			KC_ENTER,
			KC_ESCAPE,
			KC_F1,
			KC_F2,
			KC_F3,
			KC_F4,
			KC_F5,
			KC_F6,
			KC_F7,
			KC_F8,
			KC_F9,
			KC_F10,
			KC_F11,
			KC_F12,
			KC_LEFT_ALT,
			KC_LEFT_ARROW,
			KC_LEFT_SHIFT,
			KC_LEFT_CONTROL,
			KC_RIGHT_ALT,
			KC_RIGHT_ARROW,
			KC_RIGHT_CONTROL,
			KC_RIGHT_SHIFT,
			KC_SPACE,
			KC_UP_ARROW,
			KC_0,
			KC_1,
			KC_2,
			KC_3,
			KC_4,
			KC_5,
			KC_6,
			KC_7,
			KC_8,
			KC_9,
			KC_A,
			KC_B,
			KC_C,
			KC_D,
			KC_E,
			KC_F,
			KC_G,
			KC_H,
			KC_I,
			KC_J,
			KC_K,
			KC_L,
			KC_M,
			KC_N,
			KC_O,
			KC_P,
			KC_Q,
			KC_R,
			KC_S,
			KC_T,
			KC_U,
			KC_V,
			KC_W,
			KC_X,
			KC_Y,
			KC_Z
		};

		struct KeyInfo
		{
			KeyInfo(AE::Input::KeyCode kc) : keyCode(kc) {}
			virtual ~KeyInfo() {}

			AE::Input::KeyCode keyCode;
		};
	}
}

#endif