#ifndef __AE_AUDIO_MANAGER_SFML__
#define __AE_AUDIO_MANAGER_SFML__

#include "Anima/Audio/AudioManager.h"

namespace AE
{
	namespace Audio
	{
		class AudioManagerSfml : public AE::Audio::AudioManager
		{
		public:
								AudioManagerSfml() : AudioManager() {}
			virtual				~AudioManagerSfml() {}

			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool		Uninstall() = 0;



		protected:
			
		};
	}
}

#endif