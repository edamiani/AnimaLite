#ifndef __AE_AUDIO_PLAYER_MANAGER__
#define __AE_AUDIO_PLAYER_MANAGER__

#include "Anima/Plugin.h"

namespace AE
{
	namespace Audio
	{
		class AudioPlayerManager : public AE::Plugin
		{
		public:
								AudioPlayerManager() : Plugin(AE::PT_AUDIO_PLAYER_MANAGER) {}
			virtual				~AudioPlayerManager() {}

			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool		Uninstall() = 0;



		protected:

		};
	}
}

#endif