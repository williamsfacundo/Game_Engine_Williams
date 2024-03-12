#include "../headers/initial_configurations.h"

#include <iostream>

//For this project I downloaded glad for opengl version 3.3
//Web GLAD: https://glad.dav1d.de/
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../enumerators/status_corroboration_enum.h"

using namespace std;

namespace LearnOpenGL
{
	InitialConfigurations::InitialConfigurations()
	{		
		
	}

	InitialConfigurations::~InitialConfigurations()
	{

	}

	void InitialConfigurations::configurateOpenGLParameters()
	{
		//Set opengl version to 3.x
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OpenGLMinorVersion);

		//Set opengl version to x.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OpenGLMajorVersion);

		//Use only the modern opengl functions
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	StatusCorroborationEnum InitialConfigurations::initializeGLFW()
	{
		int initializationResult = glfwInit();		

		return static_cast<StatusCorroborationEnum>(initializationResult);
	}

	StatusCorroborationEnum InitialConfigurations::initializeNeccessaryData()
	{
		StatusCorroborationEnum initializationResult = initializeGLFW();

		switch (initializationResult)
		{
		case StatusCorroborationEnum::FAILED:

			cout << "Something went wrong in the initialization of GLFW!" << endl;

		case StatusCorroborationEnum::SUCCEDED:

			cout << "GLFW initialization was done successfully!" << endl;

			configurateOpenGLParameters();

		default:
			break;
		}

		return initializationResult;
	}

	StatusCorroborationEnum InitialConfigurations::initializeGLAD()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			cout << "Something went wrong in the initialization of GLAD!" << endl;

			return StatusCorroborationEnum::FAILED;
		}
		else
		{
			cout << "GLAD initialization was done successfully!" << endl;

			return StatusCorroborationEnum::SUCCEDED;
		}
	}
}