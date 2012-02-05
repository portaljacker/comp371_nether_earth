//Comp371_w12 PA1
//Prof. S. Mokhov
//Team 4
//Jordan V. 
//Taras K. 6901204
//Gianni T.
//Sebastien S.
//This is the main driver. It uses some functions from the sample skeleton.cpp program from class, such as camera control and related variables.

#include <iostream>
#include <GL/glut.h>
#include <math.h>


#include <strstream>
#include <iomanip>
#include "Tile.h"
#include "Map.h"
#include "Rubble.h"

// Initial size of graphics window.
const int WIDTH  = 600;
const int HEIGHT = 400;

// Current size of window.
int width  = WIDTH;
int height = HEIGHT;

const double STEP = 2;
const double STEP2 = -2;
const double ALL_ROUND = 360;

// Mouse positions, normalized to [0,1].
double xMouse = 0.5;
double yMouse = 0.5;

// Bounds of viewing frustum.
double nearPlane =  1;
double farPlane  = 200;

// Viewing angle.
double fovy = 45.0;

// Variables.
double alpha = 0;                                  // Set by idle function.
double beta = 0;                                   // Set by mouse X.
double distance = - (farPlane - nearPlane) / 2;    // Set by mouse Y.


void display ()
{
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.00, 0.00, 2.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);

	// Translate using Y mouse to middle of map.
	distance = - (yMouse * (farPlane - nearPlane) + nearPlane);
	glTranslatef(-25, 0, distance);
	glRotatef(45, 1, 0, 0);

	//Rotation from keypress function.
	//Hold A or D to rotate.
	glRotatef(alpha, 0, 1, 0);

	//Objects for drawing.
	Tile t1 = Tile();
	Map m1 = Map();
	Rubble r1 = Rubble();

	//Main rendering loop.
	for(int i = 0; i < 50; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			//Draw standard tile.
			if(m1.getChar(i, j, 0) == 't')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glBegin(GL_QUADS);
				t1.draw();
				glEnd();
				glFlush();
				glPopMatrix();
			}

			//Draw standard tile and small rubble pile.
			else if(m1.getChar(i, j, 0) == 's')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glBegin(GL_QUADS);
				t1.draw();
				glEnd();
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 0, j);
				r1.drawSmall();
				glFlush();
				glPopMatrix();
			}

			//Draw standard tile and medium rubble pile.
			else if(m1.getChar(i, j, 0) == 'm')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glBegin(GL_QUADS);
				t1.draw();
				glEnd();
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 0, j);
				r1.drawMedium();
				glFlush();
				glPopMatrix();
			}

			//Draw standard tile and large rubble pile.
			else if(m1.getChar(i, j, 0) == 'l')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glBegin(GL_QUADS);
				t1.draw();
				glEnd();
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 0, j);
				r1.drawLarge();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit.
			else if(m1.getChar(i, j, 0) == 'h') //h = horizontal pit
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(90, 0, 1, 0); //rotate to horizontal position
				glBegin(GL_QUADS);
				t1.drawHole();
				glEnd();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit.
			else if(m1.getChar(i, j, 0) == 'v') //v = vertical pit
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glBegin(GL_QUADS);
				t1.drawHole();
				glEnd();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'e') //e = east edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(-90, 0, 1, 0); //rotate to proper position
				glBegin(GL_QUADS);
				t1.drawHoleEdge();
				glEnd();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'w') //w = west edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(90, 0, 1, 0); //rotate to proper position
				glBegin(GL_QUADS);
				t1.drawHoleEdge();
				glEnd();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'n') //n = north edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glBegin(GL_QUADS);
				t1.drawHoleEdge();
				glEnd();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'd') //d = south edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(180, 0, 1, 0); //rotate to proper position
				glBegin(GL_QUADS);
				t1.drawHoleEdge();
				glEnd();
				glFlush();
				glPopMatrix();
			}
		}
	}
	
	glEnable(GL_DEPTH_TEST);
	

	glutSwapBuffers();
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{

		case 27: //Escape key
			exit(0);

		case 97: //a key
			alpha += STEP;
			if (alpha > ALL_ROUND)
				alpha -= ALL_ROUND;

			glutPostRedisplay();
			break;
		case 100: //d key
			alpha += STEP2;
			if (alpha > ALL_ROUND)
				alpha -= ALL_ROUND;

			glutPostRedisplay();
			break;
	}
}


void mouseMovement (int mx, int my)
{
	// Normalize mouse coordinates.
	xMouse = double(mx) / double(width);
	yMouse = 1 - double(my) / double(height);
	// Redisplay image.
	glutPostRedisplay();
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}



int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	
	//Create the window
	glutCreateWindow("Nether Earth Test Map");
	
	//Set handler functions
	glutDisplayFunc(display);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutMotionFunc(mouseMovement);
	
	glutMainLoop();
	return 0;
}