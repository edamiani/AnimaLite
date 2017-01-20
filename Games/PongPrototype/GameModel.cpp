#include "GameModel.h"

using namespace AE;
using namespace AE::Math;

GameModel::GameModel(Vector2 sceneDimensions) :
	mSceneDimensions(sceneDimensions)
{
	mPlayer = new Entity(Vector2(20, 160), Vector2(30, 160), Graphics::Color(255, 128, 0, 255));

	mOpponent = new Entity(Vector2(590, 160), Vector2(30, 160), Graphics::Color(0, 160, 255, 255));

	mBall = new Entity(Vector2(310, 230), Vector2(20, 20), Graphics::Color(255, 0, 128, 255));
	mBall->SetVelocity(Vector2(120, 80));
}

GameModel::~GameModel()
{
	delete mPlayer;
	delete mOpponent;
	delete mBall;
}

void GameModel::Setup()
{
	// Create scene
	// Add player
	// Add opponent
	// Add walls
	// Add goals
}

void GameModel::Step(Real deltaTime)
{
	// Move ball
	MoveBall(deltaTime);

	// Step through opponent's AI
	// Check for collision
}

void GameModel::Terminate()
{
	// Destroy entities
}

void GameModel::MoveBall(Real deltaTime) 
{
	// Move ball according to speed
	mBall->SetPosition(Vector2(mBall->GetPosition().x() + (mBall->GetVelocity().x() * deltaTime), 
							   mBall->GetPosition().y() + (mBall->GetVelocity().y() * deltaTime)));
	
	// Check for collision and change ball's direction if needed
	Vector2 position = mBall->GetPosition();
	Vector2 dimensions = mBall->GetDimensions();
	Vector2 velocity = mBall->GetVelocity();
	if(position.x() < 0 || position.x() + dimensions.x() > mSceneDimensions.x())
	{
		mBall->SetVelocity(Vector2(-velocity.x(), velocity.y()));
	}
	
	if(position.y() < 0 || position.y() + dimensions.y() > mSceneDimensions.y())
	{
		mBall->SetVelocity(Vector2(velocity.x(), -velocity.y()));
	}
}

void GameModel::MovePlayer(bool isLeft) 
{
	// Move player according to speed
	Vector2 position = mPlayer->GetPosition();
	if(isLeft)
	{
		mPlayer->SetPosition(Vector2(position.x(), position.y() - 1));
	}
	else
	{
		mPlayer->SetPosition(Vector2(position.x(), position.y() + 1));
	}


	// Check for collision
	// Change player's position if needed
}

void GameModel::MoveOpponent(Real deltaTime) 
{
}