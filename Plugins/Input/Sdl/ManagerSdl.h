#ifndef __ANIMA_INPUT_MANAGER_SDL__
#define __ANIMA_INPUT_MANAGER_SDL__

#include "Anima/Input/Manager.h"
#include "Anima/Input/InputManagerDesc.h"
#include "Anima/OS/EventManager.h"
#include "Anima/OS/MouseListener.h"

#include "JoystickSdl.h"
#include "KeyboardSdl.h"
#include "MouseSdl.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

#include <cassert>

namespace AE
{
	namespace Input
	{
		class ManagerSdl : public AE::Input::Manager, public AE::OS::MouseListener
		{
		public:
			ManagerSdl() {}

			virtual ~ManagerSdl() {}

			bool Install(AE::uint options, PluginOptions *pluginDesc)
			{
				if(!SDL_WasInit(SDL_INIT_JOYSTICK))
				{
					SDL_InitSubSystem(SDL_INIT_JOYSTICK);
				}

				int numJoysticks = SDL_NumJoysticks();

				for(int i = 0; i < numJoysticks; i++)
				{
					SDL_JoystickOpen(i);
					mJoysticks.push_back(new JoystickSdl(i));
				}

				mIsInstalled = true;

				return true;
			}

			bool Uninstall()
			{
				if (SDL_WasInit(SDL_INIT_JOYSTICK))
				{
					SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
				}

				for(auto joystick : mJoysticks)
				{
					delete joystick;
				}
				mJoysticks.clear();

				return true;
			}

			AE::Input::Joystick*	GetJoystick(AE::uint index) { return mJoysticks[index]; }
			AE::Input::Keyboard*	GetKeyboard() { return &mKeyboard; }
			AE::Input::Mouse*		GetMouse() { return &mMouse; }
			AE::uint				GetNumJoysticks() { return mJoysticks.size(); }

		private:
			std::vector<AE::Input::Joystick *>		mJoysticks;
			AE::Input::KeyboardSdl	mKeyboard;
			AE::Input::MouseSdl		mMouse;
		};
	}
}

#endif