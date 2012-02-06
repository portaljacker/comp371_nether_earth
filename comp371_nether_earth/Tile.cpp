//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 1
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
				glColor3f(0.0f,0.5f,0.0f);		//(Front Side)	
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Back Side)
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Left Side)
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Right Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Bottom Side)
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);		//(Top Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();

			glPushMatrix();
				glColor3f(1.0f,1.0f,1.0f);	//White (Team Number On Top)

				glVertex3f( 0.25f, 0.001f,-0.25f); //Long vetical bar.
				glVertex3f( 0.15f, 0.001f,-0.25f);
				glVertex3f( 0.15f, 0.001f, 0.35f);
				glVertex3f( 0.25f, 0.001f, 0.35f);
			glPopMatrix();

			glPushMatrix();
				glVertex3f(-0.15f, 0.001f,-0.25f); //Short vertical bar.
				glVertex3f(-0.25f, 0.001f,-0.25f);
				glVertex3f(-0.25f, 0.001f, 0.0f);
				glVertex3f(-0.15f, 0.001f, 0.0f);
			glPopMatrix();

			glPushMatrix();
				glVertex3f( 0.25f, 0.001f, 0.0f); //Horizontal bar.
				glVertex3f(-0.25f, 0.001f, 0.0f);
				glVertex3f(-0.25f, 0.001f, 0.1f);
				glVertex3f( 0.25f, 0.001f, 0.1f);
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
				glColor3f(0.0f,0.5f,0.0f);		//(Front Side)	
				glVertex3f(-0.25f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Back Side)
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Left Side)
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Right Side)
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.25f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.25f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Bottom Side)
				glVertex3f(-0.25f,-0.2f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);	//Green (Top Side)
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f, 0.0f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Right side
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Front Side)	
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Back Side)
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Left Side)
				glVertex3f( 0.25f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.25f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Right Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Bottom Side)
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Top Right Vertex
				glVertex3f( 0.25f,-0.2f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);		//(Top Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f( 0.25f, 0.0f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Bottom Right Vertex
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
				glColor3f(0.0f,0.5f,0.0f);		//(Front Side)	
				glVertex3f(-0.25f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Back Side)
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Left Side)
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Right Side)
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.25f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.25f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Bottom Side)
				glVertex3f(-0.25f,-0.2f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);		//(Top Side)
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f, 0.0f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Right side
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Front Side)	
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Back Side)
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Left Side)
				glVertex3f( 0.25f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.25f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Right Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Bottom Side)
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Top Right Vertex
				glVertex3f( 0.25f,-0.2f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);		//(Top Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f( 0.25f, 0.0f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//Middle
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Front Side)	
				glVertex3f( 0.25f, 0.0f, 0.0f);	//Top Right Vertex
				glVertex3f(-0.25f, 0.0f, 0.0f);	//Top Left Vertex
				glVertex3f(-0.25f,-0.2f, 0.0f);	//Bottom Left Vertex
				glVertex3f( 0.25f,-0.2f, 0.0f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Back Side)
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Left Side)
				glVertex3f(-0.25f, 0.0f, 0.0f);	//Top Right Vertex
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.25f,-0.2f, 0.0f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Right Side)
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.25f, 0.0f, 0.0f);	//Top Left Vertex
				glVertex3f( 0.25f,-0.2f, 0.0f);	//Bottom Left Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.5f,0.0f);		//(Bottom Side)
				glVertex3f( 0.25f,-0.2f, 0.0f);	//Top Right Vertex
				glVertex3f(-0.25f,-0.2f, 0.0f);	//Top Left Vertex
				glVertex3f(-0.25f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.25f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);		//(Top Side)
				glVertex3f( 0.25f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.25f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.25f, 0.0f, 0.0f);	//Bottom Left Vertex
				glVertex3f( 0.25f, 0.0f, 0.0f);	//Bottom Right Vertex
			glPopMatrix();

		glPopMatrix();


	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.
}
