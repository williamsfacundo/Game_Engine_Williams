#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../../headers/shader_program.h"

namespace LearnOpenGL
{
	class Triangle
	{
	private:
		ShaderProgram* _shaderProgram;

		unsigned int VBO;

		unsigned int VAO;

		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		float* getVertices();

		void generateObject();

	public:
		Triangle(ShaderProgram* shaderProgram);
		~Triangle();

		void drawObject();
	};
}

#endif