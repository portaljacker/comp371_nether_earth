//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Rubble class implimentation file.

#include "Rubble.h"


Rubble::Rubble(void)
{
}

void Rubble::drawSmall()
{  
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.2, 0.0, 0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.2, 0.0, -0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();
}

void Rubble::drawMedium()
{  
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.2, 0.0, 0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.2, 0.0, -0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.35, 0.0, -0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1f, 0.1f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.35, 0.0, 0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1f, 0.1f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.05, 0.0, 0.3);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1f, 0.1f, 4, 4);
	glPopMatrix();

}

void Rubble::drawLarge()
{  
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.2, 0.0, 0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.2, 0.0, -0.2);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.2, 0.0, -0.3);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.28, 0.0, 0.30);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2f, 0.2f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-0.35, 0.0, -0.05);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1f, 0.1f, 4, 4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0.35, 0.0, 0.05);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.1f, 0.1f, 4, 4);
	glPopMatrix();
}


Rubble::~Rubble(void)
{
}
