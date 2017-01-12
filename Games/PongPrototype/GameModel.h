#ifndef __AE_GAME_MODEL__
#define __AE_GAME_MODEL__

#include "Anima/Types.h"
#include "Anima/Graphics/Color.h"
#include "Anima/Math/Vector2.h"

class Entity
{
public:
	Entity(AE::Math::Vector2 position, AE::Math::Vector2 dimensions, AE::Graphics::Color color) :
		mPosition(position), mDimensions(dimensions), mColor(color)
	{ }

	AE::Graphics::Color GetColor() { return mColor; }
	AE::Math::Vector2 GetDimensions() { return mDimensions; }
	AE::Math::Vector2 GetPosition() { return mPosition; }
	
protected:
	AE::Graphics::Color mColor;
	AE::Math::Vector2 mDimensions;
	AE::Math::Vector2 mPosition;
};

class GameModel
{
public:
	GameModel();
	~GameModel();

	void Setup();
	void Step(AE::Real deltaTime);
	void Terminate();

	Entity* GetBall() { return mBall; }
	Entity* GetOpponent() { return mOpponent; }
	Entity* GetPlayer() { return mPlayer; }

	void MoveBall(AE::Real deltaTime);
	void MovePlayer(bool isLeft);
	void MoveOpponent(AE::Real deltaTime);

private:
	// Player
	Entity *mPlayer;
	// Opponent
	Entity *mOpponent;
	// Ball
	Entity *mBall;
	// Left wall
	// Right wall
	// Player goal
	// Opponent goal
};

#endif