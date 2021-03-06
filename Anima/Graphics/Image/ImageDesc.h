#ifndef __ANIMA_GRAPHICS_IMAGE_DESC__
#define __ANIMA_GRAPHICS_IMAGE_DESC__

#include "Anima/Graphics/ColorBufferDesc.h"
#include "Anima/Graphics/Enums.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		class ColorBuffer;

		struct ImageDesc
		{
			AE::Graphics::ColorBufferDesc	colorBufferDesc;
			std::string						file;
			AE::Graphics::ImageFormat		imageType;

			ImageDesc() :
				imageType(AE::Graphics::IF_UNKNOWN) {}
		};
	}
}

#endif