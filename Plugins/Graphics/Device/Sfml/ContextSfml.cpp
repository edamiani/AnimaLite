#include "ContextSfml.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"

#include "Plugins/Graphics/Device/Sfml/TextureSfml.h"

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

			void ContextSfml::draw(const AE::Graphics::Device::Texture &texture, const AE::Math::Vector2 position)
			{
				//AE::Graphics::Device::Texture temp = texture;
				sf::Texture *sfmlTexture = reinterpret_cast<AE::Graphics::Device::TextureSfml &>(const_cast<AE::Graphics::Device::Texture &>(texture)).getSfmlTexturePtr();

				sf::Vertex quadVertices[4];

				sf::Vector2u dimensions = sfmlTexture->getSize();
				quadVertices[0].position = sf::Vector2f(position.x(), position.y());
				quadVertices[0].texCoords = sf::Vector2f(0, 0);
				quadVertices[1].position = sf::Vector2f(position.x() + dimensions.x, position.y());
				quadVertices[1].texCoords = sf::Vector2f(dimensions.x, 0);
				quadVertices[2].position = sf::Vector2f(position.x() + dimensions.x, position.y() + dimensions.y);
				quadVertices[2].texCoords = sf::Vector2f(dimensions.x, dimensions.y);
				quadVertices[3].position = sf::Vector2f(position.x(), position.y() + dimensions.y);
				quadVertices[3].texCoords = sf::Vector2f(0, dimensions.y);

				sf::RenderStates renderStates;
				renderStates.texture = sfmlTexture;
				mInnerWindow.draw(quadVertices, 4, sf::Quads, renderStates);
				//mInnerWindow.draw(quadVertices, 4, sf::Quads);
			}

			void ContextSfml::drawLine(AE::Math::Vector2 &start, AE::Math::Vector2 &end, const AE::Graphics::Color &color)
			{
				//SDL_SetRenderDrawColor(mRenderer, color.R, color.G, color.B, color.A);
				//SDL_RenderDrawLine(mRenderer, start.x(), start.y(), end.x(), end.y());
			}

			void ContextSfml::drawQuad(const AE::Math::Vector2 &topLeft, const AE::Math::Vector2 &bottomRight, AE::Graphics::Device::Texture &texture)
			{
				sf::Vertex quadVertices[4];

				quadVertices[0].position = sf::Vector2f(topLeft.x(), bottomRight.y());
				quadVertices[0].color = sf::Color(255, 255, 255, 255);
				quadVertices[1].position = sf::Vector2f(bottomRight.x(), bottomRight.y());
				quadVertices[1].color = sf::Color(255, 255, 255, 255);
				quadVertices[2].position = sf::Vector2f(bottomRight.x(), topLeft.y());
				quadVertices[2].color = sf::Color(255, 255, 255, 255);
				quadVertices[3].position = sf::Vector2f(topLeft.x(), topLeft.y());
				quadVertices[3].color = sf::Color(255, 255, 255, 255);

				mInnerWindow.draw(quadVertices, 4, sf::Quads);
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