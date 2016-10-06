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

				void				blit(AE::Graphics::ColorBuffer *sourceColorBuffer, const AE::Math::Point2<AE::uint> &dimensions, const AE::Math::Point2<AE::uint> &position);
				void				clear(const AE::Graphics::Color &backgroundColor);
				void*				getData();
				AE::Math::Point2<AE::uint>	getDimensions();
				void*				lock(AE::Graphics::LockType lockType);
				void				plot(const AE::Graphics::Color &color, const AE::Math::Point2<AE::uint> &position);
				void				unlock();

				ALLEGRO_BITMAP*		_getAllegroBitmap() { return mAllegroBitmap; }

			protected:
				ALLEGRO_BITMAP		*mAllegroBitmap;
				AE::uint32			mPitch;
			};
		}
	}
}

#endif