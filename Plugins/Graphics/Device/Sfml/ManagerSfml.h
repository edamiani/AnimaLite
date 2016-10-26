#ifndef __AE_GRAPHICS_DEVICE_MANAGER_SDL__
#define __AE_GRAPHICS_DEVICE_MANAGER_SDL__

#include "Anima/Graphics/Device/Manager.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/Driver.h"
#include "Anima/Graphics/Device/Context.h"

#include <vector>

#include "SFML/Graphics.hpp"

namespace AE
{
	namespace Graphics
	{
		class SurfaceFactory;

		namespace Device
		{
			class Driver;

			class ManagerSfml : public AE::Graphics::Device::Manager
			{
			public:
				ManagerSfml();
				virtual ~ManagerSfml();

				bool			Install(AE::uint options);
				bool			Uninstall();

				AE::Graphics::Device::Driver*
								acquireDeviceDriver(AE::uint graphicsDeviceNumber, AE::Graphics::Device::DriverType driverType = AE::Graphics::Device::DT_NONE);

			private:
				std::vector<char *>		mDrivers;
				AE::uint				mNumOfDrivers;
			};
		}
	}
}

#endif
