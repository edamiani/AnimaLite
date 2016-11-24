#ifndef __ANIMA_INPUT_MANAGER__
#define __ANIMA_INPUT_MANAGER__

#include "Keyboard.h"
#include "Mouse.h"

namespace AE
{
	namespace Input
	{
		class Manager
		{
		protected:

		public:
			Manager() {}
			virtual ~Manager() {}

			virtual AE::Input::Keyboard& GetKeyboard() = 0;
			virtual AE::Input::Mouse& GetMouse() = 0;
		};
	}
}

#endif