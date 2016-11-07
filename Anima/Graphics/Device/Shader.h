#ifndef __AE_GRAPHICS_DEVICE_SHADER__
#define __AE_GRAPHICS_DEVICE_SHADER__

#include <string>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			enum ShaderType
			{
				ST_FRAGMENT,
				ST_GEOMETRY,
				ST_VERTEX
			};

			class Shader
			{
			private:
				std::string		mSourceCode;
				ShaderType		mType;

			public:
				Shader(ShaderType type, const std::string &shaderCode)
					: mType(type), mSourceCode(shaderCode) {  }
				virtual ~Shader() {}

				std::string&	GetSourceCode() { return mSourceCode; }
				ShaderType		GetType() { return mType; }
			};
		}
	}
}

#endif