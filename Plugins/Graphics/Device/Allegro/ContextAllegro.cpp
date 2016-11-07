#include "Plugins/Graphics/Device/Allegro/ContextAllegro.h"

//#include "../include/AnimaGraphicsDeviceDriver.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/OS/Window.h"
#include "Anima/Platform.h"
#include "Plugins/Graphics/Device/Allegro/ColorBufferAllegro.h"

#include <cassert>
#include <string>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ContextAllegro::ContextAllegro(AE::Graphics::Device::Driver *deviceDriver, AE::OS::Window *window) 
				: Context(deviceDriver)
			{
				switch(mDeviceDriver->getType())
				{
				case AE::Graphics::Device::DT_D3D9:
					al_set_new_display_flags(ALLEGRO_DIRECT3D_INTERNAL);
					break;
				case AE::Graphics::Device::DT_GL_30:
					al_set_new_display_flags(ALLEGRO_OPENGL_3_0);
					break;
				case AE::Graphics::Device::DT_GL:
				default:
					al_set_new_display_flags(ALLEGRO_OPENGL);
					break;
				}

				AE::Math::Vector2 dimensions = window->getDimensions();
				mAllegroDisplay = al_create_display(dimensions.x(), dimensions.y());
				//mFrameBuffer = new AE::Graphics::Device::ColorBufferAllegro(al_get_backbuffer(mAllegroDisplay));
				
	#ifdef AE_PLATFORM_WIN32
				if(mDeviceDriver->getType() == AE::Graphics::Device::DT_GL || mDeviceDriver->getType() == AE::Graphics::Device::DT_GL_30)
					mWinGlContext = wglGetCurrentContext();
	#endif
			}

			ContextAllegro::~ContextAllegro()
			{
				al_destroy_display(mAllegroDisplay);
			}

			/*AE::uint DeviceContextAllegro::createDrawingContext(AE::Graphics::SurfaceFormat surfaceFormat)
			{
				return 0;
			}*/

			bool ContextAllegro::BeginRendering()
			{
				al_set_target_backbuffer(mAllegroDisplay);
				return true;
			}

			bool ContextAllegro::BeginRendering(const AE::Graphics::Color &clearColor)
			{
				al_set_target_backbuffer(mAllegroDisplay);
				al_clear_to_color(al_map_rgb(clearColor.R, clearColor.G, clearColor.B));
				return true;
			}

			AE::Graphics::Surface* ContextAllegro::CreateOffscreenSurface(AE::Math::Vector2 &dimensions, AE::Graphics::SurfaceFormat surfaceFormat, bool usesVideoMemory)
			{
				if(usesVideoMemory)
				{
					al_set_target_backbuffer(mAllegroDisplay);
					al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
				}
				else
					al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);

				ALLEGRO_BITMAP *allegroSurface = al_create_bitmap(static_cast<int>(dimensions.x()), static_cast<int>(dimensions.y()));
				//AE::Graphics::Surface *newSurface = new AE::Graphics::Device::ColorBufferAllegro(allegroSurface);

				//return newSurface;
				return nullptr;
			}

			void ContextAllegro::EndRendering()
			{
				al_flip_display();
			}

			void ContextAllegro::Render()
			{
			}
		}
	}
}