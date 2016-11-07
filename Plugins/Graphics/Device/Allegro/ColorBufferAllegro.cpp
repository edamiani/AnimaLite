#include "Plugins/Graphics/Device/Allegro/ColorBufferAllegro.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ColorBufferAllegro::ColorBufferAllegro(AE::Graphics::ColorBufferDesc const &colorBufferDesc)
				: ColorBuffer(colorBufferDesc)
			{
				mAllegroBitmap = al_create_bitmap(colorBufferDesc.dimensions.x, colorBufferDesc.dimensions.y);
				int pixelFormat = al_get_bitmap_format(mAllegroBitmap);

				switch(pixelFormat)
				{
				case ALLEGRO_PIXEL_FORMAT_ARGB_8888:
					mSurfaceFormat = SF_A8R8G8B8;
					mPixelFormat.colorDepth = 32;
					mPixelFormat.alphaShift = 24;
					mPixelFormat.redShift = 16;
					mPixelFormat.greenShift = 8;
					mPixelFormat.blueShift = 0;

					break;
				case ALLEGRO_PIXEL_FORMAT_XRGB_8888:
					mSurfaceFormat = SF_X8R8G8B8;
					mPixelFormat.colorDepth = 32;
					mPixelFormat.alphaShift = -1;
					mPixelFormat.redShift = 16;
					mPixelFormat.greenShift = 8;
					mPixelFormat.blueShift = 0;

					break;
				case ALLEGRO_PIXEL_FORMAT_ARGB_1555:
					mSurfaceFormat = SF_A1R5G5B5;
					mPixelFormat.colorDepth = 16;
					mPixelFormat.alphaShift = 15;
					mPixelFormat.redShift = 10;
					mPixelFormat.greenShift = 5;
					mPixelFormat.blueShift = 0;

					break;
					/*case ALLEGRO_PIXEL_FORMAT_XRGB_1555:
						mSurfaceFormat = SF_X1R5G5B5;
						mPixelFormat.colorDepth = 16;
						mPixelFormat.alphaShift = -1;
						mPixelFormat.redShift = 10;
						mPixelFormat.greenShift = 5;
						mPixelFormat.blueShift = 0;

						break;*/
				case ALLEGRO_PIXEL_FORMAT_RGB_565:
					mSurfaceFormat = SF_R5G6B5;
					mPixelFormat.colorDepth = 16;
					mPixelFormat.alphaShift = -1;
					mPixelFormat.redShift = 11;
					mPixelFormat.greenShift = 5;
					mPixelFormat.blueShift = 0;

					break;
				}
			}

			ColorBufferAllegro::~ColorBufferAllegro()
			{
			}

			void ColorBufferAllegro::Blit(AE::Graphics::ColorBuffer *sourceColorBuffer, const AE::Math::Point2<AE::uint> &dimensions, const AE::Math::Point2<AE::uint> &position)
			{
				al_set_target_bitmap(mAllegroBitmap);
				al_draw_bitmap_region(static_cast<AE::Graphics::Device::ColorBufferAllegro *>(sourceColorBuffer)->_GetAllegroBitmap(), 0, 0, dimensions.x, dimensions.y, position.x, position.y, 0);
			}

			void ColorBufferAllegro::Clear(const AE::Graphics::Color &backgroundColor)
			{
				al_set_target_bitmap(mAllegroBitmap);
				al_clear_to_color(al_map_rgb(backgroundColor.R, backgroundColor.G, backgroundColor.B));
			}

			void* ColorBufferAllegro::GetData()
			{
				return 0;
			}

			AE::Math::Point2<AE::uint> ColorBufferAllegro::getDimensions()
			{
				return AE::Math::Point2<AE::uint>(al_get_bitmap_width(mAllegroBitmap), al_get_bitmap_height(mAllegroBitmap));
			}

			void* ColorBufferAllegro::Lock(AE::Graphics::LockType lockType)
			{
				AE::uint allegroLockType;
				switch(lockType)
				{
				case AE::Graphics::LT_READONLY:
					allegroLockType = ALLEGRO_LOCK_READONLY;
					break;
				case AE::Graphics::LT_WRITEONLY:
					allegroLockType = ALLEGRO_LOCK_WRITEONLY;
					break;
				case AE::Graphics::LT_READWRITE:
				default:
					allegroLockType = ALLEGRO_LOCK_READWRITE;
					break;
				}

				ALLEGRO_LOCKED_REGION *lockedRegion = al_lock_bitmap(mAllegroBitmap, al_get_bitmap_format(mAllegroBitmap), allegroLockType);
				assert(lockedRegion);

				return lockedRegion;
			}

			void ColorBufferAllegro::Plot(const AE::Graphics::Color &color, const AE::Math::Point2<AE::uint> &position)
			{
				al_put_pixel(position.x, position.y, al_map_rgb(color.R, color.G, color.B));
			}

			void ColorBufferAllegro::Unlock()
			{
				al_unlock_bitmap(mAllegroBitmap);
			}
		}
	}
}