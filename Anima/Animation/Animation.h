#ifndef __AE_ANIMATION__
#define __AE_ANIMATION__

#include "Anima/Types.h"

#include <memory>

namespace AE
{
	namespace Animation
	{
		class Animation
		{
		public:
			Animation() { }
			~Animation() { }

			virtual void Step(AE::Real deltaTime) = 0;

		protected:

		};

		typedef std::unique_ptr<AE::Animation::Animation> AnimationPtr;
	}
}

#endif
