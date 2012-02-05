//Comp371_w12 PA1
//Prof. S. Mokhov
//Team 4
//Jordan V. 
//Taras K. 6901204
//Gianni T.
//Sebastien S.
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
