//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Bipod implimentation file.

#include "Bipod.h"
#include <GL\glut.h>

Bipod::Bipod(void)
{
}


Bipod::~Bipod(void)
{
}

void Bipod::draw(GLuint tex)
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

	glBegin(GL_QUADS);
	//Leg
	//Bottom face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.0f, 0.25f);
	
	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.35f, 0.75f, -0.15f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.75f, 0.0f);
	
	//Left face 2
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.25f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.35f, 0.05f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.0f, 0.25f);
	
	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.75f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, 0.0f);
	
	//Right face 2
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.25f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.05f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, 0.25f);
	
	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.05f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.05f, 0.25f);
	
	//Front Face 2
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.05f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.05f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.25f, -0.15f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.25f, -0.15f);
	
	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.75f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, -0.15f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	
	//Front 
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.15f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.15f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.75f, 0.0f);
	
	//Top face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.75f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.75f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, -0.15f);
	
	glEnd();

	glTranslatef(0.6, 0.0, 0.0);
	glBegin(GL_QUADS);
	//Leg
	//Bottom face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.0f, 0.25f);
	
	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.35f, 0.75f, -0.15f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.75f, 0.0f);
	
	//Left face 2
	glNormal3f(-1.0, 0.0f, 0.0f);
	//glColor3f(0.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.25f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.35f, 0.05f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.0f, 0.25f);
	
	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.75f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, 0.0f);
	
	//Right face 2
	glNormal3f(1.0, 0.0f, 0.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.25f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.05f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, 0.25f);
	
	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.0f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.05f, 0.25f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.05f, 0.25f);
	
	//Front Face 2
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.05f, 0.25f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.05f, 0.25f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.25f, -0.15f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.25f, -0.15f);
	
	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	//glColor3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.0f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.75f, -0.15f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, -0.15f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.0f, -0.15f);
	
	//Front 
	glNormal3f(0.0, 0.0f, 1.0f);
	//glColor3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.15f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.15f, 0.15f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.35f, 0.75f, 0.0f);
	
	//Top face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.35f, 0.75f, -0.15f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.35f, 0.75f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.15f, 0.75f, -0.15f);
	
	glEnd();

	glTranslatef(-0.55f, 0.0f, 0.0f);

	glBegin(GL_QUADS);

	//bottom
	//glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.75f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.45f, 0.75f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.45f, 0.75f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.75f, 0.45f);

	//top                    
	//glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 1.0f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.45f, 1.0f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.45f, 1.0f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 1.0f, 0.45f);

	//back
	//glColor3f(1.0f, 0.5f, 0.0f);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.75f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.45f, 0.75f, -0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.45f, 1.0f, -0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 1.0f, -0.45f);

	//front
	//glColor3f(1.0f, 0.0f, 0.5f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 0.75f, 0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.45f, 0.75f, 0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.45f, 1.0f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 1.0f, 0.45f);

	//right
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.45f, 1.0f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.45f, 1.0f, 0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.45f, 0.75f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.45f, 0.75f, -0.45f);

	//left
	//glColor3f(1.0f, 0.5f, 0.5f);
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.45f, 1.0f, -0.45f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.45f, 1.0f, 0.45f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.45f, 0.75f, 0.45f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.45f, 0.75f, -0.45f);

	glEnd();

	//4
	glBegin(GL_QUADS);

	//glColor3f(0.0f, 1.0f, 0.0f);
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

	glDisable(GL_TEXTURE_2D);
	//glDisable(GL_LIGHTING);
	glPopMatrix();
}