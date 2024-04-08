#include "../headers/shaders_manager.h"

namespace LearnOpenGL
{
	ShaderManager::ShaderManager()
	{
		_shaderProgram = new ShaderProgram(VSFilePath, FSFilePath);
	}

	ShaderManager::~ShaderManager()
	{

	}

	ShaderProgram* ShaderManager::getShader()
	{
		return _shaderProgram;
	}
}