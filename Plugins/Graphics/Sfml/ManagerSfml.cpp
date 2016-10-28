#include "ManagerSfml.h"

#include "ImageSfml.h"

namespace AE
{
	namespace Graphics
	{
		ManagerSfml::ManagerSfml() {}
		ManagerSfml::~ManagerSfml() {}

		Image* ManagerSfml::createImage(AE::Math::Vector2 &dimensions)
		{
			return new AE::Graphics::ImageSfml(dimensions);
		}

		Image* ManagerSfml::createImage(const std::string &filename)
		{
			return new AE::Graphics::ImageSfml(filename);
		}
	}
}