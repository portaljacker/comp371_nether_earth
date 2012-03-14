//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the phaser class specification

#include "Enumerations.h"
#include "imageloader.h"
#include <GL/glut.h>
#include <math.h>

#pragma once

class Phaser
{
public:

	Phaser(void);
	~Phaser(void);
	void draw(Shade shade, GLuint);
	
};
