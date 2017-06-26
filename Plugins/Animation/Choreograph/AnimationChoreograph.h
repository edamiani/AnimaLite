#ifndef __AE_ANIMATION_CHOREOGRAPH__
#define __AE_ANIMATION_CHOREOGRAPH__

#include "Anima/Types.h"
#include "Anima/Animation/Animation.h"

#include "Plugins/Animation/Choreograph/RangeChoreograph.h"

#include "choreograph/Choreograph.h"

namespace AE
{
	namespace Animation
	{
		template <typename T>
		class AnimationChoreograph : public AE::Animation::Animation<T>
		{
		public:
			AnimationChoreograph(AE::Animation::Range<T> &range, AE::Real duration) 
			{ 
				mOutput = choreograph::Output<T>(range.GetFrom());
				mTimeline.apply(&mOutput)
					.then<choreograph::RampTo>(range.GetTo(), duration);
				//mMotionOptions = mTimeline.apply(mOutput);
				//mMotionOptions.then<choreograph::RampTo>(range.GetTo(), duration);
			}

			~AnimationChoreograph() { }

			const T& GetCurrentValue()
			{
				return mOutput.value();
			}

			void Step(AE::Real deltaTime)
			{
				mTimeline.step(deltaTime);
			}

		protected:
			//choreograph::MotionOptions<T>	mMotionOptions;
			choreograph::Output<T>			mOutput;
			choreograph::Timeline			mTimeline;
		};
	}
}

#endif