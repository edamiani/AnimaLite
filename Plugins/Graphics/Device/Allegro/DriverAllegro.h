#ifndef __AE_GRAPHICS_DEVICE_DRIVER_ALLEGRO__
#define __AE_GRAPHICS_DEVICE_DRIVER_ALLEGRO__

#include "Anima/Graphics/Device/Driver.h"

#include "Dependencies/allegro/include/allegro5/allegro.h"

namespace AE
{
	namespace OS
	{
		class Window;
	}

	namespace Graphics
	{
		namespace Device
		{
			class DriverAllegro : public AE::Graphics::Device::Driver
			{
			public:
				DriverAllegro(AE::uint deviceId, AE::Graphics::Device::DriverType);
				~DriverAllegro();

				AE::Graphics::Device::Context*		CreateDeviceContext(AE::OS::Window *window, const std::string &contextName = "");
				AE::Graphics::Device::Context*		CreateDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName = "");
				AE::Graphics::Device::IndexBuffer*	CreateEmptyIndexBuffer();
				AE::Graphics::Device::VertexBuffer*	CreateEmptyVertexBuffer(AE::uint vertexDeclaration, AE::Graphics::BufferUsage bufferUsage, AE::Graphics::BufferChangeFrequency bufferChangeFrequency);
				void								DestroyVertexBuffer(AE::Graphics::Device::VertexBuffer *vertexBuffer);

			protected:
				ALLEGRO_MONITOR_INFO mMonitorInfo;
			};
		}
	}
}

#endif