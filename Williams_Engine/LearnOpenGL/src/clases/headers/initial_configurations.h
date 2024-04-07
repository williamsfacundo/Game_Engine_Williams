#ifndef INITIAL_CONFIGURATIONS
#define INITIAL_CONFIGURATIONS

#include "../../enumerators/status_corroboration_enum.h"
#include "../../clases/headers/window.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace LearnOpenGL
{
	class InitialConfigurations
	{
	private:
		const int OpenGLMinorVersion = 3;
		const int OpenGLMajorVersion = 3;		

		void configurateOpenGLParameters();

		StatusCorroborationEnum initializeGLFW();

	public:
		InitialConfigurations();
		~InitialConfigurations();

		StatusCorroborationEnum initializeNeccessaryData();

		StatusCorroborationEnum initializeGLAD();

		void initialOpenGLRenderingWindowSize(Window* programWindow);

		void registerCallbackFunctions(GLFWwindow* window);
	};
}

#endif