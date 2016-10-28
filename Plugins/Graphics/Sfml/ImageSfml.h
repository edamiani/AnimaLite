#ifndef __ANIMA_GRAPHICS_IMAGE_SFML__
#define __ANIMA_GRAPHICS_IMAGE_SFML__

#include "Anima/Graphics/ColorBuffer.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Graphics/Image.h"
#include "Anima/Graphics/ImageDesc.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Math/Vector2.h"
#include "Anima/Types.h"

#include <string>

#include "SFML/Graphics.hpp"

namespace AE
{
	namespace Graphics
	{
		class ImageSfml : public Image
		{
		protected:
			sf::Image mSfmlImage;

		public:
			ImageSfml(const std::string &file);
			ImageSfml(AE::Math::Vector2 &dimensions);			
			~ImageSfml();
		};
	}
}

#endif