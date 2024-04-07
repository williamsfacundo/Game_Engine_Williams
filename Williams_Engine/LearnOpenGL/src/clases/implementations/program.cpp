#include "../headers/program.h"

#include <iostream>

#include "../headers/initial_configurations.h"
#include "../../enumerators/status_corroboration_enum.h"
#include "../headers/window.h"
#include "../headers/input_utilities.h"

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

	StatusCorroborationEnum Program::initialize()
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

		initialConfigs->registerCallbackFunctions(window->getWindow());

		initialConfigs->initialOpenGLRenderingWindowSize(window);

		initialConfigs->showMaxVertexAttributesAvailable();

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

	void Program::clearScreenCommands()
	{
		glClearColor(
			window->getClearScreenColor().r, 
			window->getClearScreenColor().g, 
			window->getClearScreenColor().b, 
			window->getClearScreenColor().a);
		
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Program::frameInput()
	{
		InputUtilities::closeWindowOnKeyPress(window->getWindow(), CloseWindowKey);
	}

	void Program::renderCommands()
	{

	}

	void Program::renderLoop()
	{
		while (!glfwWindowShouldClose(window->getWindow()))
		{
			clearScreenCommands();

			frameInput();

			renderCommands();

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
			renderingExecution();
		}
	}
}