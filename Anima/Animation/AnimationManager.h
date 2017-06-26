#ifndef __AE_ANIMATION_MANAGER__
#define __AE_ANIMATION_MANAGER__

#include "Anima/Plugin.h"

#include "Animation.h"
#include "Range.h"

namespace AE
{
	namespace Animation
	{
		class AnimationManager : public AE::Plugin
		{
		public:
			AnimationManager() : Plugin(AE::PT_ANIMATION_MANAGER) { }
			~AnimationManager() { }

			template <typename T>
			AE::Animation::AnimationPtr<T> CreateAnimation(const AE::Animation::Range<T> &range, AE::Real duration) = 0;

			virtual bool Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool Uninstall() = 0;

		protected:

		};
	}
}

#endif