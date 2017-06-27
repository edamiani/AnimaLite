#include "Ch05-Entity-Component.h"

#include "Anima/Math/Transform2.h"

#include <iostream>
#include <memory>

using namespace AE::Math;

void TestListener::OnKeyDown(const AE::OS::EventKeyboard &event)
{
	std::cout << "onKeyDown!" << std::endl;
}

void TestListener::OnKeyUp(const AE::OS::EventKeyboard &event)
{
	std::cout << "onKeyUp!" << std::endl;
}

void TestListener::OnButtonDown(const AE::OS::EventMouse &event)
{
	std::cout << "onButtonDown!" << std::endl;
}

void TestListener::OnButtonUp(const AE::OS::EventMouse &event)
{
	std::cout << "onButtonUp!" << std::endl;
}

void TestListener::OnMouseMove(const AE::OS::EventMouse &event)
{
	std::cout << "onMouseMove!" << std::endl;
}

int main(int argc, char* args[])
{
	AE::PluginManager *pluginManager = AE::PluginManager::Initialize();

	auto *eventManager = pluginManager->RegisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	eventManager->Install(AE::NO_OPTIONS);

	auto *windowManager = pluginManager->RegisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	windowManager->Install(AE::NO_OPTIONS);

	auto *deviceManager = pluginManager->RegisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");
	deviceManager->Install(AE::NO_OPTIONS);

	auto *imageManager = pluginManager->RegisterPlugin<AE::Graphics::ImageManagerSfml>("ImageManagerSfml");
	imageManager->Install(AE::NO_OPTIONS);

	auto *animationManager = pluginManager->RegisterPlugin<AE::Animation::AnimationManagerChoreograph>("AnimationManagerChoreograph");
	animationManager->Install(AE::NO_OPTIONS);

	auto *ecsManager = pluginManager->RegisterPlugin<AE::Ecs::EcsManagerAnax>("EcsManagerAnax");
	ecsManager->Install(AE::NO_OPTIONS);

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Window Test";

	auto window = windowManager->CreateWindow(windowDesc);

	auto *deviceDriver = deviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);

	auto *deviceContext = deviceDriver->CreateDeviceContext(window);

	std::unique_ptr<TestListener> testListener = std::make_unique<TestListener>();

	eventManager->RegisterWindowListener("WindowListener", testListener.get());
	eventManager->RegisterKeyListener("KeyListener", testListener.get());
	eventManager->RegisterMouseListener("MouseListener", testListener.get());

	window->Show();

	AE::OS::EventQueue *eventQueue = eventManager->GetEventQueue();

	auto image = imageManager->CreateImage("Gandalf.png");
	auto texture = deviceDriver->CreateTexture(image->GetDimensions(), image->GetData());

	float angle = 0;
	float scale = 0.9f;
	float multiplier = -1;

	AE::Animation::AnimationPtr<AE::int16> animation = animationManager->CreateAnimation<AE::int16>(AE::Animation::Range<AE::int16>(1, 3), 2.0);

	std::unique_ptr<AE::OS::TimerSdl> timer(new AE::OS::TimerSdl());
	timer->Start();

	while(eventQueue->PollEvents()) 
	{
		timer->Mark();
		AE::uint32 deltaTime = timer->GetIntervalFromLastMark();

		animation->Step(deltaTime / 1000.0f);
		std::cout << animation->GetCurrentValue() << std::endl;

		deviceContext->BeginRendering(AE::Graphics::Color(128, 0, 0, 255));

		Transform2 transform;
		/*transform = transform.Translate(Vector2(image->GetDimensions().x() / 2.0f, image->GetDimensions().y() / 2.0f))
			.Rotate(angle);*/
		transform = transform
			.Translate(Vector2(150, 150))
			.Rotate(angle)
			//.Translate(Vector2(50, 50))
			.Scale(Vector2(scale, scale))
			;
		//transform = transform.Rotate(angle);
		deviceContext->DrawTexture(texture, transform);
		angle += 0.001f;
		scale += 0.001f * multiplier;

		if(scale < 0.5f || scale > 0.9)
		{
			multiplier *= -1;
		}

		deviceContext->EndRendering();
	}

	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");
	pluginManager->UnregisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");
	pluginManager->UnregisterPlugin<AE::Graphics::ImageManagerSfml>("ImageManagerSfml");
	pluginManager->UnregisterPlugin<AE::Animation::AnimationManagerChoreograph>("AnimationManagerChoreograph");
	pluginManager->UnregisterPlugin<AE::Ecs::EcsManagerAnax>("EcsManagerAnax");

	return 0;
}