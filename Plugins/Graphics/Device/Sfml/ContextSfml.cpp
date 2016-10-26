#include "ContextSfml.h"

//#include "../AnimaGraphicsDeviceContextSfml.h"
//#include "Anima/Graphics/Device/GL15/DriverGL15.h"
//#include "Anima/Graphics/Device/GL15/ManagerGL15.h"
//#include "Anima/Graphics/Device/GL15/PipelineGL15.h"
//#include "Anima/Graphics/Device/GL15/FrameBufferGL15.h"
//#include "Anima/Graphics/Device/GL15/StageInput2dGL15.h"
//#include "Anima/Graphics/Device/GL15/VertexBufferGL.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"

#include "Plugins/OS/WindowSdl/WindowSdl.h"

#include <cassert>
#include <cstring>
#include <string>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ContextSfml::ContextSfml(AE::Graphics::Device::ContextDesc &contextDesc, AE::Graphics::Device::Driver *deviceDriver) 
				: Context(deviceDriver)
			{
				AE::OS::Window *window = static_cast<AE::OS::WindowSdl *>(contextDesc.parentWindow);

				mInnerWindow.create(window->getHandle());

				contextDesc.parentWindow->attachDeviceContext(this);
			}

			ContextSfml::~ContextSfml()
			{
				SDL_DestroyRenderer(mRenderer);
			}

			bool ContextSfml::beginRendering()
			{
				SDL_RenderClear(mRenderer);

				return true;
			}

			bool ContextSfml::beginRendering(const AE::Graphics::Color &clearColor)
			{
				SDL_SetRenderDrawColor(mRenderer, clearColor.R, clearColor.G, clearColor.B, clearColor.A);

				SDL_RenderClear(mRenderer);

				return true;
			}

			void ContextSfml::drawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color)
			{
				SDL_SetRenderDrawColor(mRenderer, color.R, color.G, color.B, color.A);
				SDL_RenderDrawLine(mRenderer, start.x(), start.y(), end.x(), end.y());
			}

			void ContextSfml::endRendering()
			{
				SDL_RenderPresent(mRenderer);
			}

			void ContextSfml::render()
			{
			}

			void ContextSfml::setFullScreen(bool isFullScreen)
			{
				if(mIsFullScreen)
				{
					/*DEVMODE dm;
					dm.dmSize = sizeof(DEVMODE);
					dm.dmPelsWidth = mParentWindow->getDimensions().x;
					dm.dmPelsHeight = mParentWindow->getDimensions().y;
					dm.dmBitsPerPel = contextDesc.getColorDepth();
					dm.dmDisplayFrequency = 60;
					dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;
					ChangeDisplaySettings(&dm, CDS_FULLSCREEN);*/
				}
			}

			void ContextSfml::setParentWindow(AE::OS::Window *parentWindow)
			{
				mParentWindow = parentWindow;

				//mDeviceContextHandle = ::GetDC(static_cast<AE::OS::WindowWin *>(mParentWindow)->_getWindowHandle());
			}
		}
	}
}