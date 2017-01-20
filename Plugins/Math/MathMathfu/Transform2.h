#ifndef __ANIMA_GRAPHICS_TRANSFORM2_SFML__
#define __ANIMA_GRAPHICS_TRANSFORM2_SFML__

#include "Anima/Types.h"
#include "Anima/Math/Matrix3.h"
#include "Anima/Math/Vector2.h"

#include "SFML/Graphics.hpp"

namespace AE
{
	namespace Graphics
	{
		class Transform2
		{
		public:
			Transform2(const AE::Math::Vector2 &dimensions) { }
			virtual ~Transform2() { }

			virtual Transform2& rotate(AE::Real angle) = 0;
			virtual Transform2& scale(AE::Math::Vector2 &scale) = 0;
			virtual Transform2& translate(AE::Math::Vector2 &translate) = 0;

		protected:
			AE::Math::Matrix3 mTransform;
		};
	}
}

#endif