#ifndef __AE_OS_WINDOW__
#define __AE_OS_WINDOW__

#include "Anima/OS/WindowListener.h"

#include "Anima/OS/WindowDesc.h"
#include "Anima/Graphics/Device/Context.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		class Manager;
	}

	namespace OS
	{
#if defined(AE_PLATFORM_WIN32)
		typedef HWND WindowHandle;

#elif defined(AE_PLATFORM_LINUX)
		typedef unsigned long WindowHandle;

#elif defined(AE_PLATFORM_OSX)
		typedef void* WindowHandle;

#endif
		class AE_DECLSPEC Window : public AE::OS::WindowListener
		{
		public:
			Window(AE::uint id, AE::OS::WindowDesc &windowDesc);
			Window(AE::uint externalWindowId) : mId(externalWindowId), mIsExternal(true) {}
			virtual ~Window() {}

			virtual void					attachDeviceContext(AE::Graphics::Device::Context *deviceContext);
			virtual void					close() = 0;
			AE::Graphics::ColorFormat		getColorFormat() { return mColorFormat; }
			AE::Graphics::Device::Context*	getDeviceContext() { return mDeviceContext; }
			AE::Math::Vector2				getDimensions() { return mDimensions; }
			virtual WindowHandle			getHandle() = 0;
			AE::uint8						getId() { return mId; }
			//AE::Input::Context*			getInputContext() { return mInputContext; }
			AE::Math::Vector2				getPosition() { return mPosition; }
			const std::string&				getTitle() { return mWindowTitle; }
			AE::int8*						getType() { return mType; }
			bool							isFullScreen() { assert(mDeviceContext); return mDeviceContext->isFullScreen(); }
			void							setFullScreen(bool isFullScreen) { assert(mDeviceContext); mDeviceContext->setFullScreen(isFullScreen); }
			virtual void					show() = 0;

			virtual void					onClose(AE::OS::Window *window) {}

		protected:
			AE::Graphics::ColorFormat		mColorFormat;
			AE::Graphics::Device::Context	*mDeviceContext;
			AE::Math::Vector2				mDimensions;
			AE::uint						mId;
			//AE::Input::Context			*mInputContext;
			bool							mIsExternal;
			bool							mIsFullScreen;
			AE::Math::Vector2				mPosition;
			AE::int8						mType[8];
			std::string						mWindowTitle;
		};
	}
}

#endif
