#ifndef __AE_GRAPHICS_DEVICE_COLOR_BUFFER__
#define __AE_GRAPHICS_DEVICE_COLOR_BUFFER__

#include "Anima/Graphics/ColorBufferDesc.h"

#include "Anima/Graphics/Enums.h"
#include "Anima/Math/Point2.h"

namespace AE
{
	namespace Graphics
	{
		class ColorBuffer
		{
		public:
			ColorBuffer(AE::Graphics::ColorBufferDesc const &colorBufferDesc) : 
				mColorFormat(colorBufferDesc.colorFormat), mData(colorBufferDesc.data),
				mDimensions(colorBufferDesc.dimensions), mUsage(colorBufferDesc.usage) {}

			virtual ~ColorBuffer() 
			{
				if(mData)
					delete mData;
			}

			virtual void*	getData() = 0;
			AE::Math::Point2<AE::int32>	
							getDimensions() { return mDimensions; }

			virtual void	blit(AE::Graphics::ColorBuffer *sourceColorBuffer, const AE::Math::Point2<AE::uint> &dimensions, const AE::Math::Point2<AE::uint> &position) = 0;
			virtual void*	lock(AE::Graphics::LockType lockType) = 0;
			virtual void	plot(const AE::Graphics::Color &color, const AE::Math::Point2<AE::uint> &position) = 0;
			virtual void	unlock() = 0;

			struct PixelFormat
			{
				AE::uint8 colorDepth;
				AE::int8 redShift;
				AE::int8 greenShift;
				AE::int8 blueShift;
				AE::int8 alphaShift;
			};

		protected:
			AE::Graphics::BufferType			mBufferType;
			AE::Graphics::ColorFormat			mColorFormat;
			void								*mData;
			AE::Math::Point2<AE::int32>			mDimensions;
			PixelFormat							mPixelFormat;
			AE::Graphics::SurfaceFormat			mSurfaceFormat;
			AE::Graphics::Device::BufferUsage	mUsage;
		};
	}
}

#endif