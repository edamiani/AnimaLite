#ifndef __AE_GRAPHICS_DEVICE_MANAGER__
#define __AE_GRAPHICS_DEVICE_MANAGER__

#include "Anima/Graphics/Enums.h"
#include "Anima/Math/Point2.h"
#include "Anima/Plugin.h"

#include <map>

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
			class Context;
			class Driver;
			class PixelBufferFactory;

			class Manager : public AE::Plugin
			{
			public:
				Manager();
				virtual ~Manager();

				static AE::Graphics::Device::Manager*		GetInstance() { assert(mInstance != 0); return mInstance; }

				virtual AE::Graphics::Device::Driver*		AcquireDeviceDriver(AE::uint graphicsDeviceNumber, AE::Graphics::Device::DriverType driverType) = 0;
				AE::Graphics::Device::Driver*				GetDeviceDriver(AE::uint graphicsDeviceNumber) { return mDeviceDrivers[graphicsDeviceNumber]; }
				AE::Graphics::Device::PixelBufferFactory*	GetPixelBufferFactory() { return mPixelBufferFactory; }
				
				/***** Inherited from AE::Plugin
				virtual bool								Install(AE::uint options) = 0;
				virtual bool								Uninstall() = 0;
				*****/

			protected:
				static AE::Graphics::Device::Manager		*mInstance;

				std::map<AE::uint, AE::Graphics::Device::Driver *> 
															mDeviceDrivers;
				AE::Graphics::Device::PixelBufferFactory	*mPixelBufferFactory;
			};
		}
	}
}

#endif
