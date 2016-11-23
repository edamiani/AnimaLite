#ifndef __AE_GAME_MODEL__
#define __AE_GAME_MODEL__

#include "Anima/Types.h"

class GameModel
{
public:
	GameModel() {}
	~GameModel() {}

	void Setup();
	void Step(AE::Real deltaTime);
	void Terminate();

private:
	void MoveBall(AE::Real deltaTime);
	void MovePlayer(bool isLeft);
	void MoveOpponent(AE::Real deltaTime);
	


	// Player
	// Opponent
	// Ball
	// Left wall
	// Right wall
	// Player goal
	// Opponent goal
};

#endif