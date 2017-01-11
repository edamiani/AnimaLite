#ifndef __AE_INPUT_KEYBOARD__
#define __AE_INPUT_KEYBOARD__

#include "Anima/Input/Device.h"
#include "Anima/Input/KeyInfo.h"

namespace AE
{
	namespace Input
	{
		class Keyboard : public AE::Input::Device
		{
		public:
										Keyboard() {  }
			virtual						~Keyboard() {  }

			virtual AE::Input::KeyCode	getKeyCode(int keyCode) = 0;
			virtual int					getKeyCode(AE::Input::KeyCode keyCode) = 0;
			virtual bool				IsKeyDown(AE::Input::KeyCode code) = 0;
		};
	}
}

#endif