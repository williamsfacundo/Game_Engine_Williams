#ifndef PROGRAM_H
#define PROGRAM_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../headers/initial_configurations.h"
#include "../../enumerators/status_corroboration_enum.h"
#include "../headers/window.h"

namespace LearnOpenGL
{
	class Program
	{
	private:
		InitialConfigurations* initialConfigs;

		Window* window;	

		StatusCorroborationEnum initialize();
		
		void renderingExecution();

		void renderLoop();

		void freeResourcesAtEnd();

	public:
		Program();
		~Program();

		void programExecution();
	};
}

#endif