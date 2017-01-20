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
	AE::Math::Vector2	GetDimensions() { return mDimensions; }
	AE::Math::Vector2	GetPosition() { return mPosition; }
	AE::Math::Vector2	GetVelocity() { return mVelocity; }
	void				SetPosition(const AE::Math::Vector2 &position) { mPosition = position; }
	void				SetVelocity(const AE::Math::Vector2 &velocity) { mVelocity = velocity; }
	
protected:
	AE::Graphics::Color mColor;
	AE::Math::Vector2	mDimensions;
	AE::Math::Vector2	mPosition;
	AE::Math::Vector2	mVelocity;
};

class GameModel
{
public:
	GameModel(AE::Math::Vector2 sceneDimensions);
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


	AE::Math::Vector2 mSceneDimensions;
};

#endif