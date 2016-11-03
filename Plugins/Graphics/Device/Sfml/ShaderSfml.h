#ifndef __AE_GRAPHICS_DEVICE_SHADER_SFML__
#define __AE_GRAPHICS_DEVICE_SHADER_SFML__

#include "Anima/Graphics/Device/Shader.h"

#include <string>

#include "SFML/Graphics.hpp"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class ShaderSfml : public Shader
			{
			private:
				sf::Shader mSfmlShader;

			public:
				ShaderSfml(ShaderType type, const std::string &shaderCode);
				~ShaderSfml();

				sf::Shader& getSfmlShader() { return mSfmlShader; }
			};
		}
	}
}

#endif