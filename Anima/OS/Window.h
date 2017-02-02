#ifndef __AE_OS_WINDOW__
#define __AE_OS_WINDOW__

#include "Anima/OS/WindowDesc.h"
#include "Anima/Graphics/Device/Context.h"

#include <memory>
#include <string>

namespace AE
{
	namespace OS
	{
#if defined(AE_PLATFORM_WIN32)
		typedef HWND WindowHandle;

#elif defined(AE_PLATFORM_LINUX)
		typedef unsigned long WindowHandle;

#elif defined(AE_PLATFORM_OSX)
		typedef void* WindowHandle;

#endif
		class Window
		{
		public:
			Window(AE::uint id, AE::OS::WindowDesc &windowDesc);
			Window(AE::uint externalWindowId) : mId(externalWindowId), mIsExternal(true) {}
			virtual ~Window() {}

			virtual void					AttachDeviceContext(AE::Graphics::Device::Context *deviceContext);
			virtual void					Close() = 0;
			AE::Graphics::ColorFormat		GetColorFormat() { return mColorFormat; }
			AE::Graphics::Device::Context*	GetDeviceContext() { return mDeviceContext; }
			AE::Math::Vector2				GetDimensions() { return mDimensions; }
			virtual WindowHandle			GetHandle() = 0;
			AE::uint8						GetId() { return mId; }
			AE::Math::Vector2				GetPosition() { return mPosition; }
			const std::string&				GetTitle() { return mWindowTitle; }
			AE::int8*						GetType() { return mType; }
			bool							IsFullScreen() { assert(mDeviceContext); return mDeviceContext->IsFullScreen(); }
			void							SetDimensions(const AE::Math::Vector2 &dimensions) { mDimensions = dimensions; }
			void							SetFullScreen(bool IsFullScreen) { assert(mDeviceContext); mDeviceContext->SetFullScreen(IsFullScreen); }
			void							SetPosition(const AE::Math::Vector2 &position) { mPosition = position; }
			void							SetTitle(const std::string &title) { mWindowTitle = title; }
			virtual void					Show() = 0;

		protected:
			AE::Graphics::ColorFormat		mColorFormat;
			AE::Graphics::Device::Context	*mDeviceContext;
			AE::Math::Vector2				mDimensions;
			AE::uint						mId;
			bool							mIsExternal;
			bool							mIsFullScreen;
			AE::Math::Vector2				mPosition;
			AE::int8						mType[8];
			std::string						mWindowTitle;
		};

		typedef std::unique_ptr<AE::OS::Window> WindowPtr;
	}
}

#endif
