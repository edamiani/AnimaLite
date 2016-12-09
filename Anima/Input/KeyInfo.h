#ifndef __AE_INPUT_KEY_INFO__
#define __AE_INPUT_KEY_INFO__

#include "Anima/Input/Keyboard.h"

namespace AE
{
	namespace Input
	{
		struct KeyInfo
		{
			KeyInfo(AE::Input::KeyCode kc) : keyCode(kc) {}
			virtual ~KeyInfo() {}

			AE::Input::KeyCode keyCode;
		};
	}
}

#endif