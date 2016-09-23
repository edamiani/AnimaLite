#ifndef __AE_OS_WINDOW_SDL__
#define __AE_OS_WINDOW_SDL__

#include "Anima/OS/Window.h"
#include "Anima/Platform.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Context;
		}
	}

	namespace OS
	{
		class AE_DECLSPEC WindowSdl : public Window
		{
		public:
			WindowSdl(const std::string &windowTitle, const AE::OS::WindowDesc &windowDesc);
			~WindowSdl();

			void	close() { ::DestroyWindow(mWindowHandle); }
			size_t	getWindowHandle();
			void	render();
			void	show() { SDL_ShowWindow(mWindow); }

			HWND _getWindowHandle() { return mWindowHandle; }
			HINSTANCE _getHInstance() { return mHInstance; }
			SDL_Window* _getSdlWindow() { return mWindow; }

			void _setSdlWindow(SDL_Window *window) { mWindow = window; }

		protected:
			HINSTANCE			mHInstance;
			SDL_Window			*mWindow;
			HWND				mWindowHandle;

		};
	}
}

#endif