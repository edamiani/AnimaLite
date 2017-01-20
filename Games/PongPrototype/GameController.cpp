#include "GameController.h"

void GameController::OnKeyUp(const AE::OS::EventKeyboard &event)
{
	if(event.keyInfo.keyCode == AE::Input::KC_ESCAPE)
	{
		mIsRunning = false;
	}
}

bool GameController::Step(AE::Real deltaTime)
{
	mEventManager->GetEventQueue()->PollEvents();

	// Listen to keyboard
	mKeyboard->Poll();
	if(mKeyboard->IsKeyDown(AE::Input::KC_UP_ARROW))
	{
		mModel->MovePlayer(true);
	}
	else if(mKeyboard->IsKeyDown(AE::Input::KC_DOWN_ARROW))
	{
		mModel->MovePlayer(false);
	}

	return true;
}