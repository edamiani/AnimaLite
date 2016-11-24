#ifndef __AE_INPUT_DEVICE__
#define __AE_INPUT_DEVICE__

namespace AE
{
	namespace Input
	{
		class Device
		{
		public:
							Device() { mBuffered = false; }
			virtual			~Device() {  }

			bool			IsBuffered() { return mBuffered; }
			void			SetBuffered(bool buffered) { mBuffered = buffered; }
			virtual bool	Poll() = 0;

		protected:
			bool			mBuffered;
		};
	}
}

#endif