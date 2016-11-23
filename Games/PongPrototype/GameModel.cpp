#include "GameModel.h"

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
}

void GameModel::MoveOpponent(AE::Real deltaTime) 
{
}