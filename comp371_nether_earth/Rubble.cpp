//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
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

void Rubble::drawSmall(Shade shade, GLuint tex)
{  
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(-0.2, 0.0, 0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(0.2, 0.0, -0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Rubble::drawMedium(Shade shade, GLuint tex)
{  
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(-0.2, 0.0, 0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(0.2, 0.0, -0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.4, 0.4, 0.4);
		glTranslatef(-0.35, 0.0, -0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.1);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.4, 0.4, 0.4);
		glTranslatef(0.35, 0.0, 0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.1);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.4, 0.4, 0.4);
		glTranslatef(0.05, 0.0, 0.3);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.1);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Rubble::drawLarge(Shade shade, GLuint tex)
{  
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(-0.2, 0.0, 0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(0.2, 0.0, -0.2);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(-0.2, 0.0, -0.3);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.3, 0.3, 0.3);
		glTranslatef(0.28, 0.0, 0.30);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.2);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.4, 0.4, 0.4);
		glTranslatef(-0.35, 0.0, -0.05);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.1);
		glPopMatrix();

		glPushMatrix();
		//glColor3f(0.4, 0.4, 0.4);
		glTranslatef(0.35, 0.0, 0.05);
		glRotatef(-90, 1, 0, 0);
		cone(shade, 0.1);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Rubble::cone(Shade shade, GLdouble x) {
	glPushMatrix();
		GLUquadricObj* GL_Quadric = 0;
		if (!GL_Quadric)
		{
			GL_Quadric = gluNewQuadric();
			switch (shade) {
			case FLAT:
				gluQuadricNormals(GL_Quadric, GL_FLAT);
				break;
			case WIRE:
				gluQuadricNormals(GL_Quadric, GL_TRUE);
				break;
			case SMOOTH:
				gluQuadricNormals(GL_Quadric, GL_SMOOTH);
				break;
			}
			gluQuadricTexture(GL_Quadric, GL_TRUE);
		}
		gluCylinder(GL_Quadric, x, 0, x, 4, 4);
	glPopMatrix();
}

Rubble::~Rubble(void)
{
}
