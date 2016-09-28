#include "Plugins/OS/EventSdl/EventManagerSdl.h"

#include "Anima/Input/KeyInfo.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

#include <cassert>

namespace AE
{
	namespace OS
	{
		//std::list<AE::OS::KeyListener *> EventManagerSdl::mKeyListeners;
		//std::list<AE::OS::MouseListener *> EventManagerSdl::mMouseListeners;

		bool handleEvents()
		{
			SDL_Event *event;
			while(SDL_PollEvent(event))
			{
				if(event->type == SDL_WINDOWEVENT)
				{
					switch(event->window.type)
					{
					case SDL_WINDOWEVENT_CLOSE:
						//for(auto window : mWin)
						break;
					}
				}
			}
		}

		/*LRESULT WINAPI EventManagerWin32::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			AE::OS::WindowWin32 *window = reinterpret_cast<AE::OS::WindowWin32 *>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
			switch( msg )
			{
					case WM_DESTROY:
						::PostQuitMessage(0);
						break;
					case WM_CLOSE:
						if(window) window->onClose();
						break;
					case WM_DISPLAYCHANGE:
						if(window) window->onDisplayChange();
						break;
					case WM_KEYDOWN:
						{
							std::list<AE::OS::KeyListener *>::iterator i;
							for(i = mKeyListeners.begin(); i != mKeyListeners.end(); i++)
							{
								AE::Input::KeyInfo keyInfo = AE::Input::KeyInfo((AE::Input::KeyValue)wParam);
								(*i)->onKeyDown(AE::Input::KeyInfo(keyInfo));
							}
						}
						break;
					case WM_KEYUP:
						{
							std::list<AE::OS::KeyListener *>::iterator i;
							for(i = mKeyListeners.begin(); i != mKeyListeners.end(); i++)
							{
								AE::Input::KeyInfo keyInfo = AE::Input::KeyInfo((AE::Input::KeyValue)wParam);
								(*i)->onKeyUp(AE::Input::KeyInfo(keyInfo));
							}
						}
						break;
					case WM_PAINT:
						if(window) window->render();
						break;
					case WM_SIZE:
						if(window) window->onResize();
						break;
					case WM_MOUSEMOVE:
						{
							std::list<AE::OS::MouseListener *>::iterator i;
							for(i = mMouseListeners.begin(); i != mMouseListeners.end(); i++)
								(*i)->onMouseMove();
							break;
						}
					case WM_LBUTTONUP:
						break;
			}
			return ::DefWindowProc( hWnd, msg, wParam, lParam );
		}*/
	}
}