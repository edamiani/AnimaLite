#ifndef __AE_OS_TIMER__
#define __AE_OS_TIMER__

#include "Anima/Types.h"

namespace AE
{
	namespace OS
	{
		class Timer
		{
		public:
			Timer() {}
			virtual ~Timer() {}

			//virtual float GetInterval() = 0;
			virtual AE::uint32 GetIntervalFromLastMark() = 0;
			virtual AE::uint32 GetIntervalFromStart() = 0;
			//virtual bool HasStarted() = 0;
			virtual void Mark() = 0;
			virtual void Reset() = 0;
			virtual void Start() = 0;
			//virtual bool Step(float elapsedTimeInSeconds) = 0;
			//virtual void Stop() = 0;
			//virtual void StopAndReset() = 0;
		};
	}
}

#endif