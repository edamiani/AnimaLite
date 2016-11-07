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

				Shader* GetDefaultFragmentShader() { return mDefaultFragmentShader; }
				Shader* GetDefaultVertexShader() { return mDefaultVertexShader; }

				void SetFragmentShader(Shader *fragmentShader) 
				{ 
					assert(fragmentShader->GetType() == AE::Graphics::Device::ST_FRAGMENT);
					mFragmentShader = fragmentShader;
				}

				void SetVertexShader(Shader *vertexShader)
				{
					assert(vertexShader->GetType() == AE::Graphics::Device::ST_VERTEX);
					mFragmentShader = vertexShader;
				}
			};
		}
	}
}

#endif
