#ifndef __AE_AUDIO_MUSIC__
#define __AE_AUDIO_MUSIC__

#include "Anima/Types.h"

namespace AE
{
	namespace Audio
	{
		class Music
		{
		public:
						Music() {}
			virtual		~Music() {}

			virtual		void Play(AE::int32 numRepeat = 0) = 0;
			virtual		void Pause() = 0;
			virtual		void Stop() = 0;

		protected:

		};
	}
}

#endif