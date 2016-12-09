#include "EventManagerSdl.h"

#include "Anima/Input/KeyInfo.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace OS
	{
		EventManagerSdl::EventManagerSdl()
		{
			
		}

		EventManagerSdl::~EventManagerSdl()
		{
			
		}

		bool EventManagerSdl::Install(AE::uint options, PluginOptions *pluginDesc = nullptr)
		{
			if(!SDL_WasInit(SDL_INIT_EVENTS))
			{
				SDL_InitSubSystem(SDL_INIT_EVENTS);
			}

			mEventQueue = new AE::OS::EventQueueSdl();

			return true;
		}

		bool EventManagerSdl::Uninstall()
		{
			if(SDL_WasInit(SDL_INIT_EVENTS))
			{
				SDL_QuitSubSystem(SDL_INIT_EVENTS);
			}

			if(mEventQueue)
			{
				delete mEventQueue;
			}

			return true;
		}
	}
}