#include "../../../headers/Objects/2D/triangle.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace LearnOpenGL
{
	Triangle::Triangle(ShaderProgram* shaderProgram)
	{
		generateObject();

		_shaderProgram = shaderProgram;
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
		glGenBuffers(1, &VBO);

		glGenVertexArrays(1, &VAO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		glEnableVertexAttribArray(0);

		glBindVertexArray(0);
	}

	void Triangle::drawObject()
	{
		_shaderProgram->useShader();
		
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}