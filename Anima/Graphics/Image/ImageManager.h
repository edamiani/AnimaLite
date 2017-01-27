#ifndef __ANIMA_GRAPHICS_IMAGE_MANAGER__
#define __ANIMA_GRAPHICS_IMAGE_MANAGER__

#include "Anima/Plugin.h"

#include "Anima/Graphics/Image/Image.h"

#include <memory>

namespace AE
{
	namespace Graphics
	{
		typedef std::unique_ptr<AE::Graphics::Image> ImagePtr;

		class ImageManager : public AE::Plugin
		{
		public:
			ImageManager() : Plugin(AE::PT_IMAGE_MANAGER) {}
			virtual ~ImageManager() {}

			virtual ImagePtr	CreateImage(const std::string &filename) = 0;
			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool		Uninstall() = 0;
		};
	}
}

#endif