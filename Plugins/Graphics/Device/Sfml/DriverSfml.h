#ifndef __AE_GRAPHICS_DEVICE_DRIVER_SDL__
#define __AE_GRAPHICS_DEVICE_DRIVER_SDL__

#include "Anima/Graphics/Device/ContextDesc.h"
#include "Anima/Graphics/Device/Driver.h"
#include "Anima/Graphics/Enums.h"

#include "PipelineSfml.h"

#include <string>
#include <vector>

#include "SFML/Graphics.hpp"

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

			class DriverSfml : public AE::Graphics::Device::Driver
			{
			public:
				DriverSfml(AE::uint deviceId, AE::Graphics::Device::DriverType driverType = AE::Graphics::Device::DT_NONE) 
					: Driver(deviceId, driverType), mBufferIdCount(-1), mDeviceId(deviceId), mType(driverType), mRenderablePixelBufferId(0) 
				{
					mDriverName = "Unknown";
					mPipeline = new PipelineSfml();
				}

				~DriverSfml() {}

				AE::Graphics::Device::Context*				createDeviceContext(AE::OS::Window *window, const std::string &contextName = "");
				AE::Graphics::Device::Context*				createDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName = "");
				AE::Graphics::Device::IndexBuffer*			createEmptyIndexBuffer() { return nullptr; }
				AE::Graphics::Device::VertexBuffer*			createEmptyVertexBuffer(AE::uint vertexDeclaration, AE::Graphics::BufferUsage bufferUsage, AE::Graphics::BufferChangeFrequency bufferChangeFrequency) { return nullptr; }
				void										destroyVertexBuffer(AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				AE::Graphics::Device::Context*				getDeviceContext(AE::uint index) { return mDeviceContexts[index]; }
				AE::uint									getDeviceId() { return mDeviceId; }
				AE::Graphics::Device::DriverType			getType() { return mType; }

			protected:
				AE::int32									mBufferIdCount;
				std::vector<AE::Graphics::Device::Context *> 
															mDeviceContexts;
				AE::uint									mDeviceId;
				AE::int8									*mDriverName;
				AE::uint									mRenderablePixelBufferId;
				AE::Graphics::Device::DriverType			mType;
			};
		}
	}
}

#endif