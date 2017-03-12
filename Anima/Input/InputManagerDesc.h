#ifndef __AE_INPUT_MANAGER_DESC__
#define __AE_INPUT_MANAGER_DESC__

#include "Anima/PluginOptions.h"

#include "Anima/OS/EventManager.h"

namespace AE
{
	namespace Input
	{
		struct InputManagerDesc : public AE::PluginOptions
		{
			InputManagerDesc(AE::OS::EventManager *eventManager_) : eventManager(eventManager_) {  }
			~InputManagerDesc() {  }

			AE::OS::EventManager *eventManager;
		};
	}
}

#endif