#include "../../../headers/Objects/2D/triangle.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace LearnOpenGL
{
	Triangle::Triangle()
	{
		generateObject();
	}

	Triangle::~Triangle()
	{
	
	}

	float* Triangle::getVertices()
	{
		return vertices;
	}

	void Triangle::generateObject()
	{
		//Vertex Buffer Object
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	}

	void Triangle::selectObject()
	{
		//Vertex Buffer Object
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	}
}