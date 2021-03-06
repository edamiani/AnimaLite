#ifndef __AE_OS_WINDOW_MANAGER__
#define __AE_OS_WINDOW_MANAGER__

#include "Anima/OS/EventQueue.h"
#include "Anima/Math/Point2.h"
#include "Anima/OS/Window.h"
#include "Anima/OS/WindowDesc.h"
#include "Anima/Platform.h"
#include "Anima/Plugin.h"
#include "Anima/Types.h"

#include <list>

#ifdef CreateWindow
#undef CreateWindow
#endif

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Driver;
		}
	}

	namespace OS
	{
		class WindowManager : public AE::Plugin
		{
		public:
			WindowManager() : AE::Plugin(AE::PT_OS_WINDOW_MANAGER) {}
			virtual ~WindowManager();

			virtual AE::OS::WindowPtr		CreateWindow(AE::OS::WindowDesc &windowDesc) = 0;
			virtual AE::OS::WindowPtr		CreateWindow(AE::OS::WindowDesc &windowDesc, AE::Graphics::Device::Context *deviceContext) = 0;
			virtual void 					DestroyWindow(AE::OS::Window *window) = 0;
		};
	}
}

#endif
