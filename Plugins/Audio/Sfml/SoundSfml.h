#ifndef __AE_AUDIO_SOUND_SFML__
#define __AE_AUDIO_SOUND_SFML__

#include "Anima/Audio/Sound.h"

namespace AE
{
	namespace Audio
	{
		class SoundSfml : public Sound
		{
		public:
						SoundSfml() {}
			virtual		~SoundSfml() {}

			virtual		void Play(AE::int32 numRepeat = 0) = 0;
			virtual		void Stop() = 0;

		protected:

		};
	}
}

#endif