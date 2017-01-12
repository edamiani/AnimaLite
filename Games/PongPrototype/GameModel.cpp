#include "GameModel.h"

GameModel::GameModel()
{
	mPlayer = new Entity(AE::Math::Vector2(20, 160), AE::Math::Vector2(30, 160), AE::Graphics::Color(255, 128, 0, 255));
	mOpponent = new Entity(AE::Math::Vector2(590, 160), AE::Math::Vector2(30, 160), AE::Graphics::Color(0, 160, 255, 255));
	mBall = new Entity(AE::Math::Vector2(310, 230), AE::Math::Vector2(20, 20), AE::Graphics::Color(255, 0, 128, 255));
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

void GameModel::Step(AE::Real deltaTime)
{
	// Move ball
	// Step through opponent's AI
	// Check for collision
}

void GameModel::Terminate()
{
	// Destroy entities
}

void GameModel::MoveBall(AE::Real deltaTime) 
{
	// Move ball according to speed
	// Check for collision
	// Change ball's direction if needed
}

void GameModel::MovePlayer(bool isLeft) 
{
	// Move player according to speed
	// Check for collision
	// Change player's position if needed

	std::cout << isLeft << std::endl;
}

void GameModel::MoveOpponent(AE::Real deltaTime) 
{
}