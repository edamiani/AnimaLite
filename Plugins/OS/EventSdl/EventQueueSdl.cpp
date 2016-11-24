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

		bool EventQueueSdl::GetNextEvent()
		{
			SDL_Event event[1];

			if(SDL_PeepEvents(event, 1, SDL_GETEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) > 0)
			{
				OnEvent(event);

				return true;
			}
			else
			{
				return false;
			}
		}

		bool EventQueueSdl::PeekNextEvent()
		{
			return true;
		}

		bool EventQueueSdl::WaitNextEvent()
		{
			SDL_Event event;

			if(SDL_WaitEvent(&event))
			{
				OnEvent(&event);

				return true;
			}
			else
			{
				return false;
			}
		}

		bool EventQueueSdl::PollEvents()
		{
			SDL_Event event;

			while(SDL_PollEvent(&event))
			{
				if(!OnEvent(&event))
				{
					return false;
				}
			}

			return true;
		}

		bool EventQueueSdl::OnEvent(SDL_Event *event)
		{
			SDL_Window *sdlWindow = SDL_GetWindowFromID(event->window.windowID);
			AE::OS::Window *window = reinterpret_cast<AE::OS::Window *>(SDL_GetWindowData(sdlWindow, "AnimaWindow"));

			if(event->type == SDL_WINDOWEVENT) 
			{
				switch(event->window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
					{
						for(auto &listener : mWindowListeners)
						{
							listener.second->OnClose(*window);
						}
						return true;
					}
					default:
						return true;
				}
			}
			else if(event->type == SDL_KEYDOWN)
			{
				for(auto &listener : mKeyListeners)
				{
					auto keyEvent = AE::OS::EventKeyboard(AE::OS::EST_KEY_DOWN, window, AE::Input::KeyInfo(AE::Input::KC_0));
					listener.second->OnKeyDown(keyEvent);
				}
			}
			else if(event->type == SDL_KEYUP)
			{
				for(auto &listener : mKeyListeners)
				{
					auto keyEvent = AE::OS::EventKeyboard(AE::OS::EST_KEY_UP, window, AE::Input::KeyInfo(AE::Input::KC_0));
					listener.second->OnKeyUp(keyEvent);
				}
			}
			else if(event->type == SDL_MOUSEBUTTONDOWN)
			{
				for(auto &listener : mMouseListeners)
				{
					auto mouseEvent = AE::OS::EventMouse(AE::OS::EST_MOUSE_BUTTON_DOWN, window, 0, AE::Math::Point2<AE::int32>(0, 0));
					listener.second->OnButtonDown(mouseEvent);
				}
			}
			else if(event->type == SDL_MOUSEBUTTONUP)
			{
				AE::uint button;
				switch (event->button.button)
				{
				case SDL_BUTTON_LEFT:
					button = 0;
					break;
				case SDL_BUTTON_MIDDLE:
					button = 1;
					break;
				case SDL_BUTTON_RIGHT:
					button = 2;
					break;
				}

				for(auto &listener : mMouseListeners)
				{
					auto mouseEvent = AE::OS::EventMouse(AE::OS::EST_MOUSE_BUTTON_UP, window, button, AE::Math::Point2<AE::int32>(event->button.x, event->button.y));
					listener.second->OnButtonUp(mouseEvent);
				}
			}
			else if(event->type == SDL_MOUSEMOTION)
			{
				for(auto &listener : mMouseListeners)
				{
					auto mouseEvent = AE::OS::EventMouse(AE::OS::EST_MOUSE_MOVE, window, 0, AE::Math::Point2<AE::int32>(event->button.x, event->button.y));
					listener.second->OnMouseMove(mouseEvent);
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