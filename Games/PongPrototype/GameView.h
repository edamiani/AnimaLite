#ifndef __AE_GAME_VIEW__
#define __AE_GAME_VIEW__

#include "Anima/Types.h"

class GameView
{
public:
	GameView() {}
	~GameView() {}

	void RenderFrame(AE::Real deltaTime);
};

#endif