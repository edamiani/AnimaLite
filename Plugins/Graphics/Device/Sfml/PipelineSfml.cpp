#include "PipelineSfml.h"

#include "ShaderSfml.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			PipelineSfml::PipelineSfml()
			{
				mDefaultVertexShader = new ShaderSfml(ST_VERTEX, 
					"#version 140\
					in vec2 LVertexPos2D;\
					void main()\
					{\
						gl_Position = vec4(LVertexPos2D.x, LVertexPos2D.y, 0, 1);\
					}");
				
				mDefaultFragmentShader = new ShaderSfml(ST_FRAGMENT, 
					"#version 140\
					out vec4 LFragment;\
					void main()\
					{\
						LFragment = vec4(1.0, 1.0, 1.0, 1.0);\
					}");

				mVertexShader = mDefaultVertexShader;
				mFragmentShader = mDefaultFragmentShader;
			}

			PipelineSfml::~PipelineSfml()
			{

			}
		}
	}
}
