#ifndef __AE_ANIMATION_CHOREOGRAPH__
#define __AE_ANIMATION_CHOREOGRAPH__

#include "Anima/Types.h"

#include "Plugins/Animation/Choreograph/RangeChoreograph.h"

#include "choreograph/Choreograph.h"

namespace AE
{
	namespace Animation
	{
		template <typename T>
		class AnimationChoreograph
		{
		public:
			AnimationChoreograph(const AE::Animation::Range<T> &range, AE::Real duration)
			{ 
				mOutput = new choreograph::Output<T>(range.GetFrom());
				mMotionOptions = mTimeline.apply(mOutput);
				mMotionOptions.then<choreograph::RampTo>(range.GetTo(), duration);
			}

			~AnimationChoreograph() { }

		protected:
			choreograph::MotionOptions<t>  mMotionOptions;
			choreograph::Output<T> *mOutput;
			choreograph::Timeline mTimeline;
		};
	}
}

#endif
