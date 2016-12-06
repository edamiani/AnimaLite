#include "GameController.h"

void GameController::Step(AE::Real deltaTime)
{
	// Listen to keyboard
	mKeyboard->Poll();
	if(mKeyboard->IsKeyDown(AE::Input::KC_LEFT_ARROW))
	{
		mModel.MovePlayer(true);
	}
	else if(mKeyboard->IsKeyDown(AE::Input::KC_RIGHT_ARROW))
	{
		mModel.MovePlayer(false);
	}
}