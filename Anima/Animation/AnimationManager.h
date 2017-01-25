#ifndef __AE_ANIMATION_MANAGER__
#define __AE_ANIMATION_MANAGER__

#include "Animation.h"

namespace AE
{
	namespace Animation
	{
		class AnimationManager
		{
		public:
			AnimationManager() { }
			~AnimationManager() { }

			virtual AE::Animation::Animation* CreateAnimation() = 0;

		protected:

		};
	}
}

#endif
