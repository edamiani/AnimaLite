#ifndef __AE_GRAPHICS_DEVICE_CONTEXT_ALLEGRO__
#define __AE_GRAPHICS_DEVICE_CONTEXT_ALLEGRO__

#include "Anima/Graphics/Device/Context.h"
#include "Anima/Math/Vector2.h"

#include "Plugins/Graphics/Device/Allegro/ManagerAllegro.h"

//#include "AnimaGraphicsSurfaceDX9.h"
//#include "AnimaGraphicsDrawingContextDesc.h"
//#include "AnimaGraphicsDrawingContextDX9.h"

#include "Dependencies/allegro/include/allegro5/allegro.h"

#include <vector>

namespace AE
{
	namespace OS
	{
		class Window;
	}

	namespace Graphics
	{
		namespace Device
		{
			class ContextAllegro : public AE::Graphics::Device::Context
			{
			public:
				ContextAllegro(AE::Graphics::Device::Driver *deviceDriver, AE::OS::Window *window);
				virtual ~ContextAllegro();

				bool beginRendering();
				bool beginRendering(const AE::Graphics::Color &clearColor);
				//AE::uint createDrawingContext(AE::OS::Window *window, AE::Graphics::SurfaceFormat surfaceFormat);
				AE::Graphics::Surface* createOffscreenSurface(AE::Math::Vector2 &dimensions, AE::Graphics::SurfaceFormat surfaceFormat, bool usesVideoMemory = true);
				void draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				void draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) {}
				void endRendering();
				void render();
				void setFullScreen(bool isFullScreen) {}

				ALLEGRO_DISPLAY* _getAllegroDisplay() { return mAllegroDisplay; }
				HGLRC& _getWinGlContext() { return mWinGlContext; }

			protected:
				ALLEGRO_DISPLAY *mAllegroDisplay;
				HGLRC mWinGlContext;
			};
		}
	}
}

#endif