#ifndef __AE_INPUT_KEY_INFO_SDL__
#define __AE_INPUT_KEY_INFO_SDL__

#include "Anima/Input/Enums.h"
#include "Anima/Input/KeyInfo.h"

#include <map>

namespace AE
{
	namespace Input
	{
		class KeyInfoSdl
		{
		public:
			static std::map<int, AE::Input::KeyCode> mKeyCodes;
			static std::map<AE::Input::KeyCode, int> mKeyCodesSdl;

			static void Initialize();
		};
	}
}

#endif