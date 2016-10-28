#include "ShaderSfml.h"

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			ShaderSfml::ShaderSfml(ShaderType type, const std::string &shaderCode)
				: Shader(type, shaderCode)
			{
				switch(type)
				{
				case ST_FRAGMENT:
					mSfmlShader.loadFromMemory(shaderCode, sf::Shader::Fragment);
					break;
				case ST_GEOMETRY:
					mSfmlShader.loadFromMemory(shaderCode, sf::Shader::Geometry);
					break;
				case ST_VERTEX:
					mSfmlShader.loadFromMemory(shaderCode, sf::Shader::Vertex);
					break;
				}
			}

			ShaderSfml::~ShaderSfml()
			{

			}
		}
	}
}