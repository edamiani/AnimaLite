#ifndef __AE_GAME_VIEW__
#define __AE_GAME_VIEW__

#include "GameModel.h"

#include "Anima/PluginManager.h"
#include "Anima/Types.h"
#include "Anima/Graphics/Device/Context.h"
#include "Anima/Graphics/Device/Manager.h"
#include "Anima/Graphics/Device/Texture.h"

class GameView
{
public:
	GameView(AE::Graphics::Device::Context	*deviceContext, GameModel *model) : 
		mDeviceContext(deviceContext), mModel(model)
	{	
	}

	~GameView() {}

	void RenderFrame(AE::Real deltaTime);

private:
	AE::Graphics::Device::Texture	mBall;
	AE::Graphics::Device::Context	*mDeviceContext;
	GameModel						*mModel;
	AE::Graphics::Device::Texture	mOpponent;
	AE::Graphics::Device::Texture	mPlayer;
};

#endif