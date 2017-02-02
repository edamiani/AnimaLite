#include "WindowManagerSdl.h"

#include "EventQueueSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"

namespace AE
{
	namespace Graphics
	{

	}

	namespace OS
	{
		WindowManagerSdl::WindowManagerSdl()
		{
		}

		WindowManagerSdl::~WindowManagerSdl()
		{
			/*for(auto *window : mWindows)
			{
				delete window;
			}*/
		}

		bool WindowManagerSdl::Install(AE::uint options, PluginOptions *pluginDesc)
		{
			if(!SDL_WasInit(SDL_INIT_VIDEO))
			{
				SDL_InitSubSystem(SDL_INIT_VIDEO);
			}

			mIsInstalled = true;

			return true;
		}

		bool WindowManagerSdl::Uninstall()
		{
			if(SDL_WasInit(SDL_INIT_VIDEO))
			{
				SDL_QuitSubSystem(SDL_INIT_VIDEO);
			}

			mIsInstalled = false;

			return true;
		}

		AE::OS::WindowPtr WindowManagerSdl::CreateWindow(AE::OS::WindowDesc &windowDesc)
		{
			return std::make_unique<AE::OS::WindowSdl>(mCurrentId++, windowDesc);
		}

		AE::OS::WindowPtr WindowManagerSdl::CreateWindow(AE::OS::WindowDesc &windowDesc, AE::Graphics::Device::Context *deviceContext)
		{
			AE::OS::WindowPtr window = CreateWindow(windowDesc);

			window->AttachDeviceContext(deviceContext);

			return window;
		}

		void WindowManagerSdl::DestroyWindow(AE::OS::Window *window)
		{
		}
	}
}