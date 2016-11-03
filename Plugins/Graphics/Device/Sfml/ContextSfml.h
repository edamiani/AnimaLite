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

				bool beginRendering();
				bool beginRendering(const AE::Graphics::Color &clearColor);
				void draw(const AE::Graphics::Device::Texture &texture, const AE::Math::Vector2 position);
				void draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				void draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) {}
				void drawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color);
				void drawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Device::Texture &texture);
				void endRendering();
				void render();
				void setFullScreen(bool isFullScreen);
				void setParentWindow(AE::OS::Window *parentWindow);

			protected:
				sf::Context mSfmlContext;
				sf::RenderWindow mInnerWindow;
				sf::Vertex mQuadVertices[4];
			};
		}
	}
}

#endif