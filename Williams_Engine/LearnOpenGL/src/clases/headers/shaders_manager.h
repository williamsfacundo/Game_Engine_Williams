#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "shader_program.h"

namespace LearnOpenGL
{
	//Hacer un enum tipo shader program enum
	class ShaderManager
	{
	private:
		const char* VSFilePath = "shaders/shader.vs";
		const char* FSFilePath = "shaders/shader.fs";

		ShaderProgram* _shaderProgram;

	public:
		ShaderManager();
		~ShaderManager();

		ShaderProgram* getShader();
	};
}

#endif