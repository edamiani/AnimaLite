#ifndef __AE_INPUT_DEVICE_SDL__
#define __AE_INPUT_DEVICE_SDL__

#include "Anima/OS/EventManager.h"

namespace AE
{
	namespace Input
	{
		class DeviceSdl
		{
		public:
							DeviceSdl(const AE::OS::EventManager &eventManager) { eventManager.RegisterKeyListener }
							~DeviceSdl() {  }

			bool			Poll() { return true; }

		protected:
			
		};
	}
}

#endif