#ifndef INITIAL_CONFIGURATIONS
#define INITIAL_CONFIGURATIONS

#include "../../enumerators/status_corroboration_enum.h"

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

		const int GLViewportWidth = 800;
		const int GLViewportHeight = 600;

		void configurateOpenGLParameters();

		StatusCorroborationEnum initializeGLFW();

	public:
		InitialConfigurations();
		~InitialConfigurations();

		StatusCorroborationEnum initializeNeccessaryData();

		StatusCorroborationEnum initializeGLAD();

		void initialOpenGLRenderingWindowSize();

		void registerCallbackFuntions(GLFWwindow* window);
	};
}

#endif