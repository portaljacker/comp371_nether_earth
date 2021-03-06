//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Cannon implementation file.

#include "Cannon.h"
#include <GL\glut.h>


Cannon::Cannon(void)
{
}


Cannon::~Cannon(void)
{
}

void Cannon::draw(GLuint tex)
{
	glPushMatrix();
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1

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

	float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	
	glBegin(GL_QUADS); //Begin quadrilateral coordinates

		//front
		//glColor3f(0.5, 0.0, 0.5);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.0, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 1.0, 0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 1.0, 0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.0, 0.45);
	
		//back
		//glColor3f(1.0, 0.0, 0.0);
		glNormal3f(0.0, 0.0, -1.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 0.0, -0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 1.0, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 1.0, -0.45);
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
		glVertex3f(0.45, 1.0, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 1.0, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 1.0, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 1.0, 0.45);

		//right
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(1.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.45, 1.0, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.45, 1.0, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.45, 0.0, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.45, 0.0, 0.45);

		//left
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(-1.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.45, 1.0, 0.45);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.45, 1.0, -0.45);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-0.45, 0.0, -0.45);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.45, 0.0, 0.45);

		glEnd();

		
		glColor3f(1.0, 1.0, 1.0);
		
		glTranslatef(0.15, 0.5, 0.25);
		GLUquadricObj *quadObj = gluNewQuadric();
		gluCylinder(quadObj, 0.05, 0.05, 0.5, 8.0, 8.0);
		glTranslatef(-0.15, -0.5, -0.25);
		gluQuadricNormals(quadObj, GL_TRUE);
		gluQuadricTexture(quadObj, GL_TRUE);

		glTranslatef(-0.15, 0.5, 0.25);
		GLUquadricObj *quadObj2 = gluNewQuadric();
		gluCylinder(quadObj2, 0.05, 0.05, 0.5, 8.0, 8.0);
		glTranslatef(0.15, -0.5, -0.25);
		gluQuadricNormals(quadObj2, GL_TRUE);
		gluQuadricTexture(quadObj2, GL_TRUE);

		//4
		glBegin(GL_QUADS);

		glColor3d(1,1,1);
		glVertex3f(-0.1f, 1.01f, 0.1f);
		glVertex3f(-0.1f, 1.01f, 0.2f);
		glVertex3f(0.1f, 1.01f, 0.2f);
		glVertex3f(0.1f, 1.01f, 0.1f);

		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.0f, 1.01f, -0.15f);
		glVertex3f(-0.0f, 1.01f, 0.35f);
		glVertex3f(0.1f, 1.01f, 0.35f);
		glVertex3f(0.1f, 1.01f, -0.15f);

		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.25f, 1.01f, -0.15f);
		glVertex3f(-0.25f, 1.01f, 0.2f);
		glVertex3f(-0.1f, 1.01f, 0.2f);
		glVertex3f(-0.1f, 1.01f, -0.15f);

		glEnd();


		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		/*
		glBegin(GL_QUADS);
	
		//front
		//glColor3f(0.5, 0.5, 0.5);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(0.05, 0.15, 0.75);
		glVertex3f(0.05, 0.25, 0.75);
		glVertex3f(-0.05, 0.25, 0.75);
		glVertex3f(-0.05, 0.15, 0.75);
	
		//back
		//glColor3f(1.0, 0.0, 0.0);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(0.05, 0.15, 0.5);
		glVertex3f(0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.15, 0.5);

		//bottom
		//glColor3f(1.0, 1.0, 0.0);
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(0.05, 0.15, 0.75);
		glVertex3f(0.05, 0.15, 0.5);
		glVertex3f(-0.05, 0.15, 0.5);
		glVertex3f(-0.05, 0.15, 0.75);

		//top
		//glColor3f(1.0, 1.0, 0.0);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(0.05, 0.25, 0.75);
		glVertex3f(0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.25, 0.75);

		//right
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(0.05, 0.25, 0.75);
		glVertex3f(0.05, 0.25, 0.5);
		glVertex3f(0.05, 0.15, 0.5);
		glVertex3f(0.05, 0.15, 0.75);

		//left
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-0.05, 0.25, 0.75);
		glVertex3f(-0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.15, 0.5);
		glVertex3f(-0.05, 0.15, 0.75);
		glEnd();

		glTranslatef(-0.35, 0.0, 0.0);
		glBegin(GL_QUADS);
	
		//front
		//glColor3f(0.5, 0.5, 0.5);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(0.05, 0.15, 0.75);
		glVertex3f(0.05, 0.25, 0.75);
		glVertex3f(-0.05, 0.25, 0.75);
		glVertex3f(-0.05, 0.15, 0.75);
	
		//back
		//glColor3f(1.0, 0.0, 0.0);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(0.05, 0.15, 0.5);
		glVertex3f(0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.15, 0.5);

		//bottom
		//glColor3f(1.0, 1.0, 0.0);
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(0.05, 0.15, 0.75);
		glVertex3f(0.05, 0.15, 0.5);
		glVertex3f(-0.05, 0.15, 0.5);
		glVertex3f(-0.05, 0.15, 0.75);

		//top
		//glColor3f(1.0, 1.0, 0.0);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(0.05, 0.25, 0.75);
		glVertex3f(0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.25, 0.75);

		//right
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(0.05, 0.25, 0.75);
		glVertex3f(0.05, 0.25, 0.5);
		glVertex3f(0.05, 0.15, 0.5);
		glVertex3f(0.05, 0.15, 0.75);

		//left
		//glColor3f(0.0, 1.0, 1.0);
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(-0.05, 0.25, 0.75);
		glVertex3f(-0.05, 0.25, 0.5);
		glVertex3f(-0.05, 0.15, 0.5);
		glVertex3f(-0.05, 0.15, 0.75);

		glEnd();
		glEnd();
		*/
	glPopMatrix();
}
