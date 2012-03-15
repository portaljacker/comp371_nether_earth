#pragma once
#include "ImageLoader.h"
#include <GL\glut.h>

class SkyBox
{
private:
	GLuint tex1;
	GLuint tex2;
	GLuint tex3;
	GLuint tex4;
	GLuint tex5;

	Image* im;

	GLuint loadTexture(Image* image);

public:
	SkyBox(void);
	~SkyBox(void);

	void draw();
};

