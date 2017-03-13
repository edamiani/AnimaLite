#ifndef __AE_INPUT_JOYSTICK__
#define __AE_INPUT_JOYSTICK__

#include "Device.h"

#include <vector>

namespace AE
{
	namespace Input
	{
		class Joystick : public AE::Input::Device
		{
		public:
								Joystick(AE::int32 id) : mId(id) {  }
			virtual				~Joystick() {  }

			virtual AE::int32	GetAxisValue(AE::uint axisNum) = 0;
			virtual AE::int32	GetNumAxes() = 0;
			virtual AE::int32	GetNumButtons() = 0;
			virtual AE::int32	GetNumHats() = 0;
			virtual AE::int32	GetHatValue(AE::uint povNum) = 0;
			virtual bool		IsButtonDown(AE::uint buttton) = 0;


		protected:
			AE::int32 mId;
		};
	}
}

#endif