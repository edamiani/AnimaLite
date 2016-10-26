#include "DriverSfml.h"

#include "Anima/OS/Window.h"

#include "ContextSfml.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			AE::Graphics::Device::Context* DriverSfml::createDeviceContext(AE::OS::Window *window, const std::string &contextName)
			{
				AE::Graphics::Device::ContextDesc contextDesc;
				contextDesc.parentWindow = window;
				contextDesc.dimensions = window->getDimensions();

				auto *deviceContext = new AE::Graphics::Device::ContextSfml(contextDesc, this);

				return deviceContext;
			}

			AE::Graphics::Device::Context* DriverSfml::createDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName)
			{
				return nullptr;
			}
		}
	}
}