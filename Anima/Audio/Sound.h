#ifndef __AE_AUDIO_SOUND__
#define __AE_AUDIO_SOUND__

#include "Anima/Types.h"

namespace AE
{
	namespace Audio
	{
		class Sound
		{
		public:
						Sound() {}
			virtual		~Sound() {}

			virtual		void Play(AE::int32 numRepeat = 0) = 0;
			virtual		void Stop() = 0;

		protected:

		};
	}
}

#endif