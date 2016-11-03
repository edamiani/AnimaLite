#include "ImageManagerSfml.h"

#include "Plugins/Graphics/Image/Sfml/ImageSfml.h"

namespace AE
{
	namespace Graphics
	{
		std::unique_ptr<AE::Graphics::Image> ImageManagerSfml::createImage(const std::string &filename)
		{
			return std::make_unique<AE::Graphics::ImageSfml>(filename);
		}

		bool ImageManagerSfml::Install(AE::uint options)
		{
			return true;
		}

		bool ImageManagerSfml::Uninstall()
		{
			return true;
		}
	}
}