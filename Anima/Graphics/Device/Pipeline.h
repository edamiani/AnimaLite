#ifndef __AE_GRAPHICS_DEVICE_PIPELINE__
#define __AE_GRAPHICS_DEVICE_PIPELINE__

#include "FragmentShader.h"
#include "VertexShader.h"

#include <cassert>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class Pipeline
			{
			protected:
				Shader		*mDefaultFragmentShader;
				Shader		*mDefaultVertexShader;
				Shader		*mFragmentShader;
				Shader		*mVertexShader;

			public:
				Pipeline();
				~Pipeline();

				void setFragmentShader(Shader *fragmentShader) 
				{ 
					assert(fragmentShader->getType() == AE::Graphics::Device::ST_FRAGMENT);
					mFragmentShader = fragmentShader;
				}

				void setVertexShader(Shader *vertexShader)
				{
					assert(vertexShader->getType() == AE::Graphics::Device::ST_VERTEX);
					mFragmentShader = vertexShader;
				}
			};
		}
	}
}

#endif
