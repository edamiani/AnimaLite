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

				AE::Graphics::Device::Context*		createDeviceContext(AE::OS::Window *window, const std::string &contextName = "");
				AE::Graphics::Device::Context*		createDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName = "");
				AE::Graphics::Device::IndexBuffer*	createEmptyIndexBuffer();
				AE::Graphics::Device::VertexBuffer*	createEmptyVertexBuffer(AE::uint vertexDeclaration, AE::Graphics::BufferUsage bufferUsage, AE::Graphics::BufferChangeFrequency bufferChangeFrequency);
				void								destroyVertexBuffer(AE::Graphics::Device::VertexBuffer *vertexBuffer);

			protected:
				ALLEGRO_MONITOR_INFO mMonitorInfo;
			};
		}
	}
}

#endif