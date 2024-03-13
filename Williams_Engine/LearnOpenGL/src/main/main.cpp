#include "../clases/headers/program.h"

using namespace LearnOpenGL;

int main()
{
	Program* program = new Program();

	program->programExecution();

	delete program;	

	return 0;
}