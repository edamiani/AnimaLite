#ifndef __ANIMA_GRAPHICS_IMAGE_SFML__
#define __ANIMA_GRAPHICS_IMAGE_SFML__

#include "Anima/Graphics/ColorBuffer.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Graphics/Image/Image.h"
#include "Anima/Graphics/Image/ImageDesc.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Math/Vector2.h"
#include "Anima/Types.h"

#include <string>

#include "SFML/Graphics.hpp"

namespace AE
{
	namespace Graphics
	{
		class ImageSfml : public AE::Graphics::Image
		{
		protected:
			sf::Image mSfmlImage;

		public:
			ImageSfml(const std::string &filename);
			ImageSfml(const AE::Math::Vector2 &dimensions);
			~ImageSfml();
		};
	}
}

#endif