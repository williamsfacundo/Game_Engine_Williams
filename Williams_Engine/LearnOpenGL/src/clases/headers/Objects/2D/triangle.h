#ifndef TRIANGLE_H
#define TRIANGLE_H

namespace LearnOpenGL
{
	class Triangle
	{
	private:
		unsigned int VBO;

		float vertices[9] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

	public:
		Triangle();
		~Triangle();

		float* getVertices();

		void generateObject();

		void selectObject();
	};
}

#endif