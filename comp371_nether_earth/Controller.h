//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the controller header.

#include "Enumerations.h"
#include <GL/glut.h>

#pragma once
class Controller
{
public:
	Controller(void);
	~Controller(void);
	
	void draw(Shade shade, GLuint);
};

