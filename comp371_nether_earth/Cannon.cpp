//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Cannon implementation file.

#include "Cannon.h"
#include <GL\glut.h>


Cannon::Cannon(void)
{
}


Cannon::~Cannon(void)
{
}

void Cannon::draw()
{
	//Add directed light
	GLfloat lightColor1[] = {0.85f, 0.85f, 0.85f, 1.0f}; 
	GLfloat lightPos1[] = {0.0f, 1.0f, -1.0f, 0.0f};
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT2, GL_POSITION, lightPos1);
	
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front
	glColor3f(0.0, 0.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.0, 0.5);
	
	//back
	//glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.0, -0.5);

	//bottom
	//glColor3f(1.0, 1.0, 0.0);
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glVertex3f(-0.5, 0.0, 0.5);

	//top
	//glColor3f(1.0, 1.0, 0.0);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//right
	//glColor3f(0.0, 1.0, 1.0);
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.0, -0.5);
	glVertex3f(0.5, 0.0, 0.5);

	//left
	//glColor3f(0.0, 1.0, 1.0);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.0, -0.5);
	glVertex3f(-0.5, 0.0, 0.5);

	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glBegin(GL_QUADS);
	
	//front
	//glColor3f(0.5, 0.5, 0.5);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.05, 0.15, 0.75);
	glVertex3f(0.05, 0.25, 0.75);
	glVertex3f(-0.05, 0.25, 0.75);
	glVertex3f(-0.05, 0.15, 0.75);
	
	//back
	//glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.05, 0.15, 0.5);
	glVertex3f(0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.15, 0.5);

	//bottom
	//glColor3f(1.0, 1.0, 0.0);
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(0.05, 0.15, 0.75);
	glVertex3f(0.05, 0.15, 0.5);
	glVertex3f(-0.05, 0.15, 0.5);
	glVertex3f(-0.05, 0.15, 0.75);

	//top
	//glColor3f(1.0, 1.0, 0.0);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(0.05, 0.25, 0.75);
	glVertex3f(0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.25, 0.75);

	//right
	//glColor3f(0.0, 1.0, 1.0);
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(0.05, 0.25, 0.75);
	glVertex3f(0.05, 0.25, 0.5);
	glVertex3f(0.05, 0.15, 0.5);
	glVertex3f(0.05, 0.15, 0.75);

	//left
	//glColor3f(0.0, 1.0, 1.0);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-0.05, 0.25, 0.75);
	glVertex3f(-0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.15, 0.5);
	glVertex3f(-0.05, 0.15, 0.75);
	glEnd();

	glTranslatef(-0.35, 0.0, 0.0);
	glBegin(GL_QUADS);
	
	//front
	//glColor3f(0.5, 0.5, 0.5);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.05, 0.15, 0.75);
	glVertex3f(0.05, 0.25, 0.75);
	glVertex3f(-0.05, 0.25, 0.75);
	glVertex3f(-0.05, 0.15, 0.75);
	
	//back
	//glColor3f(1.0, 0.0, 0.0);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.05, 0.15, 0.5);
	glVertex3f(0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.15, 0.5);

	//bottom
	//glColor3f(1.0, 1.0, 0.0);
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(0.05, 0.15, 0.75);
	glVertex3f(0.05, 0.15, 0.5);
	glVertex3f(-0.05, 0.15, 0.5);
	glVertex3f(-0.05, 0.15, 0.75);

	//top
	//glColor3f(1.0, 1.0, 0.0);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(0.05, 0.25, 0.75);
	glVertex3f(0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.25, 0.75);

	//right
	//glColor3f(0.0, 1.0, 1.0);
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(0.05, 0.25, 0.75);
	glVertex3f(0.05, 0.25, 0.5);
	glVertex3f(0.05, 0.15, 0.5);
	glVertex3f(0.05, 0.15, 0.75);

	//left
	//glColor3f(0.0, 1.0, 1.0);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-0.05, 0.25, 0.75);
	glVertex3f(-0.05, 0.25, 0.5);
	glVertex3f(-0.05, 0.15, 0.5);
	glVertex3f(-0.05, 0.15, 0.75);

	glEnd();
	glEnd();


	//4
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.1f, 0.51f, 0.1f);
	glVertex3f(-0.1f, 0.51f, 0.2f);
	glVertex3f(0.1f, 0.51f, 0.2f);
	glVertex3f(0.1f, 0.51f, 0.1f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.0f, 0.51f, -0.15f);
	glVertex3f(-0.0f, 0.51f, 0.35f);
	glVertex3f(0.1f, 0.51f, 0.35f);
	glVertex3f(0.1f, 0.51f, -0.15f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.51f, -0.15f);
	glVertex3f(-0.25f, 0.51f, 0.2f);
	glVertex3f(-0.1f, 0.51f, 0.2f);
	glVertex3f(-0.1f, 0.51f, -0.15f);

	glEnd();
}
