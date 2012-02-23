//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
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
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Front Side)	
				glVertex3f( 0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Back Side)
				glVertex3f( 0.5,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.5, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Left Side)
				glVertex3f(-0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Right Side)
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Bottom Side)
				glVertex3f( 0.5,-0.2, 0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);		//(Top Side)
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
			//Left side
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Front Side)	
				glVertex3f(-0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Back Side)
				glVertex3f(-0.25,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Left Side)
				glVertex3f(-0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Right Side)
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Bottom Side)
				glVertex3f(-0.25,-0.2, 0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);	//Green (Top Side)
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Right side
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Front Side)	
				glVertex3f( 0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Back Side)
				glVertex3f( 0.5,-0.2,-0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.5, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Left Side)
				glVertex3f( 0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Right Side)
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Bottom Side)
				glVertex3f( 0.5,-0.2, 0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);		//(Top Side)
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

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
			//Left side
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Front Side)	
				glVertex3f(-0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Back Side)
				glVertex3f(-0.25,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Left Side)
				glVertex3f(-0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Right Side)
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f(-0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Bottom Side)
				glVertex3f(-0.25,-0.2, 0.5);	//Top Right Vertex
				glVertex3f(-0.5,-0.2, 0.5);	//Top Left Vertex
				glVertex3f(-0.5,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);		//(Top Side)
				glVertex3f(-0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.5, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.5, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f(-0.25, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Right side
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Front Side)	
				glVertex3f( 0.5, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Back Side)
				glVertex3f( 0.5,-0.2,-0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.5, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Left Side)
				glVertex3f( 0.25, 0.0, 0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Right Side)
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Top Left Vertex
				glVertex3f( 0.5,-0.2, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Bottom Side)
				glVertex3f( 0.5,-0.2, 0.5);	//Top Right Vertex
				glVertex3f( 0.25,-0.2, 0.5);	//Top Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.5,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);		//(Top Side)
				glVertex3f( 0.5, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f( 0.25, 0.0, 0.5);	//Bottom Left Vertex
				glVertex3f( 0.5, 0.0, 0.5);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Middle
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Front Side)	
				glVertex3f( 0.25, 0.0, 0.0);	//Top Right Vertex
				glVertex3f(-0.25, 0.0, 0.0);	//Top Left Vertex
				glVertex3f(-0.25,-0.2, 0.0);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2, 0.0);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Back Side)
				glVertex3f( 0.25,-0.2,-0.5);	//Top Right Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Top Left Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Bottom  Left Vertex
				glVertex3f( 0.25, 0.0,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Left Side)
				glVertex3f(-0.25, 0.0, 0.0);	//Top Right Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f(-0.25,-0.2, 0.0);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Right Side)
				glVertex3f( 0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f( 0.25, 0.0, 0.0);	//Top Left Vertex
				glVertex3f( 0.25,-0.2, 0.0);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,0.5,0.0);		//(Bottom Side)
				glVertex3f( 0.25,-0.2, 0.0);	//Top Right Vertex
				glVertex3f(-0.25,-0.2, 0.0);	//Top Left Vertex
				glVertex3f(-0.25,-0.2,-0.5);	//Bottom Left Vertex
				glVertex3f( 0.25,-0.2,-0.5);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);		//(Top Side)
				glVertex3f( 0.25, 0.0,-0.5);	//Top Right Vertex
				glVertex3f(-0.25, 0.0,-0.5);	//Top Left Vertex
				glVertex3f(-0.25, 0.0, 0.0);	//Bottom Left Vertex
				glVertex3f( 0.25, 0.0, 0.0);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();


	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.
}
