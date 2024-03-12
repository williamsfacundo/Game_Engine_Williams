#ifndef INITIAL_CONFIG
#define INITIAL_CONFIG

namespace LearnOpenGL
{
	class InitialConfig
	{
	private:
		const int OpenGLMinorVersion = 3;
		const int OpenGLMajorVersion = 3;

		int createAndSetContext();

	public:
		InitialConfig();
		~InitialConfig();
	};
}

#endif