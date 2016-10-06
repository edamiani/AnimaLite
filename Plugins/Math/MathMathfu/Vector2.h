#ifndef __AE_MATH_MATHFU_VECTOR2__
#define __AE_MATH_MATHFU_VECTOR2__

#include "Anima/Types.h"

#include "Dependencies/mathfu/include/mathfu/vector.h"

namespace AE
{
	namespace Math
	{
		class AE_DECLSPEC Vector2
		{
		public:
			Vector2()
			{
				mVector[0] = 0;
				mVector[1] = 0;
			}

			Vector2(AE::Real x, AE::Real y) 
			{
				mVector[0] = x; 
				mVector[1] = y;
			}

			inline AE::Real x() { return mVector[0]; }
			inline AE::Real y() { return mVector[1]; }

			inline AE::Math::Vector2 operator + (const AE::Math::Vector2 &rhs)
			{
				return AE::Math::Vector2(mVector[0] + rhs.mVector[0], mVector[1] + rhs.mVector[1]);
			}

			inline AE::Math::Vector2 operator - (const AE::Math::Vector2 &rhs)
			{
				return AE::Math::Vector2(mVector[0] - rhs.mVector[0], mVector[1] - rhs.mVector[1]);
			}

			inline AE::Math::Vector2 operator * (const AE::Math::Vector2 &rhs)
			{
				return AE::Math::Vector2(mVector[0] * rhs.mVector[0], mVector[1] * rhs.mVector[1]);
			}

			inline AE::Math::Vector2 operator = (const AE::Math::Vector2 &rhs)
			{
				mVector[0] = rhs.mVector[0];
				mVector[1] = rhs.mVector[1];

				return *this;
			}

			inline bool operator != (const AE::Math::Vector2 &rhs)
			{
				return !(mVector[0] == rhs.mVector[0] && mVector[1] == rhs.mVector[1]);
			}

			AE::Real dot(const Vector2 &rhs)
			{
				return static_cast<AE::Real>(mathfu::DotProductHelper(mVector, rhs.mVector));
			}

			AE::Real length()
			{
				return static_cast<AE::Real>(mVector.Length());
			}
			
			friend Vector2;

		private:
			mathfu::Vector<AE::Real, 2> mVector;

			/*static const Vector2 Vector2::ZERO;
			static const Vector2 Vector2::UNIT_X;
			static const Vector2 Vector2::UNIT_Y;
			static const Vector2 Vector2::NEGATIVE_UNIT_X;
			static const Vector2 Vector2::NEGATIVE_UNIT_Y;*/
		};

		/*const Vector2 Vector2::ZERO(0, 0);
		const Vector2 Vector2::UNIT_X(1, 0);
		const Vector2 Vector2::UNIT_Y(0, 1);
		const Vector2 Vector2::NEGATIVE_UNIT_X(-1, 0);
		const Vector2 Vector2::NEGATIVE_UNIT_Y(0, -1);*/
	}
}

#endif
