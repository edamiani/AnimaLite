//#include "../include/AnimaOSProcessManagerWin32.h"
//#include "../include/AnimaOSProcessWin32.h"
#include "Plugins/Input/Sdl/KeyInfoSdl.h"
#include "Plugins/OS/EventSdl/EventQueueSdl.h"
//#include "WindowSdl.h"
//#include "WindowManagerSdl.h"

//#include "AnimaGraphicsManager.h"
//#include "Anima/Input/KeyInfo.h"
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
			mJoystickListeners.clear();
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
			else if(event->type == SDL_JOYAXISMOTION)
			{
				if(event->jaxis.value < -2000 || event->jaxis.value > 2000)
				{
					for(auto &listener : mJoystickListeners)
					{
						auto joyEvent = AE::OS::EventJoystick(AE::OS::EST_JOYSTICK_AXIS, window);
						joyEvent.joystickId = event->jdevice.which;
						joyEvent.axisId = event->jaxis.axis;
						joyEvent.value = event->jaxis.value;
						listener.second->OnAxisMove(joyEvent);
					}
				}
			}
			else if(event->type == SDL_JOYBUTTONDOWN)
			{
				for(auto &listener : mJoystickListeners)
				{
					auto joyEvent = AE::OS::EventJoystick(AE::OS::EST_JOYSTICK_BUTTON_DOWN, window);
					joyEvent.joystickId = event->jdevice.which;
					joyEvent.buttonId = event->jbutton.button;
					listener.second->OnButtonDown(joyEvent);
				}
			}
			else if(event->type == SDL_JOYBUTTONUP)
			{
				for(auto &listener : mJoystickListeners)
				{
					auto joyEvent = AE::OS::EventJoystick(AE::OS::EST_JOYSTICK_BUTTON_DOWN, window);
					joyEvent.joystickId = event->jdevice.which;
					joyEvent.buttonId = event->jbutton.button;
					listener.second->OnButtonUp(joyEvent);
				}
			}

			else if(event->type == SDL_JOYHATMOTION)
			{
				for(auto &listener : mJoystickListeners)
				{
					auto joyEvent = AE::OS::EventJoystick(AE::OS::EST_JOYSTICK_HAT, window);
					joyEvent.joystickId = event->jdevice.which;
					joyEvent.hatId = event->jhat.hat;
					joyEvent.value = event->jhat.value;
					listener.second->OnHatMove(joyEvent);
				}
			}
			else if(event->type == SDL_KEYDOWN)
			{
				for(auto &listener : mKeyListeners)
				{
					auto keyEvent = AE::OS::EventKeyboard(AE::OS::EST_KEY_DOWN, window, AE::Input::KeyInfoSdl::mKeyCodes[event->key.keysym.sym]);
					listener.second->OnKeyDown(keyEvent);
				}
			}
			else if(event->type == SDL_KEYUP)
			{
				for(auto &listener : mKeyListeners)
				{
					auto keyEvent = AE::OS::EventKeyboard(AE::OS::EST_KEY_UP, window, AE::Input::KeyInfoSdl::mKeyCodes[event->key.keysym.sym]);
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