#include "TextureSfml.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			TextureSfml::TextureSfml(const AE::Math::Vector2 &dimensions, void *data, bool hasMipMap)
			{
				mSfmlTexture.create(dimensions.x(), dimensions.y());

				if(data != nullptr)
				{
					mSfmlTexture.update(static_cast<sf::Uint8 *>(data));
				}

				if(hasMipMap)
				{
					mSfmlTexture.generateMipmap();
				}
			}

			TextureSfml::TextureSfml(const AE::Graphics::Image &image)
			{
				void *data = image.GetData();
				AE::Math::Vector2 dimensions = image.GetDimensions();
				
				mSfmlTexture.create(dimensions.x(), dimensions.y());
				mSfmlTexture.update(static_cast<sf::Uint8 *>(data));
			}

			TextureSfml::~TextureSfml()
			{

			}

			AE::Math::Vector2 TextureSfml::GetDimensions()
			{
				sf::Vector2u size = mSfmlTexture.getSize();

				return AE::Math::Vector2(size.x, size.y);
			}
		}
	}
}