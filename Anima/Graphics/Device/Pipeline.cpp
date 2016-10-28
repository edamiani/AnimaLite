#include "Pipeline.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			Pipeline::Pipeline()
			{
				mDefaultVertexShader = new Shader(ST_VERTEX, "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }");
				mDefaultFragmentShader = new Shader(ST_FRAGMENT, "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }");
			}

			Pipeline::~Pipeline()
			{

			}
		}
	}
}
