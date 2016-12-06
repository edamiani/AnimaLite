#ifndef __AE_OS_TIMER_SDL__
#define __AE_OS_TIMER_SDL__

#include "Anima/Types.h"
#include "Anima/OS/Timer.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace OS
	{
		class TimerSdl : public AE::OS::Timer
		{
		private:
			float		mAccumulator = 0;
			bool		mHasStarted = false;
			float		mInterval = 0;
			AE::uint32	mCurrentTime = 0;
			AE::uint32	mPreviousTime = 0;
			AE::uint32	mStartingTime = 0;

		public:
			TimerSdl() { }

			float TimerSdl::GetInterval() { return mInterval; }

			AE::uint32 GetIntervalFromLastMark()
			{
				return mCurrentTime - mPreviousTime;
			}

			AE::uint32 GetIntervalFromStart()
			{
				return mCurrentTime - mStartingTime;
			}

			bool TimerSdl::HasStarted() { return mHasStarted; }

			void TimerSdl::Mark()
			{
				mPreviousTime = mCurrentTime;
				mCurrentTime = SDL_GetTicks();
			}

			void TimerSdl::Reset() { mPreviousTime = mStartingTime = mCurrentTime; }

			void TimerSdl::Start() 
			{ 
				mStartingTime = SDL_GetTicks(); 
			}

			void TimerSdl::Stop() { mHasStarted = false; }

			void TimerSdl::StopAndReset()
			{
				mHasStarted = false;
				mAccumulator = 0;
			}

			bool TimerSdl::Step(float elapsedTimeInSeconds)
			{
				if (mHasStarted)
				{
					mAccumulator += elapsedTimeInSeconds;
					if (mAccumulator >= mInterval)
					{
						mAccumulator -= mInterval;
						//onInterval();
						return true;
					}
				}
				return false;
			}
		};
	}
}

#endif