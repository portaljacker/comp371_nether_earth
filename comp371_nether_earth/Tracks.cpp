//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Tracks implementation file.

#include "Tracks.h"
#include "imageloader.h"
#include <GL\glut.h>

Tracks::Tracks(void)
{
}


Tracks::~Tracks(void)
{
}


void Tracks::draw(GLuint tex)
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
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
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

	//top
	//glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.15f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.15f, 0.45f);

	//bottom
	//glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);

	//right 1
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);

	//right 2
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);

	//right 3
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);

	//left 1
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//left 2
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);

	//left 3
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	
	glEnd(); //End quadrilateral coordinates

	glTranslatef(0.7, 0.0, 0.0);

	glBegin(GL_QUADS); //Begin quadrilateral coordinates

	//top
	//glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.15f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.15f, 0.45f);

	//bottom
	//glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);

	//right 1
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);

	//right 2
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, 0.25f);

	//right 3
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.25f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.25f, 0.0f, -0.25f);

	//left 1
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	//left 2
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, 0.25f);

	//left 3
	//glColor3f(0.5f, 0.5f, 1.0f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 0.15f, -0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.0f, -0.25f);

	glEnd(); //End quadrilateral coordinates
	
	glTranslatef(-0.7, 0.0, 0.0);

	glBegin(GL_QUADS);

	//bottom
	//glColor3f(0.5f, 0.0f, 0.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.15f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.15f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.15f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.15f, 0.35f);

	//top                    
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 1.0f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 1.0f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 1.0f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 1.0f, 0.35f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.15f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.15f, -0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 1.0f, -0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 1.0f, -0.35f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.15f, 0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 0.15f, 0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 1.0f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 1.0f, 0.35f);

	//right
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.35f, 1.0f, -0.35f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.35f, 1.0f, 0.35f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.35f, 0.15f, 0.35f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.35f, 0.15f, -0.35f);

	//left
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glVertex3f(-0.35f, 1.0f, -0.35f);
	glVertex3f(-0.35f, 1.0f, 0.35f);
	glVertex3f(-0.35f, 0.15f, 0.35f);
	glVertex3f(-0.35f, 0.15f, -0.35f);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	//4
	glPushMatrix();
	glBegin(GL_QUADS);

	glColor3d(1,1,1);
	glVertex3f(-0.1f, 1.01f, 0.1f);
	glVertex3f(-0.1f, 1.01f, 0.2f);
	glVertex3f(0.1f, 1.01f, 0.2f);
	glVertex3f(0.1f, 1.01f, 0.1f);

	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.0f, 1.01f, -0.15f);
	glVertex3f(-0.0f, 1.01f, 0.3f);
	glVertex3f(0.1f, 1.01f, 0.3f);
	glVertex3f(0.1f, 1.01f, -0.15f);

	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.25f, 1.01f, -0.15f);
	glVertex3f(-0.25f, 1.01f, 0.2f);
	glVertex3f(-0.1f, 1.01f, 0.2f);
	glVertex3f(-0.1f, 1.01f, -0.15f);

	glEnd();
	glPopMatrix();
	glDisable(GL_LIGHTING);

	glPopMatrix();
}