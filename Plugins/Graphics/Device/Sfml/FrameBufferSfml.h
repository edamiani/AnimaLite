#ifndef __AE_GRAPHICS_DEVICE_FRAME_BUFFER_GL15_SDL__
#define __AE_GRAPHICS_DEVICE_FRAME_BUFFER_GL15_SDL__

#include "Anima/Graphics/Device/FrameBuffer.h"

#include "Anima/Platform.h"
#include "Anima/Graphics/Device/GL15/GLHeaders.h"
#include "Anima/Graphics/Device/PixelBufferDesc.h"
#include "Anima/OS/Window.h"

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class ContextGL15;

			class FrameBufferGL15_Sdl : public AE::Graphics::Device::FrameBuffer
			{
			public:
				FrameBufferGL15_Sdl(AE::OS::Window &window, const AE::Graphics::Device::PixelBufferDesc &pixelBufferDesc);
				~FrameBufferGL15_Sdl();

				/***** Inherited from AE::Graphics::Device::PixelBuffer *****/
				void							blitFrom(AE::Graphics::ColorBuffer *source, AE::Math::Point2<AE::uint> srcOffset, AE::Math::Point2<AE::uint> srcDimensions, AE::Math::Point2<AE::int32> const &destPosition);
				void*							getData();
				void*							lock(AE::Graphics::LockType lockType);
				void							plot(const AE::uint32 color, const AE::Math::Point2<AE::int32> &position);
				void							plot32(const AE::uint32 color, const AE::Math::Point2<AE::int32> &position);
				void							unlock();

				/***** Inherited from AE::Graphics::ColorBuffer
				AE::Graphics::ColorFormat		getColorFormat();
				void*							getData();
				AE::Math::Point2&				getDimensions();
				AE::Math::Point2&				getRowOrder();
				*****/

			private:
				GLenum							mPixelFormatGL;
				GLenum							mTypeGL;

				SDL_Renderer					*mRenderer;

				friend	AE::Graphics::Device::ContextGL15;

				/***** Inherited from AE::Graphics::Device::PixelBuffer
				AE::Graphics::AllocationType	mAllocationType;
				AE::Graphics::Color				mColorKey;
				AE::Graphics::Device::PixelBufferType
												mPixelBufferType;
				bool							mUsesColorKey;
				*****/

				/***** Inherited from AE::Graphics::ColorBuffer
				AE::Graphics::ColorFormat		mColorFormat;
				void							*mData;
				AE::Math::Point2				mDimensions;
				AE::Graphics::RowOrder			mRowOrder;
				*****/
			};
		}
	}
}

#endif