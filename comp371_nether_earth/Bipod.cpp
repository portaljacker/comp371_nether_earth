//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 1
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Bipod implimentation file.

#include "Bipod.h"
#include <GL\glut.h>

Bipod::Bipod(void)
{
}


Bipod::~Bipod(void)
{
}

void Bipod::draw(void)
{
	//Add directed light
	GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {0.0f, 1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
	
	glBegin(GL_QUADS);

	glPushMatrix();
	
	glScalef(0.1, 0.1, 0.1);
	//Bottom face
	glColor3f(0.5f, 0.5f, 0.5f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 2.0f);
	glVertex3f(-0.5f, -0.5f, 2.0f);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	//Left face 2
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 2.0f);
	glVertex3f(-0.5f, -0.25f, 2.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	//Right face 2
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.5f, 2.0f);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.5f, 2.0f);
	glVertex3f(-0.5f, -0.5f, 2.0f);

	//Front Face 2
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 3.0f, -0.5f);
	glVertex3f(0.5f, 3.0f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	//Leg

	//Front 
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 3.0f, 0.5f);
	glVertex3f(-0.5f, 3.0f, 0.5f);

	//Right 
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 3.0f, -0.5f);
	glVertex3f(0.5f, 3.0f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 3.0f, 0.5f);
	glVertex3f(-0.5f, 3.0f, -0.5f);

	//Top face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.5f, 3.0f, -0.5f);
	glVertex3f(-0.5f, 3.0f, 0.5f);
	glVertex3f(0.5f, 3.0f, 0.5f);
	glVertex3f(0.5f, 3.0f, -0.5f);
	glEnd();

	glTranslatef(2.5f, 0.0f, 0.0f);

	glBegin(GL_QUADS);


	//Bottom face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 2.0f);
	glVertex3f(-0.5f, -0.5f, 2.0f);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	//Left face 2
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 2.0f);
	glVertex3f(-0.5f, -0.25f, 2.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	//Right face 2
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.5f, 2.0f);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.5f, 2.0f);
	glVertex3f(-0.5f, -0.5f, 2.0f);

	//Front Face 2
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, -0.25f, 2.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 3.0f, -0.5f);
	glVertex3f(0.5f, 3.0f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	//Leg

	//Front 
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 3.0f, 0.5f);
	glVertex3f(-0.5f, 3.0f, 0.5f);

	//Right 
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 3.0f, -0.5f);
	glVertex3f(0.5f, 3.0f, 0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 3.0f, 0.5f);
	glVertex3f(-0.5f, 3.0f, -0.5f);

	//Top face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.5f, 3.0f, -0.5f);
	glVertex3f(-0.5f, 3.0f, 0.5f);
	glVertex3f(0.5f, 3.0f, 0.5f);
	glVertex3f(0.5f, 3.0f, -0.5f);
	glEnd();

	glTranslatef(-1.25f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
	//Torso

	//Bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-2.5f, 3.0f, -2.0f);
	glVertex3f(-2.5f, 3.0f, 2.0f);
	glVertex3f(2.5f, 3.0f, 2.0f);
	glVertex3f(2.5f, 3.0f, -2.0f);

	//Top
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-2.5f, 3.5f, -2.0f);
	glVertex3f(-2.5f, 3.5f, 2.0f);
	glVertex3f(2.5f, 3.5f, 2.0f);
	glVertex3f(2.5f, 3.5f, -2.0f);

	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.5f, 3.0f, 2.0f);
	glVertex3f(2.5f, 3.0f, 2.0f);
	glVertex3f(2.5f, 3.5f, 2.0f);
	glVertex3f(-2.5f, 3.5f, 2.0f);

	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.5f, 3.0f, -2.0f);
	glVertex3f(2.5f, 3.5f, -2.0f);
	glVertex3f(2.5f, 3.5f, 2.0f);
	glVertex3f(2.5f, 3.0f, 2.0f);

	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-2.5f, 3.0f, -2.0f);
	glVertex3f(-2.5f, 3.0f, 2.0f);
	glVertex3f(-2.5f, 3.5f, 2.0f);
	glVertex3f(-2.5f, 3.5f, -2.0f);

	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-2.5f, 3.0f, -2.0f);
	glVertex3f(-2.5f, 3.5f, -2.0f);
	glVertex3f(2.5f, 3.5f, -2.0f);
	glVertex3f(2.5f, 3.0f, -2.0f);

	glEnd();

	//4
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.5f, 3.6f, -0.1f);
	glVertex3f(-0.5f, 3.6f, 0.1f);
	glVertex3f(0.25f, 3.6f, 0.1f);
	glVertex3f(0.25f, 3.6f, -0.1f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.0f, 3.6f, -0.5f);
	glVertex3f(-0.0f, 3.6f, 0.5f);
	glVertex3f(0.25f, 3.6f, 0.5f);
	glVertex3f(0.25f, 3.6f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-1.0f, 3.6f, -0.5f);
	glVertex3f(-1.0f, 3.6f, 0.1f);
	glVertex3f(-0.5f, 3.6f, 0.1f);
	glVertex3f(-0.5f, 3.6f, -0.5f);

	glEnd();

	glPopMatrix();

}