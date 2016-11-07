#ifndef __ANIMA_GRAPHICS_SURFACE_ALLEGRO__
#define __ANIMA_GRAPHICS_SURFACE_ALLEGRO__

#include "Anima/Graphics/ColorBuffer.h"
#include "Anima/Math/Vector2.h"

#include "allegro5/allegro.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class ColorBufferAllegro : public AE::Graphics::ColorBuffer
			{
			public:
				ColorBufferAllegro(AE::Graphics::ColorBufferDesc const &colorBufferDesc);
				~ColorBufferAllegro();

				void				Blit(AE::Graphics::ColorBuffer *sourceColorBuffer, const AE::Math::Point2<AE::uint> &dimensions, const AE::Math::Point2<AE::uint> &position);
				void				Clear(const AE::Graphics::Color &backgroundColor);
				void*				GetData();
				AE::Math::Point2<AE::uint>	getDimensions();
				void*				Lock(AE::Graphics::LockType lockType);
				void				Plot(const AE::Graphics::Color &color, const AE::Math::Point2<AE::uint> &position);
				void				Unlock();

				ALLEGRO_BITMAP*		_GetAllegroBitmap() { return mAllegroBitmap; }

			protected:
				ALLEGRO_BITMAP		*mAllegroBitmap;
				AE::uint32			mPitch;
			};
		}
	}
}

#endif