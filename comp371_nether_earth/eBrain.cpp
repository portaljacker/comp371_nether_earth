//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the eBrain implimentation file.

#include "eBrain.h"
#include <GL\glut.h>


eBrain::eBrain(void)
{
}


eBrain::~eBrain(void)
{
}

void eBrain::draw(GLuint tex)
{
	glPushMatrix();
	
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0

	//Add ambient light
	GLfloat ambientColor[] = {0.75f, 0.75f, 0.75f, 0.5f}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat lightPos0[] = {0.0f, 3.0f, 0.0f, 1.0f}; 
	GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 20.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	////Add ambient light
	//GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 0.5f}; 
	////glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	//
	////Add directed light
	//GLfloat lightColor1[] = {0.85f, 0.85f, 0.85f, 1.0f}; 
	//GLfloat lightPos1[] = {0.0f, 2.0f, -3.0f, 0.0f};
	//glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
	//glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

		//front
		//glColor3f(0.0, 0.5, 0.5);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.0, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 0.5, 0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 0.5, 0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.0, 0.45);
	
		//back
		//glColor3f(1.0, 0.0, 0.0);
		glNormal3f(0.0, 0.0, -1.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.0, -0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 0.5, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 0.5, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.0, -0.45);

		//bottom
		//glColor3f(1.0, 1.0, 0.0);
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.0, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 0.0, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 0.0, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.0, 0.45);

		//top
		//glColor3f(1.0, 1.0, 0.0);
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.5, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 0.5, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 0.5, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.5, 0.45);

		//right
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(1.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.5, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 0.5, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.45, 0.0, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.45, 0.0, 0.45);

		//left
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(-1.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.45, 0.5, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.45, 0.5, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 0.0, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.0, 0.45);

		glEnd();

		//glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0, 0.5, 0.0);
		//glNormal3f(0.0, 1.0, 0.0);
		glutSolidSphere( 0.40, 8.0, 8.0);

		//4
		glBegin(GL_QUADS);

		glColor3d(1,1,1);
		glVertex3f(-0.1f, 0.51f, 0.1f);
		glVertex3f(-0.1f, 0.51f, 0.2f);
		glVertex3f(0.1f, 0.51f, 0.2f);
		glVertex3f(0.1f, 0.51f, 0.1f);

		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.0f, 0.51f, -0.15f);
		glVertex3f(-0.0f, 0.51f, 0.35f);
		glVertex3f(0.1f, 0.51f, 0.35f);
		glVertex3f(0.1f, 0.51f, -0.15f);

		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.25f, 0.51f, -0.15f);
		glVertex3f(-0.25f, 0.51f, 0.2f);
		glVertex3f(-0.1f, 0.51f, 0.2f);
		glVertex3f(-0.1f, 0.51f, -0.15f);

	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}