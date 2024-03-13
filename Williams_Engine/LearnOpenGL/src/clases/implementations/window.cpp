#include "../headers/window.h"

#include "../../enumerators/status_corroboration_enum.h"

#include <iostream>

using namespace std;

namespace LearnOpenGL
{
	Window::Window()
	{
		window = nullptr;
	}

	Window::~Window()
	{

	}

	StatusCorroborationEnum Window::createWindow()
	{
		window = glfwCreateWindow(WindowWidth, WindowHeight, WindowTitle, NULL, NULL);
		
		if (window == NULL)
		{
			cout << "Something went wrong creating the window!" << endl;

			glfwTerminate();			

			return StatusCorroborationEnum::FAILED;
		}
		else
		{
			cout << "Window was created successfully!" << endl;
		}

		glfwMakeContextCurrent(window);

		return StatusCorroborationEnum::SUCCEDED;
	}

	GLFWwindow* Window::getWindow()
	{
		return window;
	}

	MyColor Window::getClearScreenColor()
	{
		return clearScreenColor;
	}
}
