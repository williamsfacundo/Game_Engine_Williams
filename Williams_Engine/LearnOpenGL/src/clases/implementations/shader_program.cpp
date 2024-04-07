#include "../headers/shader_program.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../enumerators/status_corroboration_enum.h"

using namespace std;

namespace LearnOpenGL
{
	ShaderProgram::ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
	{		
		createShaderProgram(vertexShaderPath, fragmentShaderPath);
	}

	ShaderProgram::~ShaderProgram()
	{

	}

	void ShaderProgram::useShader()
	{

	}

	StatusCorroborationEnum ShaderProgram::getSourceCodeFromFilePath(const char* shaderFilePath, const char* &resultingShaderCode)
	{
		string code;

		ifstream shaderFile;

		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			// open files
			shaderFile.open(shaderFilePath);
			
			stringstream shaderStream;
			
			// read file’s buffer contents into streams
			shaderStream << shaderFile.rdbuf();
			
			// close file handlers
			shaderFile.close();
			
			// convert stream into string
			code = shaderStream.str();			
		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;

			return StatusCorroborationEnum::FAILED;
		}

		resultingShaderCode = code.c_str();
		
		return StatusCorroborationEnum::SUCCEDED;
	}

	void ShaderProgram::shaderCompilation(unsigned int& shaderID, ShaderTypeEnum shaderType, const char* shaderSourceCode)
	{	
		int success;
		
		char infoLog[512];

		switch (shaderType)
		{
		case LearnOpenGL::ShaderTypeEnum::VERTEX_SHADER:

			shaderID = glCreateShader(GL_VERTEX_SHADER);

			break;
		case LearnOpenGL::ShaderTypeEnum::FRAGMENT_SHADER:
			
			shaderID = glCreateShader(GL_FRAGMENT_SHADER);
			
			break;
		default:
			break;
		}
				
		glShaderSource(shaderID, 1, &shaderSourceCode, NULL);
		
		glCompileShader(shaderID);
		
		// print compile errors if any
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		
		if (!success)
		{
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			
			cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
		};
	}

	void ShaderProgram::createShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
	{
		//Get shaders source code
		const char* vertexShaderCode;
		const char* fragmentShaderCode;

		getSourceCodeFromFilePath(vertexShaderPath, vertexShaderCode);

		getSourceCodeFromFilePath(fragmentShaderPath, fragmentShaderCode);

		//Shaders compilation

		unsigned int vertexShaderID;
		unsigned int fragmentShaderID;

		shaderCompilation(vertexShaderID, ShaderTypeEnum::VERTEX_SHADER, vertexShaderCode);
		shaderCompilation(fragmentShaderID, ShaderTypeEnum::FRAGMENT_SHADER, fragmentShaderCode);
		
		//Shaders linking into program

		int success;

		char infoLog[512];

		programID = glCreateProgram();

		glAttachShader(programID, vertexShaderID);
		
		glAttachShader(programID, fragmentShaderID);
		
		glLinkProgram(programID);

		// print linking errors if any
		glGetProgramiv(programID, GL_LINK_STATUS, &success);
		
		if (!success)
		{
			glGetProgramInfoLog(programID, 512, NULL, infoLog);
			
			cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
		}

		glDeleteShader(vertexShaderID);

		glDeleteShader(fragmentShaderID);
	}
}