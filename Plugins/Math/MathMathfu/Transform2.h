#ifndef __ANIMA_GRAPHICS_TRANSFORM2_SFML__
#define __ANIMA_GRAPHICS_TRANSFORM2_SFML__

#include "Anima/Types.h"
#include "Anima/Math/Matrix3.h"
#include "Anima/Math/Vector2.h"

#include "mathfu/matrix.h"

namespace AE
{
	namespace Math
	{
		class Transform2
		{
		public:
			Transform2(const AE::Math::Vector2 &dimensions) { }
			virtual ~Transform2() { }

			AE::Math::Matrix3 GetMatrix()
			{
				return AE::Math::Matrix3(
					mTransform[0], mTransform[1], mTransform[2],
					mTransform[3], mTransform[4], mTransform[5],
					mTransform[6], mTransform[7], mTransform[8]
				);
			}

			virtual Transform2& Rotate(AE::Real angle)
			{
				mTransform = mathfu::Matrix<AE::Real, 3, 3>::RotationZ(angle);

				return *this;
			}

			virtual Transform2& Scale(AE::Math::Vector2 &scale)
			{
				mTransform = mathfu::Matrix<AE::Real, 3, 3>::FromScaleVector(mathfu::Vector<float, 2>(scale.x(), scale.y()));

				return *this;
			}

			virtual Transform2& Translate(AE::Math::Vector2 &translate)
			{
				mTransform = mathfu::Matrix<AE::Real, 3, 3>::FromTranslationVector(mathfu::Vector<float, 2>(translate.x(), translate.y()));

				return *this;
			}

		protected:
			mathfu::Matrix<AE::Real, 3, 3> mTransform;
		};
	}
}

#endif