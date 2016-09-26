#ifndef __AE_OS_EVENT_MANAGER_WIN32__
#define __AE_OS_EVENT_MANAGER_WIN32__

#include "Anima/OS/EventManager.h"
#include "Anima/Platform.h"

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

			void registerKeyListener(AE::OS::KeyListener *keyListener);
			void registerMouseListener(AE::OS::MouseListener *mouseListener);
			void unregisterKeyListener(AE::OS::KeyListener *keyListener);
			void unregisterMouseListener(AE::OS::MouseListener *mouseListener);

			bool handleEvents();

		private:
			static std::list<AE::OS::KeyListener *> mKeyListeners;
			static std::list<AE::OS::MouseListener *> mMouseListeners;
		};
	}
}

#endif