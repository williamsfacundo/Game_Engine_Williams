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
		glUseProgram(programID);
	}

	StatusCorroborationEnum ShaderProgram::getSourceCodeFromFilePath(const char* shaderFilePath, string &resultingShaderCode)
	{
		ifstream shaderFile;

		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			// open files
			shaderFile.open(shaderFilePath);
			
			stringstream shaderStream;
			
			// read file�s buffer contents into streams
			shaderStream << shaderFile.rdbuf();
			
			// close file handlers
			shaderFile.close();
			
			// convert stream into string
			resultingShaderCode = shaderStream.str();
		}
		catch (ifstream::failure e)
		{
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;

			return StatusCorroborationEnum::FAILED;
		}		
		
		return StatusCorroborationEnum::SUCCEDED;
	}

	//Para no usar la logica del enum podemos usar directamente un unsigned int (y pasar  GL_VERTEX_SHADER o GL_FRAGMENT_SHADER)
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
		string vertexShaderstringSourceCode;
		string fragmentShaderstringSourceCode;

		//Get shaders source code		

		getSourceCodeFromFilePath(vertexShaderPath, vertexShaderstringSourceCode);

		getSourceCodeFromFilePath(fragmentShaderPath, fragmentShaderstringSourceCode);

		//When assining the pointer of the string if we delete the string var the reference is lost (be careful)
		const char* vertexShaderCode = vertexShaderstringSourceCode.c_str();
		const char* fragmentShaderCode = fragmentShaderstringSourceCode.c_str();

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