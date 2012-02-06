#include "Tracks.h"
#include <GL\glut.h>

Tracks::Tracks(void)
{
}


Tracks::~Tracks(void)
{
}

void Tracks::draw(void)
{
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.0f, 0.0f, -1.0f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(-1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.0f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, -0.15f, 0.5f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.25f, 0.0f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.0f);
	glVertex3f(0.25f, -0.15f, 0.5f);
	glVertex3f(0.25f, 0.0f, 0.5f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.0f);
	glVertex3f(-0.25f, -0.15f, 0.5f);
	glVertex3f(-0.25f, 0.0f, 0.5f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.5f, 0.15f, 0.5f);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//front
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, 0.0f, -0.25f);
	glVertex3f(0.5f, 0.0f, -0.25f);
	glVertex3f(0.5f, -0.15f, -0.25f);
	glVertex3f(-0.5f, -0.15f, -0.25f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, 0.0f, 0.75f);
	glVertex3f(0.5f, 0.0f, 0.75f);
	glVertex3f(0.5f, -0.15f, 0.75f);
	glVertex3f(-0.5f, -0.15f, 0.75f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, -0.25f);
	glVertex3f(0.5f, 0.0f, -0.25f);
	glVertex3f(0.5f, 0.0f, 0.75f);
	glVertex3f(-0.5f, 0.0f, 0.75f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.15f, -0.25f);
	glVertex3f(0.5f, -0.15f, -0.25f);
	glVertex3f(0.5f, -0.15f, 0.75f);
	glVertex3f(-0.5f, -0.15f, 0.75f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.5f, 0.0f, -0.25f);
	glVertex3f(0.5f, -0.15f, -0.25f);
	glVertex3f(0.5f, -0.15f, 0.75f);
	glVertex3f(0.5f, 0.0f, 0.75f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, 0.0f, -0.25f);
	glVertex3f(-0.5f, -0.15f, -0.25f);
	glVertex3f(-0.5f, -0.15f, 0.75f);
	glVertex3f(-0.5f, 0.0f, 0.75f);

	glEnd(); //End quadrilateral coordinates

	//4
	glBegin(GL_QUADS);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.1f, 0.01f, 0.1f);
	glVertex3f(-0.1f, 0.01f, 0.2f);
	glVertex3f(0.1f, 0.01f, 0.2f);
	glVertex3f(0.1f, 0.01f, 0.1f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.0f, 0.01f, -0.15f);
	glVertex3f(-0.0f, 0.01f, 0.5f);
	glVertex3f(0.1f, 0.01f, 0.5f);
	glVertex3f(0.1f, 0.01f, -0.15f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.01f, -0.15f);
	glVertex3f(-0.25f, 0.01f, 0.2f);
	glVertex3f(-0.1f, 0.01f, 0.2f);
	glVertex3f(-0.1f, 0.01f, -0.15f);

	glEnd();
}