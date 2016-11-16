#ifndef __AE_MATH_MATHFU_MATRIX3__
#define __AE_MATH_MATHFU_MATRIX3__

#include "Anima/Types.h"

#include "Dependencies/mathfu/include/mathfu/matrix.h"

namespace AE
{
	namespace Math
	{
		class Matrix3
		{
		public:
			Matrix3()
			{
				for(int i = 0; i < 9; i++) mMatrix[i] = 0;
			}

			Matrix3(AE::Real i0_j0, AE::Real i0_j1, AE::Real i0_j2,
				AE::Real i1_j0, AE::Real i1_j1, AE::Real i1_j2,
				AE::Real i2_j0, AE::Real i2_j1, AE::Real i2_j2)
			{
				mMatrix(0, 0) = i0_j0; mMatrix(0, 1) = i0_j1; mMatrix(0, 2) = i0_j2;
				mMatrix(1, 0) = i1_j0; mMatrix(1, 1) = i1_j1; mMatrix(1, 2) = i1_j2;
				mMatrix(2, 0) = i2_j0; mMatrix(2, 1) = i2_j1; mMatrix(2, 2) = i2_j2;
			}

			inline AE::Real operator () (AE::uint row, AE::uint column)
			{
				return mMatrix(row, column);
			}

			inline AE::Math::Matrix3 operator + (const AE::Math::Matrix3 &rhs)
			{
				mathfu::Matrix<AE::Real, 3, 3> newMatrix = mMatrix + rhs.mMatrix;

				return Matrix3(newMatrix(0, 0), newMatrix(0, 1), newMatrix(0, 2),
							   newMatrix(1, 0), newMatrix(1, 1), newMatrix(1, 2),
							   newMatrix(2, 0), newMatrix(2, 1), newMatrix(2, 2));
			}

			inline AE::Math::Matrix3 operator - (const AE::Math::Matrix3 &rhs)
			{
				mathfu::Matrix<AE::Real, 3, 3> newMatrix = mMatrix - rhs.mMatrix;

				return Matrix3(newMatrix(0, 0), newMatrix(0, 1), newMatrix(0, 2),
							   newMatrix(1, 0), newMatrix(1, 1), newMatrix(1, 2),
							   newMatrix(2, 0), newMatrix(2, 1), newMatrix(2, 2));
			}

			inline AE::Math::Matrix3 operator * (const AE::Math::Matrix3 &rhs)
			{
				mathfu::Matrix<AE::Real, 3, 3> newMatrix = mMatrix * rhs.mMatrix;

				return Matrix3(newMatrix(0, 0), newMatrix(0, 1), newMatrix(0, 2),
							   newMatrix(1, 0), newMatrix(1, 1), newMatrix(1, 2),
							   newMatrix(2, 0), newMatrix(2, 1), newMatrix(2, 2));
			}

			inline AE::Math::Matrix3 operator * (AE::Real rhs)
			{
				mathfu::Matrix<AE::Real, 3, 3> newMatrix = mMatrix * rhs;

				return Matrix3(newMatrix(0, 0), newMatrix(0, 1), newMatrix(0, 2),
							   newMatrix(1, 0), newMatrix(1, 1), newMatrix(1, 2),
							   newMatrix(2, 0), newMatrix(2, 1), newMatrix(2, 2));
			}

			inline AE::Math::Matrix3 operator = (const AE::Math::Matrix3 &rhs)
			{
				mMatrix = rhs.mMatrix;

				return *this;
			}

			inline AE::Math::Matrix3 Inverse()
			{
				mathfu::Matrix<AE::Real, 3, 3> newMatrix = mMatrix.Inverse();

				return Matrix3(newMatrix(0, 0), newMatrix(0, 1), newMatrix(0, 2),
							   newMatrix(1, 0), newMatrix(1, 1), newMatrix(1, 2),
							   newMatrix(2, 0), newMatrix(2, 1), newMatrix(2, 2));
			}
			
			friend Matrix3;

		private:
			mathfu::Matrix<AE::Real, 3, 3> mMatrix;
		};
	}
}

#endif
