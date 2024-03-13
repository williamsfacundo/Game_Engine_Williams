#include "../headers/input_utilities.h"

namespace LearnOpenGL
{
	void InputUtilities::closeWindowOnKeyPress(GLFWwindow* window, int key)
	{
		//GLFW_KEY_ESCAPE
		if (glfwGetKey(window, key) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
}