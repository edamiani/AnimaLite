#include "Pipeline.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			Pipeline::Pipeline()
			{
				mDefaultVertexShader = new Shader(ST_VERTEX, 
					"#version 140\n\
					in vec2 LVertexPos2D;\n\
					void main()\n\
					{\n\
						gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 );\n\
					}");

				mDefaultFragmentShader = new Shader(ST_FRAGMENT, 
					"#version 140\n\
					out vec4 LFragment;\n\
					void main()\n\
					{ \n\
						LFragment = vec4( 1.0, 1.0, 1.0, 1.0 );\n\
					}");
			}

			Pipeline::~Pipeline()
			{

			}
		}
	}
}
