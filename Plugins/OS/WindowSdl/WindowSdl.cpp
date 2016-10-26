#include "WindowSdl.h"

#include <cassert>

namespace AE
{
	namespace OS
	{
		WindowSdl::WindowSdl(AE::uint id, AE::OS::WindowDesc &windowDesc)
			: Window(id, windowDesc)
		{
			mType[0] = 'S';
			mType[1] = 'D';
			mType[2] = 'L';
			mType[3] = '\0';

			mIsFullScreen = false;

			mWindow = SDL_CreateWindow(windowDesc.title.c_str(), 
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

		WindowHandle WindowSdl::getHandle()
		{
			SDL_SysWMinfo sysInfo;
			SDL_GetWindowWMInfo(mWindow, &sysInfo);

#if defined(AE_PLATFORM_WIN32)
			return sysInfo.info.win.window;

#elif defined(AE_PLATFORM_LINUX)
			return sysInfo.info.x11.window;

#elif defined(AE_PLATFORM_OSX)
			return sysInfo.info.cocoa.window;

#endif
		}
	}
}