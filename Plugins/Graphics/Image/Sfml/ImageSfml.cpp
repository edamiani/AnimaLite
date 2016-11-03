#include "ImageSfml.h"

namespace AE
{
	namespace Graphics
	{
		ImageSfml::ImageSfml(const std::string &filename)
			: Image(filename)
		{
			mSfmlImage.loadFromFile(filename);
			mData = static_cast<void *>(const_cast<sf::Uint8 *>(mSfmlImage.getPixelsPtr()));
			mDimensions = AE::Math::Vector2(mSfmlImage.getSize().x, mSfmlImage.getSize().y);
		}

		ImageSfml::ImageSfml(const AE::Math::Vector2 &dimensions)
			: Image(dimensions)
		{
			mSfmlImage.create(static_cast<int>(dimensions.x()), static_cast<int>(dimensions.y()));
		}

		ImageSfml::~ImageSfml()
		{

		}
	}
}