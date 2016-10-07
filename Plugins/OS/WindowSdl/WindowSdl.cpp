#include "WindowSdl.h"

#include <cassert>

namespace AE
{
	namespace OS
	{
		WindowSdl::WindowSdl(AE::uint id, AE::OS::WindowDesc &windowDesc)
			: Window(id, windowDesc)
		{
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
	}
}