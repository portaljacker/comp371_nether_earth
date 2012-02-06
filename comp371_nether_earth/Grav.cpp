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
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//top
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//right 1
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, 0.0f, 0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//right 2
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);

	//right 3
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//left 1
	//glColor3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//left 2
	//glColor3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//left 3
	//glColor3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);


	glEnd(); //End quadrilateral coordinates

	glTranslatef(-1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//right 1
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, 0.0f, 0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//right 2
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, 0.25f);

	//right 3
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.25f, 0.0f, -0.5f);
	glVertex3f(0.25f, 0.0f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);
	glVertex3f(0.25f, -0.15f, -0.25f);

	//left 1
	//glColor3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);

	//left 2
	//glColor3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, 0.25f);

	//left 3
	//glColor3f(0.5f, 0.5f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.5f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);
	glVertex3f(-0.25f, -0.15f, -0.25f);


	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.5f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	//bottom
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.01f, 0.45f);
	glVertex3f(-0.65f, 0.01f, 0.45f);

	//top                    
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.65f, 0.11f, -0.45f);
	glVertex3f(0.65f, 0.11f, -0.45f);
	glVertex3f(0.65f, 0.11f, 0.45f);
	glVertex3f(-0.65f, 0.11f, 0.45f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.01f, -0.45f);
	glVertex3f(0.65f, 0.11f, -0.45f);
	glVertex3f(-0.65f, 0.11f, -0.45f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glVertex3f(-0.65f, 0.0f, 0.45f);
	glVertex3f(0.65f, 0.0f, 0.45f);
	glVertex3f(0.65f, 0.11f, 0.45f);
	glVertex3f(-0.65f, 0.11f, 0.45f);

	//right
	//glColor3f(1.0f, 0.5f, 0.5f);
	glVertex3f(0.65f, 0.11f, -0.45f);
	glVertex3f(0.65f, 0.11f, 0.45f);
	glVertex3f(0.65f, 0.01f, 0.45f);
	glVertex3f(0.65f, 0.01f, -0.45f);

	//left
	//glColor3f(1.0f, 0.5f, 0.5f);
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