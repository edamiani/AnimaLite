#ifndef __AE_INPUT_MOUSE_SDL__
#define __AE_INPUT_MOUSE_SDL__

#include "Anima/Input/Enums.h"
#include "Anima/Input/Mouse.h"
#include "Anima/Math/Vector2.h"
#include "Anima/OS/Event.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace Input
	{
		class MouseSdl : public AE::Input::Mouse
		{
		public:
								MouseSdl() {  }
								~MouseSdl() {  }

			AE::Math::Vector2	GetAbsolutePosition() { SDL_GetMouseState(&mPosition.x, &mPosition.y); return mPosition; }
			AE::Math::Vector2	GetRelativePosition() { SDL_GetRelativeMouseState(&mPosition.x, &mPosition.y); return mPosition; }
			bool				IsButtonDown(AE::OS::MouseButtonType button) { return mIsButtonDown[static_cast<int>(button)]; }
			bool				Poll() { return true; }

			void				OnButtonDown(const AE::OS::EventMouse &event) { mIsButtonDown[event.buttonPressed] = true; }
			void				OnButtonUp(const AE::OS::EventMouse &event) { mIsButtonDown[event.buttonPressed] = false; }

		private:
			AE::Math::Vector2	mPosition;
			bool				mIsButtonDown[3];
		};
	}
}

#endif