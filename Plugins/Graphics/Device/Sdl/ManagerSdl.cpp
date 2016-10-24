#include "ManagerSdl.h"

#include "Anima/Exception.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"

#include "DriverSdl.h"

#include <cassert>
#include <string.h>

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ManagerSdl::ManagerSdl()
			{
				mInstance = this;

				if(!SDL_WasInit(SDL_INIT_VIDEO))
				{
					SDL_InitSubSystem(SDL_INIT_VIDEO);
				}

				mNumOfDrivers = SDL_GetNumVideoDrivers();
				for(AE::uint i = 0; i < mNumOfDrivers; i++)
				{
					mDeviceDrivers[i] = new AE::Graphics::Device::DriverSdl(i);
				}
			}

			ManagerSdl::~ManagerSdl()
			{
				mInstance = 0;

				for(AE::uint i = 0; i < mNumOfDrivers; i++)
				{ 
					delete mDeviceDrivers[i];
				}

				if(SDL_WasInit(SDL_INIT_VIDEO))
				{
					SDL_QuitSubSystem(SDL_INIT_VIDEO);
				}
			}

			bool ManagerSdl::Install(AE::uint options)
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

			bool ManagerSdl::Uninstall()
			{
				//delete mPixelBufferFactory;

				return true;
			}

			AE::Graphics::Device::Driver* ManagerSdl::acquireDeviceDriver(AE::uint graphicsDeviceNumber, AE::Graphics::Device::DriverType driverType)
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
