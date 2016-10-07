#include "Anima/OS/Window.h"

#include "Anima/Graphics/Device/Context.h"

#include <cassert>

namespace AE
{
	namespace OS
	{
		Window::Window(AE::uint id, AE::OS::WindowDesc &windowDesc)
				: mId(id), mIsExternal(false), mIsFullScreen(false)
		{
			mDimensions = windowDesc.dimensions;
			mPosition = windowDesc.position;
			mColorFormat = const_cast<AE::OS::WindowDesc &>(windowDesc).getColorFormat();
		}

		void Window::attachDeviceContext(AE::Graphics::Device::Context *deviceContext)
		{
			mDeviceContext = deviceContext;
			mDeviceContext->setParentWindow(this);
		}
	}
}
