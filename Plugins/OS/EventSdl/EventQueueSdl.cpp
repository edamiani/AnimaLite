//#include "../include/AnimaOSProcessManagerWin32.h"
//#include "../include/AnimaOSProcessWin32.h"
#include "Plugins/OS/EventSdl/EventQueueSdl.h"
//#include "WindowSdl.h"
//#include "WindowManagerSdl.h"

//#include "AnimaGraphicsManager.h"
#include "Anima/Input/KeyInfo.h"
#include "Anima/OS/Event.h"

#include <cassert>

namespace AE
{
	namespace OS
	{
		EventQueueSdl::EventQueueSdl()
		{
			
		}

		EventQueueSdl::~EventQueueSdl()
		{
			mKeyListeners.clear();
			mMouseListeners.clear();
			mWindowListeners.clear();
		}

		bool EventQueueSdl::getNextEvent()
		{
			SDL_Event event[1];

			if(SDL_PeepEvents(event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) > 0)
			{
				onEvent(event);

				return true;
			}
			else
			{
				return false;
			}
		}

		bool EventQueueSdl::peekNextEvent()
		{
			return true;
		}

		void EventQueueSdl::registerWindowListener(AE::OS::WindowListener *windowListener)
		{
			mWindowListeners.push_back(windowListener);
		}

		bool EventQueueSdl::waitNextEvent()
		{
			SDL_Event event;

			if(SDL_WaitEvent(&event))
			{
				onEvent(&event);

				return true;
			}
			else
			{
				return false;
			}
		}

		bool EventQueueSdl::pollEvents()
		{
			SDL_Event event;

			while(SDL_PollEvent(&event))
			{
				if(!onEvent(&event))
				{
					return false;
				}
			}

			return true;
		}

		bool EventQueueSdl::onEvent(SDL_Event *event)
		{
			if(event->type == SDL_WINDOWEVENT) 
			{
				SDL_Window *sdlWindow = SDL_GetWindowFromID(event->window.windowID);
				AE::OS::Window *window = reinterpret_cast<AE::OS::Window *>(SDL_GetWindowData(sdlWindow, "AnimaWindow"));

				switch(event->window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
					{
						std::list<AE::OS::WindowListener *>::iterator i;
						for(i = mWindowListeners.begin(); i != mWindowListeners.end(); i++)
						{
							(*i)->onClose(window);
						}
						return true;
					}
					default:
						return true;
				}
			}
			else if(event->type == SDL_QUIT)
			{
				return false;
			}

			return true;
		}
	}
}