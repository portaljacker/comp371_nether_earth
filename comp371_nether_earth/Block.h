//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the block header.

#pragma once
#include "imageloader.h"
#include <GL/glut.h>
#include <math.h>

class Block
{

public:
	Block(void);
	~Block(void);

	void drawPH(GLuint);	//1
	void drawPU(GLuint);	//2
	void drawHH(GLuint, GLuint);	//3
	void drawHU(GLuint, GLuint);	//4

	void drawD(void);	//6

	void drawHQ(GLuint);	//@
	void drawF(GLuint);		//$
};

