#ifndef __AE_ANIMATION_MANAGER_CHOREOGRAPH__
#define __AE_ANIMATION_MANAGER_CHOREOGRAPH__

#include "Anima/Animation/AnimationManager.h"

#include "AnimationChoreograph.h"

#include "choreograph/Choreograph.h"

namespace AE
{
	namespace Animation
	{
		class AnimationManagerChoreograph : public AE::Animation::AnimationManager
		{
		public:
			AnimationManagerChoreograph() { }
			~AnimationManagerChoreograph() { }

			template <typename T>
			AE::Animation::AnimationPtr<T> CreateAnimation(AE::Animation::Range<T> &range, AE::Real duration)
			{
				std::unique_ptr<AE::Animation::Animation<T>> animation(new AnimationChoreograph<T>(range, duration));

				return animation;
			}

			bool Install(AE::uint options, PluginOptions *pluginDesc = nullptr)
			{
				mIsInstalled = true;

				return true;
			}

			bool Uninstall()
			{
				mIsInstalled = false;

				return true;
			}

		protected:

		};
	}
}

#endif
