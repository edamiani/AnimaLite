#include "WindowSdl.h"
//#include "EventQueueSdl.h"

#include <cassert>

namespace AE
{
	namespace OS
	{
		WindowSdl::WindowSdl(AE::uint id, const std::string &windowTitle, AE::OS::WindowDesc &windowDesc)
			: Window(id, windowTitle, windowDesc)
		{
			mIsFullScreen = false;

			mWindow = SDL_CreateWindow(windowTitle.c_str(), 
									   static_cast<int>(windowDesc.position.x()), static_cast<int>(windowDesc.position.y()),
									   static_cast<int>(windowDesc.dimensions.x()), static_cast<int>(windowDesc.dimensions.y()), 
									   SDL_WINDOW_HIDDEN);

			SDL_SetWindowData(mWindow, "AnimaWindow", this);
		}

		WindowSdl::~WindowSdl()
		{
			if(mWindow)
			{
				SDL_DestroyWindow(mWindow);
			}
		}

		size_t WindowSdl::getWindowHandle()
		{
			/*size_t winHandle;
			HWND *pHwnd = (HWND*)(&winHandle);
			*pHwnd = mWindowHandle;
			return winHandle;*/

			return 0;
		}

		void WindowSdl::render()
		{

		}
	}
}