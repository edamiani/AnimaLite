#ifndef __ANIMA_GRAPHICS_MANAGER_SFML__
#define __ANIMA_GRAPHICS_MANAGER_SFML__

#include "Anima/Graphics/Manager.h"

namespace AE
{
	namespace Graphics
	{
		class Image;

		class ManagerSfml : public Manager
		{
		protected:

		public:
			ManagerSfml() {}
			virtual ~ManagerSfml() {}

			Image* createImage(AE::Math::Vector2 &dimensions);
			Image* createImage(const std::string &filename);
		};
	}
}

#endif