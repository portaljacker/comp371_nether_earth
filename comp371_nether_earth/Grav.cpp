//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 1
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the grav implementation file.

#include "Grav.h"
#include <GL\glut.h>

Grav::Grav(void)
{
}


Grav::~Grav(void)
{
}

void Grav::draw(void)
{
	//Add directed light
	GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {0.0f, 1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
	
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//top
	glColor3f(0.5f, 0.5f, 0.5f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//right 1
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, 0.0f, 0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//right 2
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);

	//right 3
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//left 1
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//left 2
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//left 3
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);


	glEnd(); //End quadrilateral coordinates

	glTranslatef(-1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//top
	glColor3f(0.5f, 0.5f, 0.5f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//right 1
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, 0.0f, 0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//right 2
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);

	//right 3
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//left 1
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//left 2
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//left 3
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.5f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	//bottom
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.01f, 0.45f);
	glVertex3f(-0.65f, 0.01f, 0.45f);

	//top                    
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-0.65f, 0.11f, -0.45f);
	glVertex3f(0.65f, 0.11f, -0.45f);
	glVertex3f(0.65f, 0.11f, 0.45f);
	glVertex3f(-0.65f, 0.11f, 0.45f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glVertex3f(-0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.11f, -0.45f);
	glVertex3f(-0.65f, 0.11f, -0.45f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glVertex3f(-0.65f, 0.0f, 0.45f);
	glVertex3f(0.65f, 0.0f, 0.45f);
	glVertex3f(0.65f, 0.11f, 0.45f);
	glVertex3f(-0.65f, 0.11f, 0.45f);

	//right
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glVertex3f(0.65f, 0.11f, -0.45f);
	glVertex3f(0.65f, 0.11f, 0.45f);
	glVertex3f(0.65f, 0.01f, 0.45f);
	glVertex3f(0.65f, 0.01f, -0.45f);

	//left
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.65f, 0.11f, -0.45f);
	glVertex3f(-0.65f, 0.11f, 0.45f);
	glVertex3f(-0.65f, 0.01f, 0.45f);
	glVertex3f(-0.65f, 0.01f, -0.45f);

	glEnd();

	//4
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.1f, 0.12f, 0.1f);
	glVertex3f(-0.1f, 0.12f, 0.2f);
	glVertex3f(0.1f, 0.12f, 0.2f);
	glVertex3f(0.1f, 0.12f, 0.1f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.0f, 0.12f, -0.15f);
	glVertex3f(-0.0f, 0.12f, 0.3f);
	glVertex3f(0.1f, 0.12f, 0.3f);
	glVertex3f(0.1f, 0.12f, -0.15f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.12f, -0.15f);
	glVertex3f(-0.25f, 0.12f, 0.2f);
	glVertex3f(-0.1f, 0.12f, 0.2f);
	glVertex3f(-0.1f, 0.12f, -0.15f);

	glEnd();
}