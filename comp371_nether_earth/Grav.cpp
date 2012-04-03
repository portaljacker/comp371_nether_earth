//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
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

void Grav::draw(GLuint tex)
{
	glPushMatrix();
	//glEnable(GL_LIGHTING); //Enable lighting
	//glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1
	
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

	glTranslatef(0,0,.7);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//front
	//glColor3f(1.0f,0.0f, 0.0f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.0, 0.0, -0.7); 
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//front
	//glColor3f(1.0f,0.0f, 0.0f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);
	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.7, 0.0, 0.0); 
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//front
	//glColor3f(1.0f,0.0f, 0.0f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);
	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.0, 0.0, 0.7); 
	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//front
	//glColor3f(1.0f,0.0f, 0.0f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.10f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.45f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.10f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.10f, -0.45f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(-0.7, 0.0, -0.7);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates
	
	//front
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.50f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.50f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.10f, -0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.10f, -0.35f);

	//back
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.50f, 0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.50f, 0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.10f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.10f, 0.35f);

	//top
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.50f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.50f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.50f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.50f, 0.35f);

	//bottom
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.10f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.10f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.10f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.10f, 0.35f);

	//right
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35f, 0.50f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.10f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.10f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35f, 0.50f, 0.35f);

	//left
	//glColor3f(0.0f, 1.0f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.50f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.10f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.35f, 0.10f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.50f, 0.35f);

	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.0, 0.0, -0.20);
	//4
	glBegin(GL_QUADS);

	glColor3d(1,1,1);
	glVertex3f(-0.1f, 0.51f, 0.1f);
	glVertex3f(-0.1f, 0.51f, 0.2f);
	glVertex3f(0.1f, 0.51f, 0.2f);
	glVertex3f(0.1f, 0.51f, 0.1f);

	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.0f, 0.51f, -0.15f);
	glVertex3f(-0.0f, 0.51f, 0.5f);
	glVertex3f(0.1f, 0.51f, 0.5f);
	glVertex3f(0.1f, 0.51f, -0.15f);

	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 0.51f, -0.15f);
	glVertex3f(-0.25f, 0.51f, 0.2f);
	glVertex3f(-0.1f, 0.51f, 0.2f);
	glVertex3f(-0.1f, 0.51f, -0.15f);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	//glDisable(GL_LIGHTING);

	glPopMatrix();
}