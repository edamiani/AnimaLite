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

			AE::Math::Vector2 GetAbsolutePosition() 
			{
				int x, y;
				SDL_GetMouseState(&x, &y);

				return AE::Math::Vector2(x, y); 
			}

			AE::Math::Vector2 GetRelativePosition() 
			{
				int x, y;
				SDL_GetRelativeMouseState(&x, &y);

				return AE::Math::Vector2(x, y);
			}

			bool				IsButtonDown(AE::OS::MouseButtonType button) 
			{ 
				int buttons = SDL_GetMouseState(nullptr, nullptr);

				bool result = false;

				switch(button)
				{
				case AE::OS::MBT_LEFT:
					result = buttons & SDL_BUTTON(SDL_BUTTON_LEFT);
					break;
				case AE::OS::MBT_MIDDLE:
					result = buttons & SDL_BUTTON(SDL_BUTTON_MIDDLE);
					break;
				case AE::OS::MBT_RIGHT:
					result = buttons & SDL_BUTTON(SDL_BUTTON_RIGHT);
					break;
				}

				return result;
			}

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