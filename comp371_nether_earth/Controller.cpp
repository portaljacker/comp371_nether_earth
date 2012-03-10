//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the controller class. It creates the controller model.

#include "Controller.h"
#include <GL/glut.h>

Controller::Controller(void)
{
}


Controller::~Controller(void)
{
}

void Controller::draw(Shade shade) {
	
	glPushMatrix();
		float matAmbient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
		float matSpecular[] = { 0.1f, 0.1f, 0.0f, 0.1f };
		float matShininess = 60;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, matShininess);
		glColor3f(0.5, 0.5, 0.5);
		glPushMatrix();	// middle block
			glTranslatef (0.0, 0.2, 0.0);   
			glScalef (0.4, 0.4, 0.4);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();	// top left block
			glTranslatef (-0.3, 0.2, 0.3);
			glScalef (0.4, 0.4, 0.4);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();	// top right block
			glTranslatef (0.3, 0.2, 0.3);
			glScalef (0.4, 0.4, 0.4);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();	// bottom left block
			glTranslatef (-0.3, 0.2, -0.3);
			glScalef (0.4, 0.4, 0.4);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();	// bottom right block
			glTranslatef (0.3, 0.2, -0.3);
			glScalef (0.4, 0.4, 0.4);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();	// raised block
			glTranslatef (0.0, 0.4, 0.0);
			glScalef (0.2, 0.2, 0.2);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			GLUquadricObj* GL_Quadric = 0;
			glTranslatef (0.0, 0.9, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
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
			}
			gluCylinder(GL_Quadric, 0.02, 0.02, 0.8, 20, 20);
		glPopMatrix();
	glPopMatrix();
}