#include "GameView.h"

void GameView::RenderFrame(AE::Real deltaTime)
{
	mDeviceContext->BeginRendering(AE::Graphics::Color(128, 0, 0, 255));

	// Iterate through visual entities
	Entity *player = mModel->GetPlayer();
	Entity *opponent = mModel->GetOpponent();
	Entity *ball = mModel->GetBall();
	
	// Advance animation

	// Draw
	mDeviceContext->DrawQuad(player->GetPosition(), player->GetPosition() + player->GetDimensions(), player->GetColor());
	mDeviceContext->DrawQuad(opponent->GetPosition(), opponent->GetPosition() + opponent->GetDimensions(), opponent->GetColor());
	mDeviceContext->DrawQuad(ball->GetPosition(), ball->GetPosition() + ball->GetDimensions(), ball->GetColor());

	mDeviceContext->EndRendering();
}