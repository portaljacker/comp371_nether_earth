//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 1
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the sample program skeleton.cpp from the course website. It is not used but provides the basis for some of the code in the SceneDriver file.

/*// Skeleton program for GLUT applications.

// Link with: opengl32.lib, glu32.lib, glut32.lib.
#include <iostream>
#include <GL/glut.h>
#include <math.h>

#include <strstream>
#include <iomanip>

// Initial size of graphics window.
const int WIDTH  = 600;
const int HEIGHT = 400;

// Current size of window.
int width  = WIDTH;
int height = HEIGHT;

// Mouse positions, normalized to [0,1].
double xMouse = 0.5;
double yMouse = 0.5;

// Bounds of viewing frustum.
double nearPlane =  5;
double farPlane  = 15;

// Viewing angle.
double fovy = 40.0;

// Variables.
double alpha = 0;                                  // Set by idle function.
double beta = 0;                                   // Set by mouse X.
double distance = - (farPlane - nearPlane) / 2;    // Set by mouse Y.

// This function is called to display the scene.
void display ()
{
 	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Translate using Y mouse.
	distance = - (yMouse * (farPlane - nearPlane) + nearPlane);
	glTranslatef(0, 0, distance);

	// Rotation from idle function.
	glRotatef(alpha, 0, 1, 0);

	// Rotation using X mouse.
	beta = 180.0 * xMouse;
	glRotatef(beta, 1, 0, 0);

	// Draw model axes.
	glBegin(GL_LINES);
		// X axis
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(2, 0, 0);
		// Y axis
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 2, 0);
		// Z axis
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 2);
	glEnd();

	// Draw an object.
	glColor3f(0, 1, 1);
	glutWireSphere(1, 20, 20);

	glutSwapBuffers();
}

// This function is called when there is nothing else to do.
void idle ()
{
	const double STEP = 0.1;
	const double ALL_ROUND = 360;
	alpha += STEP;
	if (alpha > ALL_ROUND)
		alpha -= ALL_ROUND;

	glutPostRedisplay();
}

void mouseMovement (int mx, int my)
{
	// Normalize mouse coordinates.
	xMouse = double(mx) / double(width);
	yMouse = 1 - double(my) / double(height);

	// Redisplay image.
	glutPostRedisplay();
}

// Respond to window resizing, preserving proportions.
// Parameters give new window size in pixels.
void reshapeMainWindow (int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, GLfloat(width) / GLfloat(height), nearPlane, farPlane);
}

// Display help.

// Respond to graphic character keys.
// Parameters give key code and mouse coordinates.
void graphicKeys (unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
	}
}

// Respond to function keys.
// Parameters give key code and mouse coordinates.



void main (int argc, char **argv)
{
	// GLUT initialization.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("GLUT Skeleton Program");

	// Register call backs.
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeMainWindow);
	glutKeyboardFunc(graphicKeys);
	//glutSpecialFunc(functionKeys);
	glutMotionFunc(mouseMovement);
	glutIdleFunc(idle);

	// Display help.
	//help();

	// Enter GLUT loop.
	glutMainLoop();
}*/
