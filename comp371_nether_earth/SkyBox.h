//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Skybox header. This class draws the skybox.

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

