#ifndef CALLBACK_FUNCTIONS
#define CALLBACK_FUNCTIONS

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

//Register callback functions after we create the window and before the render loop initiated

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif