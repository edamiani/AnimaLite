#ifndef __AE_GRAPHICS_DEVICE_DRIVER__
#define __AE_GRAPHICS_DEVICE_DRIVER__

#include "Anima/Graphics/Device/ContextDesc.h"
#include "Anima/Graphics/Device/Texture.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/OS/Window.h"

#include <string>
#include <vector>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Context;
			class IndexBuffer;
			class Pipeline;
			class PixelBuffer;
			class VertexBuffer;

			class Driver
			{
			public:
				Driver(AE::uint deviceId, AE::Graphics::Device::DriverType driverType)
					: mBufferIdCount(-1), mDeviceId(deviceId), mType(driverType), mRenderablePixelBufferId(0) {}
				~Driver() {}

				virtual AE::Graphics::Device::Context*		CreateDeviceContext(AE::OS::WindowPtr &window, const std::string &contextName = "") = 0;
				virtual AE::Graphics::Device::Context*		CreateDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName = "") = 0;
				virtual AE::Graphics::Device::IndexBuffer*	CreateEmptyIndexBuffer() = 0;
				virtual AE::Graphics::Device::VertexBuffer*	CreateEmptyVertexBuffer(AE::uint vertexDeclaration, AE::Graphics::BufferUsage bufferUsage, AE::Graphics::BufferChangeFrequency bufferChangeFrequency) = 0;
				virtual TexturePtr							CreateTexture(const AE::Math::Vector2 &dimensions, void *data = nullptr, bool hasMipMap = false) = 0;
				virtual void								DestroyVertexBuffer(AE::Graphics::Device::VertexBuffer *vertexBuffer) = 0;
				AE::Graphics::Device::Context*				GetDeviceContext(AE::uint index) { return mDeviceContexts[index]; }
				AE::uint									GetDeviceId() { return mDeviceId; }
				AE::Graphics::Device::Pipeline*				GetPipeline() { return mPipeline; }
				AE::Graphics::Device::DriverType			GetType() { return mType; }

			protected:
				AE::int32									mBufferIdCount;
				std::vector<AE::Graphics::Device::Context *> 
															mDeviceContexts;
				AE::uint									mDeviceId;
				Pipeline									*mPipeline;
				AE::uint									mRenderablePixelBufferId;
				AE::Graphics::Device::DriverType			mType;
			};
		}
	}
}

#endif