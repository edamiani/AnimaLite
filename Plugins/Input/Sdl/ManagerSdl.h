#ifndef __ANIMA_INPUT_MANAGER_SDL__
#define __ANIMA_INPUT_MANAGER_SDL__

#include "Anima/Input/Manager.h"
#include "Anima/Input/InputManagerDesc.h"
#include "Anima/OS/EventManager.h"
#include "Anima/OS/MouseListener.h"

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
				assert(pluginDesc != nullptr);

				if (!SDL_WasInit(SDL_INIT_GAMECONTROLLER))
				{
					SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
				}

				static_cast<AE::Input::InputManagerDesc *>(pluginDesc)->eventManager->RegisterMouseListener("InputManagerSdl", this);

				mIsInstalled = true;

				return true;
			}

			bool Uninstall()
			{
				if (SDL_WasInit(SDL_INIT_GAMECONTROLLER))
				{
					SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
				}

				return true;
			}

			AE::Input::Keyboard*	GetKeyboard() { return &mKeyboard; }
			AE::Input::Mouse*		GetMouse() { return &mMouse; }

		private:
			AE::Input::KeyboardSdl	mKeyboard;
			AE::Input::MouseSdl		mMouse;
		};
	}
}

#endif