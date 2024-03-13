#include "../headers/program.h"

#include <iostream>

#include "../headers/initial_configurations.h"
#include "../../enumerators/status_corroboration_enum.h"
#include "../headers/window.h"

using namespace std;

namespace LearnOpenGL
{
	Program::Program()
	{
		initialConfigs = nullptr;

		window = nullptr;		
	}

	Program::~Program()
	{
		if(initialConfigs != nullptr)
		{
			delete initialConfigs;
		}

		if(window != nullptr)
		{
			delete window;
		}
	}

	StatusCorroborationEnum  Program::initialize()
	{
		//Initialization phase 1
		InitialConfigurations* initialConfigs = new InitialConfigurations();

		if (initialConfigs->initializeNeccessaryData() == StatusCorroborationEnum::FAILED)
		{
			return StatusCorroborationEnum::FAILED;
		}

		//Initialization phase 2
		window = new Window();

		if (window->createWindow() == StatusCorroborationEnum::FAILED)
		{
			return StatusCorroborationEnum::FAILED;
		}

		//Initialization phase 3

		if (initialConfigs->initializeGLAD() == StatusCorroborationEnum::FAILED)
		{
			glfwTerminate();
			
			return StatusCorroborationEnum::FAILED;
		}

		initialConfigs->registerCallbackFuntions(window->getWindow());

		if (initialConfigs != nullptr)
		{
			delete initialConfigs;

			initialConfigs = nullptr;
		}		
	}

	void Program::renderingExecution()
	{
		renderLoop();

		freeResourcesAtEnd();
	}

	void Program::renderLoop()
	{
		while (!glfwWindowShouldClose(window->getWindow()))
		{
			glfwSwapBuffers(window->getWindow());

			glfwPollEvents();
		}
	}

	void Program::freeResourcesAtEnd()
	{
		glfwTerminate();
	}

	void Program::programExecution()
	{		
		if (initialize() == StatusCorroborationEnum::FAILED)
		{
			cout << "We are so sorry, program could not execute properly!" << endl;
		}
		else
		{
			window->getWindow();
			renderingExecution();
		}
	}
}