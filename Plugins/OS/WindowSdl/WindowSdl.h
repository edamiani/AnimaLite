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

			void			close() { SDL_DestroyWindow(mWindow); }
			WindowHandle	getHandle();
			void			show() { SDL_ShowWindow(mWindow); }

			void			onClose(AE::OS::Window *window) { if(window->getId() == mId) SDL_DestroyWindow(mWindow); }

			SDL_Window*		_getSdlWindow() { return mWindow; }

			void			_setSdlWindow(SDL_Window *window) { mWindow = window; }

		protected:
			SDL_Window		*mWindow;
		};
	}
}

#endif