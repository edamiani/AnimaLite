#include "TextureSfml.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			TextureSfml::TextureSfml(const AE::Graphics::Image &image)
			{
				void *data = image.getData();
				AE::Math::Vector2 dimensions = image.getDimensions();
				
				mSfmlTexture.create(dimensions.x(), dimensions.y());
				mSfmlTexture.update(static_cast<sf::Uint8 *>(data));
			}

			TextureSfml::~TextureSfml()
			{

			}
		}
	}
}