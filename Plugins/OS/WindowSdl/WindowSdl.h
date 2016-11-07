#ifndef __AE_OS_WINDOW_SDL__
#define __AE_OS_WINDOW_SDL__

#include "Anima/OS/Window.h"
#include "Anima/Platform.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"
#include "Dependencies/SDL2-2.0.4/include/SDL_syswm.h"

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
			WindowSdl(AE::uint id, AE::OS::WindowDesc &windowDesc);
			~WindowSdl();

			void			Close() { SDL_DestroyWindow(mWindow); }
			WindowHandle	GetHandle();
			void			Show() { SDL_ShowWindow(mWindow); }

			void			OnClose(AE::OS::Window *window) { if(window->GetId() == mId) SDL_DestroyWindow(mWindow); }

			SDL_Window*		_GetSdlWindow() { return mWindow; }

			void			_SetSdlWindow(SDL_Window *window) { mWindow = window; }

		protected:
			SDL_SysWMinfo	mSysInfo;
			SDL_Window		*mWindow;
		};
	}
}

#endif