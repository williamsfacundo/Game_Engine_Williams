#ifndef PROGRAM_H
#define PROGRAM_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../headers/initial_configurations.h"
#include "../../enumerators/status_corroboration_enum.h"
#include "../headers/window.h"
#include "../headers/shaders_manager.h"
#include "../headers/Objects/2D/triangle.h"

namespace LearnOpenGL
{
	class Program
	{
	private:
		const int CloseWindowKey = GLFW_KEY_ESCAPE;

		InitialConfigurations* initialConfigs;

		Window* window;

		ShaderManager* shaderManager;

		Triangle* triangle;

		StatusCorroborationEnum initialize();
		
		void renderingExecution();

		void clearScreenCommands();

		void frameInput();

		void renderCommands();

		void renderLoop();

		void freeResourcesAtEnd();

	public:
		Program();
		~Program();

		void programExecution();
	};
}

#endif