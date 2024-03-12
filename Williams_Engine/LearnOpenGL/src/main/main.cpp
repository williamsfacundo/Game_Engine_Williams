#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../clases/headers/initial_configurations.h"
#include "../enumerators/status_corroboration_enum.h"

using namespace std;
using namespace LearnOpenGL;

int main()
{
	InitialConfigurations* initialConfigs = new InitialConfigurations();	

	if (initialConfigs->initializeNeccessaryData() == StatusCorroborationEnum::FAILED)
	{
		return -1;
	}

	const int windowHeight = 800;

	const int windowWidth = 600;

	const char* windowTitle = "LearnOpenGL";

	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		
		glfwTerminate();
		
		delete initialConfigs;

		return -1;
	}

	glfwMakeContextCurrent(window);

	if (initialConfigs->initializeGLAD() == StatusCorroborationEnum::FAILED)
	{
		delete initialConfigs;

		return -1;
	}

	delete initialConfigs;

	return 0;
}