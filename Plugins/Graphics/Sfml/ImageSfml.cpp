#include "ImageSfml.h"

namespace AE
{
	namespace Graphics
	{
		ImageSfml::ImageSfml(const std::string &filename, AE::Graphics::ImageType imageType)
		{
			mSfmlImage.loadFromFile(filename);
		}

		ImageSfml::ImageSfml(AE::Math::Vector2 &dimensions)
		{
			mSfmlImage.create(static_cast<int>(dimensions.x), static_cast<int>(dimensions.y));
		}

		ImageSfml::~ImageSfml()
		{

		}
	}
}