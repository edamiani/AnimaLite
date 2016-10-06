#ifndef __AE_MATH_MATHFU_VECTOR3__
#define __AE_MATH_MATHFU_VECTOR3__

#include "Anima/Types.h"

#include "Dependencies/mathfu/include/mathfu/vector.h"

namespace AE
{
	namespace Math
	{
		class AE_DECLSPEC Vector3
		{
		public:
			Vector3()
			{
				mVector[0] = 0;
				mVector[1] = 0;
				mVector[2] = 0;
			}

			Vector3(AE::Real x, AE::Real y, AE::Real z) 
			{
				mVector[0] = x; 
				mVector[1] = y;
				mVector[2] = z;
			}

			inline AE::Real x() { return mVector[0]; }
			inline AE::Real y() { return mVector[1]; }
			inline AE::Real z() { return mVector[2]; }

			inline AE::Math::Vector3 operator + (const AE::Math::Vector3 &rhs)
			{
				return AE::Math::Vector3(mVector[0] + rhs.mVector[0], mVector[1] + rhs.mVector[1], mVector[2] + rhs.mVector[2]);
			}

			inline AE::Math::Vector3 operator - (const AE::Math::Vector3 &rhs)
			{
				return AE::Math::Vector3(mVector[0] - rhs.mVector[0], mVector[1] - rhs.mVector[1], mVector[2] - rhs.mVector[2]);
			}

			inline AE::Math::Vector3 operator * (const AE::Math::Vector3 &rhs)
			{
				return AE::Math::Vector3(mVector[0] * rhs.mVector[0], mVector[1] * rhs.mVector[1], mVector[2] * rhs.mVector[2]);
			}

			inline AE::Math::Vector3 operator = (const AE::Math::Vector3 &rhs)
			{
				mVector[0] = rhs.mVector[0];
				mVector[1] = rhs.mVector[1];
				mVector[2] = rhs.mVector[2];

				return *this;
			}

			inline bool operator != (const AE::Math::Vector3 &rhs)
			{
				return !(mVector[0] == rhs.mVector[0] && mVector[1] == rhs.mVector[1] && mVector[2] == rhs.mVector[2]);
			}

			AE::Math::Vector3 cross(const Vector3 &rhs)
			{
				mathfu::Vector<AE::Real, 3> result;
				result = mVector.CrossProduct(mVector, rhs.mVector);

				return AE::Math::Vector3(mVector[0], mVector[1], mVector[2]);
			}

			AE::Real dot(const Vector3 &rhs)
			{
				return static_cast<AE::Real>(mathfu::DotProductHelper(mVector, rhs.mVector));
			}

			AE::Real length()
			{
				return static_cast<AE::Real>(mVector.Length());
			}
			
			friend Vector3;

		private:
			mathfu::Vector<AE::Real, 3> mVector;
		};
	}
}

#endif
