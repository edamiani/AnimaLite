#ifndef __AE_ANIMATION_RANGE_CHOREOGRAPH__
#define __AE_ANIMATION_RANGE_CHOREOGRAPH__

#include "Anima/Animation/Range.h"

namespace AE
{
	namespace Animation
	{
		template <typename T>
		class RangeChoreograph : public AE::Animation::Range<T>
		{
		public:
			RangeChoreograph(const T& from, const T& to) : Range<T>(from, to) { }
			~RangeChoreograph() { }

		protected:

		};
	}
}

#endif
