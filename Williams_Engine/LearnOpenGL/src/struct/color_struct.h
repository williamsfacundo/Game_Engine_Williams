#ifndef COLOR_STRUCT
#define COLOR_STRUCT

namespace LearnOpenGL
{
	struct MyColor
	{
		float r;
		float g;
		float b;
		float a;

		MyColor(float redValue, float greenValue, float blueValue, float alphaValue)
		{
			r = redValue;
			g = greenValue;
			b = blueValue;
			a = alphaValue;
		}
	};
}

#endif