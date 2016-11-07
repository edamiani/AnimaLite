#include "DriverSdl.h"

#include "Anima/OS/Window.h"

#include "ContextSdl.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			AE::Graphics::Device::Context* DriverSdl::CreateDeviceContext(AE::OS::Window *window, const std::string &contextName)
			{
				AE::Graphics::Device::ContextDesc contextDesc;
				contextDesc.parentWindow = window;
				contextDesc.dimensions = window->GetDimensions();

				auto *deviceContext = new AE::Graphics::Device::ContextSdl(contextDesc, this);

				return deviceContext;
			}

			AE::Graphics::Device::Context* DriverSdl::CreateDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName)
			{
				return nullptr;
			}
		}
	}
}