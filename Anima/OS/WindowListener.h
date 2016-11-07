#ifndef __AE_OS_WINDOW_LISTENER__
#define __AE_OS_WINDOW_LISTENER__

#include "Anima/Math/Point2.h"
//#include "Anima/OS/Window.h"

#include <memory>

namespace AE
{
	namespace OS
	{
		class Window;

		class WindowListener
		{
		public:
			WindowListener() {}
			virtual ~WindowListener() {}

			// Window events
			virtual void OnClose(AE::OS::Window *window) {}
			virtual void OnDeviceFound(AE::OS::Window *window) {}
			virtual void OnDeviceLost(AE::OS::Window *window) {}
			virtual void OnGainFocus(AE::OS::Window *window) {}
			virtual void OnLostFocus(AE::OS::Window *window) {}
			virtual void OnOrientationChanged(AE::OS::Window *window) {}
			virtual void OnResize(AE::OS::Window *window, const AE::Math::Point2<AE::int32> &topLeft, const AE::Math::Point2<AE::uint> &newDimensions) {}
			virtual void OnRestore(AE::OS::Window *window, const AE::Math::Point2<AE::int32> &topLeft, const AE::Math::Point2<AE::uint> &dimensions) {}
		};

		typedef std::unique_ptr<WindowListener> WindowListenerPtr;
	}
}

#endif