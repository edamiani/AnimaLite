#ifndef __AE_AUDIO_MUSIC_SFML__
#define __AE_AUDIO_MUSIC_SFML__

#include "Anima/Audio/Music.h"

namespace AE
{
	namespace Audio
	{
		class MusicSfml : public AE::Audio::Music
		{
		public:
						MusicSfml() {}
			virtual		~MusicSfml() {}

			virtual		void Play(AE::int32 numRepeat = 0) = 0;
			virtual		void Pause() = 0;
			virtual		void Stop() = 0;

		protected:

		};
	}
}

#endif