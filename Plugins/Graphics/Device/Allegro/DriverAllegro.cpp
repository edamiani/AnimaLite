#include "Plugins/Graphics/Device/Allegro/DriverAllegro.h"

#include "Anima/OS/Window.h"
#include "Plugins/Graphics/Device/Allegro/ContextAllegro.h"


namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			DriverAllegro::DriverAllegro(AE::uint deviceId, AE::Graphics::Device::DriverType driverType) 
				: Driver(deviceId, driverType) 
			{
				al_get_monitor_info(mDeviceId, &mMonitorInfo);
			}

			DriverAllegro::~DriverAllegro() 
			{
			}

			AE::Graphics::Device::Context* DriverAllegro::CreateDeviceContext(AE::OS::Window *window, const std::string &contextName)
			{
				AE::Math::Vector2 dimensions = window->getDimensions();
				AE::Graphics::Device::Context *deviceContext = new AE::Graphics::Device::ContextAllegro(this, window);

				window->attachDeviceContext(deviceContext);

				return deviceContext;
			}

			AE::Graphics::Device::Context* DriverAllegro::CreateDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName)
			{
				return nullptr;
			}

			AE::Graphics::Device::IndexBuffer* DriverAllegro::CreateEmptyIndexBuffer()
			{
				return nullptr;
			}

			AE::Graphics::Device::VertexBuffer* DriverAllegro::CreateEmptyVertexBuffer(AE::uint vertexDeclaration, AE::Graphics::BufferUsage bufferUsage, AE::Graphics::BufferChangeFrequency bufferChangeFrequency)
			{
				return nullptr;
			}

			void DriverAllegro::DestroyVertexBuffer(AE::Graphics::Device::VertexBuffer *vertexBuffer)
			{

			}
		}
	}
}