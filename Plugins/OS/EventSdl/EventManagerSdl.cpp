#include "EventManagerSdl.h"

#include "Anima/Input/KeyInfo.h"

#include "Plugins/Input/Sdl/KeyInfoSdl.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace OS
	{
		EventManagerSdl::EventManagerSdl()
		{
			AE::Input::KeyInfoSdl::Initialize();
		}

		EventManagerSdl::~EventManagerSdl()
		{
			
		}

		bool EventManagerSdl::Install(AE::uint options, PluginOptions *pluginDesc)
		{
			if(!SDL_WasInit(SDL_INIT_EVENTS))
			{
				SDL_InitSubSystem(SDL_INIT_EVENTS);
			}

			if(!SDL_WasInit(SDL_INIT_JOYSTICK))
			{
				SDL_InitSubSystem(SDL_INIT_JOYSTICK);
			}

			int numJoysticks = SDL_NumJoysticks();

			for(int i = 0; i < numJoysticks; i++)
			{
				SDL_JoystickOpen(i);
			}

			mEventQueue = new AE::OS::EventQueueSdl();

			mIsInstalled = true;

			return true;
		}

		bool EventManagerSdl::Uninstall()
		{
			if(mEventQueue)
			{
				delete mEventQueue;
			}

			if(SDL_WasInit(SDL_INIT_EVENTS))
			{
				SDL_QuitSubSystem(SDL_INIT_EVENTS);
			}

			if(SDL_WasInit(SDL_INIT_JOYSTICK))
			{
				SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
			}

			return true;
		}
	}
}