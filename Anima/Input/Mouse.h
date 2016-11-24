#ifndef __AE_INPUT_MOUSE__
#define __AE_INPUT_MOUSE__

#include "Device.h"
#include "Anima/OS/Event.h"
#include "Anima/Math/Vector2.h"

namespace AE
{
	namespace Input
	{
		class Mouse : public AE::Input::Device
		{
		public:
										Mouse() {  }
			virtual						~Mouse() {  }

			virtual AE::Math::Vector2	GetAbsolutePosition() = 0;
			virtual AE::Math::Vector2	GetRelativePosition() = 0;
			virtual bool				IsButtonDown(AE::OS::MouseButtonType button) = 0;
		};
	}
}

#endif