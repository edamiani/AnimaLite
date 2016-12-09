#ifndef __AE_INPUT_MANAGER_SDL_DESC__
#define __AE_INPUT_MANAGER_SDL_DESC__

#include "Anima/PluginOptions.h"

#include "Anima/OS/EventManager.h"

namespace AE
{
	namespace Input
	{
		struct InputManagerSdlDesc : public AE::PluginOptions
		{
			InputManagerSdlDesc() {  }
			~InputManagerSdlDesc() {  }

			AE::OS::EventManager *eventManager;
		};
	}
}

#endif