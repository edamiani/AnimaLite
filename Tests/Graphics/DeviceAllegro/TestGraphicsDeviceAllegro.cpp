#include "TestGraphicsDeviceAllegro.h"

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

	AE::OS::WindowDesc windowDesc;
	windowDesc.dimensions = AE::Math::Vector2(640, 480);
	windowDesc.position = AE::Math::Vector2(50, 50);
	windowDesc.title = "Window Test";

	auto window = windowManager->CreateWindow(windowDesc);

	auto *deviceDriver = deviceManager->AcquireDeviceDriver(0, AE::Graphics::Device::DT_NONE);

	auto *deviceContext = deviceDriver->CreateDeviceContext(window);

	std::unique_ptr<TestListener> testListener = std::make_unique<TestListener>();

	eventManager->RegisterWindowListener("WindowListener", testListener.get());
	eventManager->RegisterKeyListener("WindowListener", testListener.get());
	eventManager->RegisterMouseListener("WindowListener", testListener.get());

	window->Show();

	AE::OS::EventQueue *eventQueue = eventManager->GetEventQueue();

	auto image = imageManager->CreateImage("Gandalf.png");
	auto texture = deviceDriver->CreateTexture(image->GetDimensions(), image->GetData());

	//Transform2 transform;

	float angle = 0;
	float scale = 0.9f;
	float multiplier = -1;

	//transform = transform.Translate(Vector2(-image->GetDimensions().x() / 2.0f, -image->GetDimensions().y() / 2.0f))
		//.Rotate(0.5f)
						 //.Translate(Vector2(image->GetDimensions().x() / 2.0f, image->GetDimensions().y() / 2.0f));
		;
	//transform = transform.Translate(Vector2(50, 50)).Rotate(0.5f);
	//transform = transform.Scale(Vector2(0.5f, 0.5f));

	while(eventQueue->PollEvents()) 
	{ 
		deviceContext->BeginRendering(AE::Graphics::Color(128, 0, 0, 255));

		Transform2 transform;
		/*transform = transform.Translate(Vector2(image->GetDimensions().x() / 2.0f, image->GetDimensions().y() / 2.0f))
			.Rotate(angle);*/
		transform = transform
			.Translate(Vector2(150, 150))
			.Rotate(angle)
			.Translate(Vector2(50, 50))
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

		//deviceContext->drawQuad(AE::Math::Vector2(50, 50), AE::Math::Vector2(500, 500), texture);

		deviceContext->EndRendering();
	}

	windowManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::WindowManagerSdl>("WindowSdl");

	eventManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::OS::EventManagerSdl>("EventSdl");

	deviceManager->Uninstall();
	pluginManager->UnregisterPlugin<AE::Graphics::Device::ManagerSfml>("GraphicsSfml");

	return 0;
}