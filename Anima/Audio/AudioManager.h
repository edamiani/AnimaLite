#ifndef __AE_AUDIO_MANAGER__
#define __AE_AUDIO_MANAGER__

#include "Anima/Plugin.h"

namespace AE
{
	namespace Audio
	{
		class AudioManager : public AE::Plugin
		{
		public:
								AudioManager() : Plugin(AE::PT_AUDIO_MANAGER) {}
			virtual				~AudioManager() {}

			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool		Uninstall() = 0;



		protected:
			
		};
	}
}

#endif