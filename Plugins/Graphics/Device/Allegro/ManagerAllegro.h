#ifndef __AE_GRAPHICS_DEVICE_MANAGER_ALLEGRO__
#define __AE_GRAPHICS_DEVICE_MANAGER_ALLEGRO__

#include "Anima/Graphics/Device/Manager.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/Driver.h"
#include "Anima/Graphics/Device/Context.h"
//#include "AnimaGraphicsDrawingContextDesc.h"

#include "Dependencies/allegro/include/allegro5/allegro.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Driver;

			class ManagerAllegro : public AE::Graphics::Device::Manager
			{
			public:
				ManagerAllegro();
				virtual ~ManagerAllegro();

				bool Install(AE::uint options);
				bool Uninstall();

				AE::Graphics::Device::Driver* AcquireDeviceDriver(AE::uint graphicsDeviceNumber, AE::Graphics::Device::DriverType driverType);
				//AE::Graphics::Device::Context* createDeviceContext(AE::Graphics::Device::Driver *devicedriver, const AE::Math::Point2 &dimensions, AE::Graphics::Device::ContextOption deviceContextOptions, const std::string &contextName = "");

			protected:
			};
		}
	}
}

#endif