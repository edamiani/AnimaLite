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

				bool BeginRendering();
				bool BeginRendering(const AE::Graphics::Color &clearColor);
				//AE::uint createDrawingContext(AE::OS::Window *window, AE::Graphics::SurfaceFormat surfaceFormat);
				AE::Graphics::Surface* CreateOffscreenSurface(AE::Math::Vector2 &dimensions, AE::Graphics::SurfaceFormat surfaceFormat, bool usesVideoMemory = true);
				void Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer) {}
				void Draw3dObject(AE::Graphics::RenderOperationType operationType, AE::Graphics::Device::VertexBuffer *vertexBuffer, AE::Graphics::Device::IndexBuffer *indexBuffer) {}
				void EndRendering();
				void Render();
				void SetFullScreen(bool isFullScreen) {}

				ALLEGRO_DISPLAY* _GetAllegroDisplay() { return mAllegroDisplay; }
				HGLRC& _GetWinGlContext() { return mWinGlContext; }

			protected:
				ALLEGRO_DISPLAY *mAllegroDisplay;
				HGLRC mWinGlContext;
			};
		}
	}
}

#endif