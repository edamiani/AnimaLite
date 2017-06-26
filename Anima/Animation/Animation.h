#ifndef __AE_ANIMATION__
#define __AE_ANIMATION__

#include "Anima/Types.h"

#include <memory>

namespace AE
{
	namespace Animation
	{
		template <typename T>
		class Animation
		{
		public:
			Animation() { }
			~Animation() { }

			virtual const T& GetCurrentValue() = 0;
			virtual void Step(AE::Real deltaTime) = 0;

		protected:

		};

		//typedef std::unique_ptr<AE::Animation::Animation<int>> AnimationPtr;
		template<class T> using AnimationPtr = std::unique_ptr<AE::Animation::Animation<T>>;
	}
}

#endif
