#ifndef __AE_GAME_VIEW__
#define __AE_GAME_VIEW__

#include "GameModel.h"

#include "Anima/Types.h"
#include "Anima/Graphics/Device/Texture.h"

class GameView
{
public:
	GameView(GameModel &model) : mModel(model) {}
	~GameView() {}

	void RenderFrame(AE::Real deltaTime);

private:
	AE::Graphics::Device::Texture	mBall;
	GameModel						&mModel;
	AE::Graphics::Device::Texture	mOpponent;
	AE::Graphics::Device::Texture	mPlayer;
};

#endif