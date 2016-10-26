#ifndef __AE_GRAPHICS_DEVICE_CONTEXT_SFML__
#define __AE_GRAPHICS_DEVICE_CONTEXT_SFML__

#include "Anima/Graphics/Device/Context.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/ContextDesc.h"
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
				//AE::uint createDrawingContext(AE::OS::Window *window, AE::Graphics::SurfaceFormat surfaceFormat);
				//AE::Graphics::Surface* createOffscreenSurface(const AE::Math::Point2 &dimensions, AE::Graphics::SurfaceFormat surfaceFormat, bool usesVideoMemory);
				void draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				void draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) {}
				void drawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color);
				void endRendering();
				void render();
				void setFullScreen(bool isFullScreen);
				void setParentWindow(AE::OS::Window *parentWindow);

			protected:
				sf::Context mContext;
				sf::RenderWindow mInnerWindow;
			};
		}
	}
}

#endif