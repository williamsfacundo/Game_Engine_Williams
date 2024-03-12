#ifndef INITIAL_CONFIGURATIONS
#define INITIAL_CONFIGURATIONS

#include "../../enumerators/status_corroboration_enum.h"

namespace LearnOpenGL
{
	class InitialConfigurations
	{
	private:
		const int OpenGLMinorVersion = 3;
		const int OpenGLMajorVersion = 3;

		void configurateOpenGLParameters();

		StatusCorroborationEnum initializeGLFW();

	public:
		InitialConfigurations();
		~InitialConfigurations();

		StatusCorroborationEnum initializeNeccessaryData();

		StatusCorroborationEnum initializeGLAD();
	};
}

#endif