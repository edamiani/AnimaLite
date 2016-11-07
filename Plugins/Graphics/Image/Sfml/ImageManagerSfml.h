#ifndef __ANIMA_GRAPHICS_IMAGE_MANAGER_SFML__
#define __ANIMA_GRAPHICS_IMAGE_MANAGER_SFML__

#include "Anima/Graphics/Image/ImageManager.h"

#include "Sfml/Graphics.hpp"

#include <memory>

namespace AE
{
	namespace Graphics
	{
		class ImageManagerSfml : public AE::Graphics::ImageManager
		{
		public:
			ImageManagerSfml() {}
			virtual ~ImageManagerSfml() {}

			std::unique_ptr<AE::Graphics::Image> 
						CreateImage(const std::string &filename);
			bool		Install(AE::uint options);
			bool		Uninstall();
		};
	}
}

#endif
