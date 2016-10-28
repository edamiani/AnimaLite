#ifndef __ANIMA_GRAPHICS_MANAGER__
#define __ANIMA_GRAPHICS_MANAGER__

#include "Anima/Math/Vector2.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		class Image;

		class Manager
		{
		protected:

		public:
			Manager() {}
			virtual ~Manager() {}

			virtual Image* createImage(AE::Math::Vector2 &dimensions) = 0;
			virtual Image* createImage(const std::string &filename) = 0;
		};
	}
}

#endif