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