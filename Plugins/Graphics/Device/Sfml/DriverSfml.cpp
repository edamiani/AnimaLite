#include "DriverSfml.h"

#include "Anima/OS/Window.h"

#include "Plugins/Graphics/Device/Sfml/ContextSfml.h"
#include "Plugins/Graphics/Device/Sfml/TextureSfml.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			AE::Graphics::Device::Context* DriverSfml::CreateDeviceContext(AE::OS::WindowPtr &window, const std::string &contextName)
			{
				AE::Graphics::Device::ContextDesc contextDesc;
				contextDesc.parentWindow = window.get();
				contextDesc.dimensions = window->GetDimensions();

				auto *deviceContext = new AE::Graphics::Device::ContextSfml(contextDesc, this);

				return deviceContext;
			}

			AE::Graphics::Device::Context* DriverSfml::CreateDeviceContext(AE::Graphics::Device::ContextDesc &contextDesc, const std::string &contextName)
			{
				return nullptr;
			}

			AE::Graphics::Device::TexturePtr DriverSfml::CreateTexture(const AE::Math::Vector2 &dimensions, void *data, bool hasMipMap)
			{
				return std::make_unique<AE::Graphics::Device::TextureSfml>(dimensions, data, hasMipMap);
			}
		}
	}
}