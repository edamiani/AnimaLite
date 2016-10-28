#include "ContextSfml.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"

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
				AE::OS::Window *window = contextDesc.parentWindow;

				sf::ContextSettings settings;
				settings.majorVersion = 3;
				settings.minorVersion = 1;
				mInnerWindow.create(window->getHandle(), settings);

				contextDesc.parentWindow->attachDeviceContext(this);
			}

			ContextSfml::~ContextSfml()
			{

			}

			bool ContextSfml::beginRendering()
			{
				mInnerWindow.clear();

				return true;
			}

			bool ContextSfml::beginRendering(const AE::Graphics::Color &clearColor)
			{
				mInnerWindow.clear(sf::Color(clearColor.R, clearColor.G, clearColor.B, clearColor.A));

				return true;
			}

			void ContextSfml::drawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color)
			{
				//SDL_SetRenderDrawColor(mRenderer, color.R, color.G, color.B, color.A);
				//SDL_RenderDrawLine(mRenderer, start.x(), start.y(), end.x(), end.y());
			}

			void ContextSfml::endRendering()
			{
				mInnerWindow.display();
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