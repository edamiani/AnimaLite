#ifndef __AE_GAME_CONTROLLER__
#define __AE_GAME_CONTROLLER__

#include "Anima/Types.h"

class GameController
{
	GameController() {}
	~GameController() {}

	void OnKeyUp() {}
	void Step(AE::Real deltaTime);
};

#endif