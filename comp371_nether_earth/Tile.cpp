//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Tile class implimentation file.

#include "Tile.h"
#include <GL/glut.h>

//Default constructor..
Tile::Tile()
{
	
}


Tile::~Tile(void)
{
}
void Tile::draw()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_QUADS);
		glPushMatrix();
			float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
			glColor3f(0.5f,0.5f,0.5f);

			glBegin(GL_QUADS);
			glPushMatrix();
				//(Front Side)
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f( 0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Back Side)
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f( 0.5,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.5, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Left Side)
				glNormal3f(-1.0, 0.0, 0.0);
				glVertex3f(-0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Right Side)
				glNormal3f(1.0, 0.0, 0.0);
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Bottom Side)
				glNormal3f(0.0, -1.0, 0.0);
				glVertex3f( 0.5,-0.2, 0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Top Side)
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

			glPushMatrix();
				glColor3f(1.0,1.0,1.0);	//White (Team Number On Top)

				glVertex3f( 0.25, 0.001,-0.25); //Long vetical bar.
				glVertex3f( 0.15, 0.001,-0.25);
				glVertex3f( 0.15, 0.001, 0.35);
				glVertex3f( 0.25, 0.001, 0.35);
			glPopMatrix();

			glPushMatrix();
				glVertex3f(-0.15, 0.001,-0.25); //Short vertical bar.
				glVertex3f(-0.25, 0.001,-0.25);
				glVertex3f(-0.25, 0.001, 0.0);
				glVertex3f(-0.15, 0.001, 0.0);
			glPopMatrix();

			glPushMatrix();
				glVertex3f( 0.25, 0.001, 0.0); //Horizontal bar.
				glVertex3f(-0.25, 0.001, 0.0);
				glVertex3f(-0.25, 0.001, 0.1);
				glVertex3f( 0.25, 0.001, 0.1);
			glPopMatrix();
			glEnd();
		glPopMatrix();
	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.
}

void Tile::drawHole()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_QUADS);
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		glColor3f(0.5f,0.5f,0.5f);
		glNormal3f(0.0, 1.0, 0.0);

		glBegin(GL_QUADS);
		glPushMatrix();
			//Left side
			glPushMatrix();
				//(Front Side)
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f(-0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Back Side)
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f(-0.25,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Left Side)
				glNormal3f(-1.0, 0.0, 0.0);
				glVertex3f(-0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Right Side)
				glNormal3f(1.0, 0.0, 0.0);
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Bottom Side)
				glNormal3f(0.0, -1.0, 0.0);
				glVertex3f(-0.25,-0.2, 0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Top Side)
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Right side
			glPushMatrix();
				//(Front Side)	
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f( 0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Back Side)
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f( 0.5,-0.2,-0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.5, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Left Side)
				glNormal3f(-1.0, 0.0, 0.0);
				glVertex3f( 0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Right Side)
				glNormal3f(1.0, 0.0, 0.0);
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Bottom Side)
				glNormal3f(0.0, -1.0, 0.0);
				glVertex3f( 0.5,-0.2, 0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Top Side)
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();
		glPopMatrix();
		glEnd();
	glPopMatrix();
	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.
}

void Tile::drawHoleEdge()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_QUADS);
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		glColor3f(0.5f,0.5f,0.5f);
		glNormal3f(0.0, 1.0, 0.0);

		glBegin(GL_QUADS);
		glPushMatrix();
			//Left side
			glPushMatrix();
				//(Front Side)
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f(-0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Back Side)
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f(-0.25,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Left Side)
				glNormal3f(-1.0, 0.0, 0.0);
				glVertex3f(-0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Right Side)
				glNormal3f(1.0, 0.0, 0.0);
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Bottom Side)
				glNormal3f(0.0, -1.0, 0.0);
				glVertex3f(-0.25,-0.2, 0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Top Side)
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Right side
			glPushMatrix();
				//(Front Side)
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f( 0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Back Side)
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f( 0.5,-0.2,-0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.5, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Left Side)
				glNormal3f(-1.0, 0.0, 0.0);
				glVertex3f( 0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Right Side)
				glNormal3f(1.0, 0.0, 0.0);
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Bottom Side)
				glNormal3f(0.0, -1.0, 0.0);
				glVertex3f( 0.5,-0.2, 0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Top Side)
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Middle
			glPushMatrix();
				//(Front Side)
				glNormal3f(0.0, 0.0, 1.0);
				glVertex3f( 0.25, 0.0, 0.0);	//Top Right Vertex
				glVertex3f(-0.25, 0.0, 0.0);	//Top Left Vertex
				glVertex3f(-0.25,-0.2, 0.0);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2, 0.0);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Back Side)
				glNormal3f(0.0, 0.0, -1.0);
				glVertex3f( 0.25,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Left Side)
				glNormal3f(-1.0, 0.0, 0.0);
				glVertex3f(-0.25, 0.0, 0.0);	//Top Right Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2, 0.0);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Right Side)
				glNormal3f(1.0, 0.0, 0.0);
				glVertex3f( 0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0, 0.0);	//Top Left Vertex
				glVertex3f( 0.25,-0.2, 0.0);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Bottom Side)
				glNormal3f(0.0, -1.0, 0.0);
				glVertex3f( 0.25,-0.2, 0.0);	//Top Right Vertex
				glVertex3f(-0.25,-0.2, 0.0);	//Top Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				//(Top Side)
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f( 0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.25, 0.0, 0.0);	//Bottom Left Vertex
				glVertex3f( 0.25, 0.0, 0.0);	//Bottom Right Vertex
			glPopMatrix();
		glPopMatrix();
		glEnd();
	glPopMatrix();


	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.
}