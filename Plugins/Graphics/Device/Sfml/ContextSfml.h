#ifndef __AE_GRAPHICS_DEVICE_CONTEXT_SFML__
#define __AE_GRAPHICS_DEVICE_CONTEXT_SFML__

#include "Anima/Graphics/Device/Context.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/ContextDesc.h"
#include "Anima/Graphics/Device/Texture.h"
#include "Anima/OS/Window.h"

#include "SFML/Graphics.hpp"

#include <vector>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class ContextSfml : public AE::Graphics::Device::Context
			{
			public:
				ContextSfml(AE::Graphics::Device::ContextDesc &contextDesc, AE::Graphics::Device::Driver *deviceDriver);
				virtual ~ContextSfml();

				bool BeginRendering();
				bool BeginRendering(const AE::Graphics::Color &clearColor);
				void DrawTexture(AE::Graphics::Device::TexturePtr const &texture, const AE::Math::Vector2 &position);
				void Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				void Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) {}
				void DrawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color);
				void DrawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Color &color);
				void DrawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Device::Texture &texture);
				void EndRendering();
				void Render();
				void SetFullScreen(bool isFullScreen);
				void SetParentWindow(AE::OS::Window *parentWindow);

			protected:
				sf::Context mSfmlContext;
				sf::RenderWindow mSfmlWindow;
				sf::Vertex mQuadVertices[4];
			};
		}
	}
}

#endif