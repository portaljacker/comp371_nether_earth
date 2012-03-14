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
#include "Cube.h"

Controller::Controller(void)
{
}


Controller::~Controller(void)
{
}

void Controller::draw(Shade shade, GLuint tex) {
	
	//Add ambient light
	GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 0.5f}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add directed light
	GLfloat lightColor1[] = {0.85f, 0.85f, 0.85f, 1.0f}; 
	GLfloat lightPos1[] = {0.0f, 2.0f, -3.0f, 0.0f};
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glPushMatrix();
		/*float matAmbient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
		float matSpecular[] = { 0.1f, 0.1f, 0.0f, 0.1f };
		float matShininess = 60;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, matAmbient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpecular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, matShininess);*/

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glColor3f(0.7, 0.7, 0.7);
		glPushMatrix();	// middle block
			glTranslatef (0.0, 0.2, 0.0);   
			glScalef (0.4, 0.4, 0.4);
			pj::cube();
		glPopMatrix();
		glPushMatrix();	// top left block
			glTranslatef (-0.3, 0.2, 0.3);
			glScalef (0.4, 0.4, 0.4);
			pj::cube();
		glPopMatrix();
		glPushMatrix();	// top right block
			glTranslatef (0.3, 0.2, 0.3);
			glScalef (0.4, 0.4, 0.4);
			pj::cube();
		glPopMatrix();
		glPushMatrix();	// bottom left block
			glTranslatef (-0.3, 0.2, -0.3);
			glScalef (0.4, 0.4, 0.4);
			pj::cube();
		glPopMatrix();
		glPushMatrix();	// bottom right block
			glTranslatef (0.3, 0.2, -0.3);
			glScalef (0.4, 0.4, 0.4);
			pj::cube();
		glPopMatrix();
		glPushMatrix();	// raised block
			glTranslatef (0.0, 0.4, 0.0);
			glScalef (0.2, 0.2, 0.2);
			pj::cube();
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
				gluQuadricTexture(GL_Quadric, GL_TRUE);
			}
			gluCylinder(GL_Quadric, 0.02, 0.02, 0.8, 20, 20);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}