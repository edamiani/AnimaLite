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

		AE::OS::WindowPtr WindowManagerSdl::createWindow(AE::OS::WindowDesc &windowDesc)
		{
			return std::make_unique<AE::OS::WindowSdl>(mCurrentId++, windowDesc);
		}

		AE::OS::WindowPtr WindowManagerSdl::createWindow(AE::OS::WindowDesc &windowDesc, AE::Graphics::Device::Context *deviceContext)
		{
			AE::OS::WindowPtr window = createWindow(windowDesc);

			window->attachDeviceContext(deviceContext);

			return window;
		}

		void WindowManagerSdl::destroyWindow(AE::OS::Window *window)
		{
		}
	}
}