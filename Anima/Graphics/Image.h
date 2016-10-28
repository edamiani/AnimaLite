#ifndef __ANIMA_GRAPHICS_IMAGE__
#define __ANIMA_GRAPHICS_IMAGE__

#include "Anima/Graphics/ColorBuffer.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Graphics/ImageDesc.h"
#include "Anima/Graphics/Enums.h"
#include "Anima/Math/Vector2.h"
#include "Anima/Types.h"

#include <string>

namespace AE
{
	namespace Graphics
	{
		class Image
		{
		protected:
			AE::Math::Vector2			mDimensions;
			std::string					mFile;
			AE::Graphics::ImageType		mImageType;

		public:
			Image(const std::string &filename) :
				mFile(filename) {}

			Image(AE::Math::Vector2 &dimensions) :
				mDimensions(dimensions) {}
			
			virtual ~Image() 
			{
			}
		};
	}
}

#endif