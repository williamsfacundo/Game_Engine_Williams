#ifndef INPUT_UTILITIES_H
#define INPUT_UTILITIES_H

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace LearnOpenGL
{
	class InputUtilities
	{
	public:
		static void closeWindowOnKeyPress(GLFWwindow* window, int key);
	};
}

#endif