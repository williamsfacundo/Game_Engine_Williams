#include "../headers/initial_config.h"

#include <iostream>

//For this project I downloaded glad for opengl version 3.3
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

namespace LearnOpenGL
{
	InitialConfig::InitialConfig()
	{		
		switch (createAndSetContext())
		{
		case 0:

			cout << "Something went wrong in the initialization!" << endl;

		case 1:

			cout << "Initialization was successful!";

		default:
			break;
		}
	}

	InitialConfig::~InitialConfig()
	{

	}

	int InitialConfig::createAndSetContext()
	{
		int initializationResult = glfwInit();

		//Set opengl version to 3.x
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OpenGLMinorVersion);

		//Set opengl version to x.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OpenGLMajorVersion);

		//Use only the modern opengl functions
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		return initializationResult;
	}
}