//Comp371_w12 PA1
//Prof. S. Mokhov
//Team 4
//Jordan V. 
//Taras K. 6901204
//Gianni T.
//Sebastien S.
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

