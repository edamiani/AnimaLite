#ifndef __AE_GRAPHICS_DEVICE_CONTEXT__
#define __AE_GRAPHICS_DEVICE_CONTEXT__

#include "Anima/Types.h"
#include "Anima/Graphics/Surface.h"
#include "Anima/Graphics/Device/Texture.h"
#include "Anima/Math/Transform2.h"

#include <vector>

namespace AE
{
	namespace OS
	{
		class Window;
	}

	namespace Graphics
	{
		class Viewport;

		namespace Device
		{
			class Driver;
			class FrameBuffer;
			class IndexBuffer;
			class Pipeline;
			class VertexBuffer;

			class AE_DECLSPEC Context
			{
			public:
				Context(AE::Graphics::Device::Driver *deviceDriver) : mDeviceDriver(deviceDriver) { }
				virtual ~Context() { }

				virtual bool						BeginRendering() = 0;
				virtual bool						BeginRendering(const AE::Graphics::Color &clearColor) = 0;
				virtual void						Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) = 0;
				virtual void						DrawTexture(AE::Graphics::Device::TexturePtr const &texture, AE::Math::Transform2 &transform) = 0;
				virtual void						Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) = 0;
				virtual void						DrawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color) = 0;
				virtual void						DrawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Color &color) = 0;
				virtual void						DrawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Device::Texture &texture) = 0;
				virtual void						EndRendering() = 0;
				AE::Graphics::Device::Driver*		GetDeviceDriver() { return mDeviceDriver; }
				AE::Graphics::Device::FrameBuffer*	GetFrameBuffer() { return mFrameBuffer; }
				AE::OS::Window*						GetParentWindow() { return mParentWindow; }
				AE::Graphics::Device::Pipeline*		GetPipeline() { return mPipeline; }
				bool								IsFullScreen() { return mIsFullScreen; }
				virtual void						Render() = 0;
				virtual void						SetFullScreen(bool IsFullScreen) = 0;
				virtual void						SetParentWindow(AE::OS::Window *parentWindow) { mParentWindow = parentWindow; }
				void								SetViewport(AE::Graphics::Viewport *viewport) { mViewport = viewport; }


			protected:
				AE::Graphics::Device::Driver		*mDeviceDriver;
				AE::Graphics::Device::FrameBuffer	*mFrameBuffer;
				bool								mIsFullScreen;
				AE::Graphics::Viewport				*mViewport;
				AE::OS::Window						*mParentWindow;
				AE::Graphics::Device::Pipeline		*mPipeline;
			};
		}
	}
}

#endif
