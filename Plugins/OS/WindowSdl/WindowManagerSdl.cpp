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
			for(auto *window : mWindows)
			{
				delete window;
			}
		}

		bool WindowManagerSdl::Install(AE::uint options)
		{
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
			mIsInstalled = false;

			return true;
		}

		AE::OS::Window* WindowManagerSdl::createWindow(AE::OS::WindowDesc &windowDesc)
		{
			AE::OS::Window *window = new AE::OS::WindowSdl(mCurrentId++, windowDesc);
			mWindows.push_back(window);

			/*AE::Graphics::Device::ContextDesc contextDesc;
			contextDesc.dimensions = window->getDimensions();
			contextDesc.fullScreen = windowDesc.fullScreen;
			contextDesc.parentWindow = window;
			contextDesc.setColorFormat(windowDesc.getColorFormat());*/

			return window;
		}

		AE::OS::Window* WindowManagerSdl::createWindow(AE::OS::WindowDesc &windowDesc, AE::Graphics::Device::Context *deviceContext)
		{
			AE::OS::Window *window = createWindow(windowDesc);

			window->attachDeviceContext(deviceContext);

			return window;
		}

		void WindowManagerSdl::destroyWindow(AE::OS::Window *window)
		{
			for(auto *w : mWindows)
			{
				if(w == window)
				{
					delete window;
				}
			}
		}
	}
}