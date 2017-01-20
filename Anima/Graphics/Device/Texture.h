#ifndef __AE_GRAPHICS_DEVICE_TEXTURE__
#define __AE_GRAPHICS_DEVICE_TEXTURE__

#include "Anima/Graphics/Image/Image.h"

#include <memory>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Texture
			{
			public:
				Texture() {}
				virtual ~Texture() {}

				virtual AE::Math::Vector2 GetDimensions() = 0;
			};

			typedef std::unique_ptr<AE::Graphics::Device::Texture> TexturePtr;
		}
	}
}

#endif