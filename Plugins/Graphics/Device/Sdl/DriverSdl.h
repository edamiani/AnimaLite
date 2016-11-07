#ifndef __AE_GRAPHICS_DEVICE_DRIVER_SDL__
#define __AE_GRAPHICS_DEVICE_DRIVER_SDL__

#include "Anima/Graphics/Device/ContextDesc.h"
#include "Anima/Graphics/Device/Driver.h"
#include "Anima/Graphics/Enums.h"
//#include "Anima/Math/Vector2.h"

//#include <list>
#include <string>
#include <vector>

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

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

			class DriverSdl : public AE::Graphics::Device::Driver
			{
			public:
				DriverSdl(AE::uint deviceId, AE::Graphics::Device::DriverType driverType = AE::Graphics::Device::DT_NONE) 
					: Driver(deviceId, driverType), mBufferIdCount(-1), mDeviceId(deviceId), mType(driverType), mRenderablePixelBufferId(0) 
				{
					mDriverName = const_cast<char *>(SDL_GetVideoDriver(deviceId));
				}

				~DriverSdl() {}

				AE::Graphics::Device::Context*				CreateDeviceContext(AE::OS::Window *window, const std::string &contextName = "");
				AE::Graphics::Device::Context*				CreateDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName = "");
				AE::Graphics::Device::IndexBuffer*			CreateEmptyIndexBuffer() { return nullptr; }
				AE::Graphics::Device::VertexBuffer*			CreateEmptyVertexBuffer(AE::uint vertexDeclaration, AE::Graphics::BufferUsage bufferUsage, AE::Graphics::BufferChangeFrequency bufferChangeFrequency) { return nullptr; }
				void										DestroyVertexBuffer(AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				AE::Graphics::Device::Context*				GetDeviceContext(AE::uint index) { return mDeviceContexts[index]; }
				AE::uint									GetDeviceId() { return mDeviceId; }
				AE::Graphics::Device::DriverType			GetType() { return mType; }

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