#include "ManagerSfml.h"

#include "Anima/Exception.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"

#include "DriverSfml.h"

#include <cassert>
#include <string.h>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ManagerSfml::ManagerSfml()
			{
				mInstance = this;

				// SFML doesn't have multimonitor support
				mNumOfDrivers = 1;
				mDeviceDrivers[0] = new AE::Graphics::Device::DriverSfml(0);
			}

			ManagerSfml::~ManagerSfml()
			{
				mInstance = 0;

				delete mDeviceDrivers[0];
			}

			bool ManagerSfml::Install(AE::uint options)
			{
				if(mParent != 0)
				{
					//mPixelBufferFactory = new AE::Graphics::Device::PixelBufferFactoryGL15();

					mIsInstalled = true;

					return true;
				}
				else
					return false;
			}

			bool ManagerSfml::Uninstall()
			{
				//delete mPixelBufferFactory;

				return true;
			}

			AE::Graphics::Device::Driver* ManagerSfml::AcquireDeviceDriver(AE::uint graphicsDeviceNumber, AE::Graphics::Device::DriverType driverType)
			{
				// TODO implement adapter counting
				/*if(mDeviceDrivers.find(graphicsDeviceNumber) != mDeviceDrivers.end())
					throw AE::Exception(AE::ET_ALREADY_EXISTS, "AE::Graphics::ManagerAllegro::acquireDeviceDriver(): Device driver already acquired.");
				else if(graphicsDeviceNumber >= mAdapters.size())
					throw AE::Exception(AE::ET_NOT_FOUND, "AE::Graphics::ManagerAllegro::acquireDeviceDriver(): graphicsDeviceNumber exceeds the number of existing devices.");*/

				//mDeviceDrivers[graphicsDeviceNumber] = new AE::Graphics::Device::DriverSdl(graphicsDeviceNumber);

				return mDeviceDrivers[graphicsDeviceNumber];
			}
		}
	}
}
