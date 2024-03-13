#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../enumerators/status_corroboration_enum.h"

namespace LearnOpenGL
{
	class Window
	{
	private:
		const int WindowHeight = 800;

		const int WindowWidth = 600;

		const char* WindowTitle = "LearnOpenGL";

		GLFWwindow* window;

	public:
		Window();
		~Window();

		StatusCorroborationEnum createWindow();

		GLFWwindow* getWindow();
	};
}

#endif