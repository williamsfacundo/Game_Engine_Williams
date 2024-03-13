#include "../headers/input_utilities.h"

namespace LearnOpenGL
{
	void InputUtilities::closeWindowOnKeyPress(GLFWwindow* window, int key)
	{	
		if (glfwGetKey(window, key) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
}