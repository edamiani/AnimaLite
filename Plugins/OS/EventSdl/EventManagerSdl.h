#ifndef __AE_OS_EVENT_MANAGER_SDL__
#define __AE_OS_EVENT_MANAGER_SDL__

#include "Anima/OS/EventManager.h"
//#include "Anima/Platform.h"

#include "Plugins/OS/EventSdl/EventQueueSdl.h"

#include <list>

namespace AE
{
	namespace OS
	{
		class EventManagerSdl : public AE::OS::EventManager
		{
		public:
			EventManagerSdl();
			virtual ~EventManagerSdl();
		};
	}
}

#endif