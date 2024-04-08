#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include <string>

#include "../../enumerators/status_corroboration_enum.h"
#include "../../enumerators/shader_type_enum.h"

using namespace std;

namespace LearnOpenGL
{
	class ShaderProgram
	{
	private:
		unsigned int programID;

		StatusCorroborationEnum getSourceCodeFromFilePath(const char* shaderFilePath, string &resultingShaderCode);

		void shaderCompilation(unsigned int& shaderID, ShaderTypeEnum shaderType, const char* shaderSourceCode);

		void createShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);		

	public:
		ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
		~ShaderProgram();

		void useShader();
	};
}

#endif