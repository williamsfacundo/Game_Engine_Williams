#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../enumerators/status_corroboration_enum.h"
#include "../../struct/color_struct.h"

namespace LearnOpenGL
{
	class Window
	{
	private:
		const int WindowHeight = 800;

		const int WindowWidth = 600;

		const char* WindowTitle = "LearnOpenGL";

		const MyColor clearScreenColor = MyColor(0.2f, 0.3f, 0.3f, 1.0f);

		GLFWwindow* window;

	public:
		Window();
		~Window();

		StatusCorroborationEnum createWindow();

		GLFWwindow* getWindow();
		
		int getHeight();

		int getWidth();

		MyColor getClearScreenColor();
	};
}

#endif