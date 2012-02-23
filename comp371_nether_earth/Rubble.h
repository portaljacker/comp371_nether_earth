//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Rubble class header. This class creates rubble to place on top of tiles.

#pragma once

#include <GL/glut.h>
#include <math.h>
class Rubble
{
public:
	void drawSmall();
	void drawMedium();
	void drawLarge();
	Rubble(void);
	~Rubble(void);
};

