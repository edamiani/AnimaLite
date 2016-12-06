#ifndef __AE_GAME_CONTROLLER__
#define __AE_GAME_CONTROLLER__

#include "GameModel.h"

#include "Anima/PluginManager.h"
#include "Anima/Types.h"
#include "Anima/Input/Keyboard.h"
#include "Anima/Input/Manager.h"
#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"
#include "Anima/OS/WindowListener.h"

class GameController : public AE::OS::KeyListener, public AE::OS::MouseListener, public AE::OS::WindowListener
{
public:
	GameController(AE::PluginManager &pluginManager, GameModel &model) : mPluginManager(pluginManager), mModel(model) 
	{
		mInputManager = mPluginManager.GetInstalledPluginByType<AE::Input::Manager>(AE::PT_INPUT_MANAGER);
		mKeyboard = mInputManager->GetKeyboard();
	}

	~GameController() {}

	void OnKeyUp() {}
	void Step(AE::Real deltaTime);

private:
	AE::Input::Manager	*mInputManager;
	AE::Input::Keyboard	*mKeyboard;
	GameModel			&mModel;
	AE::PluginManager	&mPluginManager;
};

#endif