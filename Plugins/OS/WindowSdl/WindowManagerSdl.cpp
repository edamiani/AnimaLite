#include "WindowManagerSdl.h"

#include "EventQueueSdl.h"
#include "WindowSdl.h"

#include <cassert>

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
			std::list<AE::OS::Window *>::iterator i;
			for(i = mWindows.begin(); i != mWindows.end(); i++)
			{
				delete *i;
			}
		}

		bool WindowManagerSdl::Install(AE::uint options)
		{
			SDL_InitSubSystem(SDL_INIT_VIDEO);

			if(mParent != 0)
			{
				mIsInstalled = true;

				return true;
			}
			else
				return false;
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

		AE::OS::Window* WindowManagerSdl::createWindow(const std::string &windowTitle, AE::OS::WindowDesc &windowDesc)
		{
			AE::OS::Window *window = new AE::OS::WindowSdl(mCurrentId++, windowTitle, windowDesc);
			mWindows.push_back(window);

			/*AE::Graphics::Device::ContextDesc contextDesc;
			contextDesc.dimensions = window->getDimensions();
			contextDesc.fullScreen = windowDesc.fullScreen;
			contextDesc.parentWindow = window;
			contextDesc.setColorFormat(windowDesc.getColorFormat());*/

			return window;
		}

		AE::OS::Window* WindowManagerSdl::createWindow(const std::string &windowTitle, AE::OS::WindowDesc &windowDesc, AE::Graphics::Device::Context *deviceContext)
		{
			AE::OS::Window *window = createWindow(windowTitle, windowDesc);

			window->attachDeviceContext(deviceContext);

			return window;
		}

		void WindowManagerSdl::destroyWindow(AE::OS::Window *window)
		{
			std::list<AE::OS::Window *>::iterator i;
			for(i = mWindows.begin(); i != mWindows.end(); i++)
			{
				if(*i == window)
				{
					delete window;
				}
			}
		}
	}
}