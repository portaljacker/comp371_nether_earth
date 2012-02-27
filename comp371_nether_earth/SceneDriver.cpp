//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the main driver. It uses some functions from the sample skeleton.cpp and sampleprogram.cpp files from class, such as camera control and related variables.

#include <iostream>
#include <GL/glut.h>
#include <math.h>


#include <strstream>
#include <iomanip>
#include "Tile.h"
#include "Map.h"
#include "Rubble.h"
#include "Block.h"
#include "Controller.h"
#include "Bipod.h"
#include "Grav.h"
#include "Tracks.h"
#include "eBrain.h"
#include "Cannon.h"
#include "Nuke.h"
#include "Missiles.h"
#include "Phaser.h"
using namespace std;

// Initial size of graphics window.
const int WIDTH  = 600;
const int HEIGHT = 600;

// Current size of window.
int width  = WIDTH;
int height = HEIGHT;

const double STEP = 2; //Used in Perspective and Orthogonal camera modes.
const double ORBSTEP = 0.01; //Used to lessen rotation during Orbit Mode.
const double ALL_ROUND = 360;

// Mouse positions, normalized to [0,1].
double xMouse = 0.5;
double yMouse = 0.5;

// Bounds of viewing frustum.
double viewWindowLeft =  -100;
double viewWindowRight  = 100;
double viewWindowBottom =  -100;
double viewWindowTop  = 100;
double nearPlane =  1;
double farPlane  = 200;

// Variables used in zooming (1 and 2 keys).
const double ZoomSTEP = 2;
const double zoomFactor = 1.03;

// Viewing angle.
double fovy = 45.0;

// Variables.
//Used in camera rotation (Ortho mode).
double alpha = 0;                                  
double beta = 0;
double gamma = 0;
double distance = - (farPlane - nearPlane) / 2; 

//Used in eye placement (Perspective mode).
double movX = 0;
double movY = 0;
double movZ = 0;

//Tilt (Orthogonal Mode).
double rotX = 0;
double rotY = 0;
double rotZ = 0;

//Coordinates for Orbit Mode.
double orbX = 0;
double eyeX = 0;
double eyeY = 50;
double eyeZ = 50;
double upX= 0;
double upY= 1;
double upZ= 0;
double r = 70; //Orbit Radius

int wireFrame = 0; //For wireframe mode.
int cameraMode = 1; //For camera modes.
bool cameraReset = false;

void setCamera()
{
	// Must set it up in Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Rotation about Y from LEFT-RIGHT Arrow key.
	glRotatef(alpha, 0, 1, 0);
	// Rotation about X from UP-DOWN Arrow key.
	glRotatef(beta, 1, 0, 0);
	//Rotation about Z from F1-F2 keys.
	glRotatef(gamma, 0, 0, 1);

	if(cameraMode == 1 || cameraMode == 2)
	{
		gluPerspective(fovy, width/height, nearPlane, farPlane);
	}
	else
	{
		glOrtho(viewWindowLeft, viewWindowRight, viewWindowBottom, viewWindowTop, nearPlane, farPlane); //Useful for question 9.
	}
	
}
//Displays controls in console window.
void dispKeys()
{
	cout << "Camera controls:" << endl;
	cout << "Perspective mode:" << endl;
	cout << "w, a, s, d: Move the camera around." << endl;
	cout << "q, e: Move the camera up or down.(Closer or farther from the \"ground\".)" << endl;
	cout << "left & right arrow keys: Rotate camera horizontally." << endl;
	cout << "up & down arrow keys: Rotate camera vertically.(Look up or down.)" << endl;
	cout << endl;
	cout << "Orbit mode:" << endl;
	cout << "a, d: Make camera orbit left or right." << endl;
	cout << endl;
	cout << "Orthogonal mode:" << endl;
	cout << "left & right arrow keys: Rotate around y axis." << endl;
	cout << "up & down arrow keys: Rotate around x axis." << endl;
	cout << endl;
	cout << "Controls common to all modes:" << endl;
	cout << "1, 2: Zoom in and out." << endl;
	cout << "F1, F2: Rotate around Z axis.(May get clippy in Perspective mode.)" << endl;
	cout << "c: Toggle Perspective / Orbit / Orthogonal mode." << endl;
	cout << "r: Reset camera." << endl;
	cout << endl;
	cout << "Other controls:" << endl;
	cout << "t: Toggle wireframe/shading mode." << endl;
	cout << "h/H: Display list of controls in console window." << endl;
	cout << "esc: Close the program." << endl;
	cout << endl;
}

//Resets variables to initial values.
void resetCam()
{
	alpha = 0;
	beta = 0;
	gamma = 0;
	movX = 0;
	movY = 0;
	movZ = 0;
	rotX = 0;
	rotY = 0;
	rotZ = 0;
	orbX = 0;
	eyeX = 0;
	eyeY = 50;
	eyeZ = 50;
	upX= 0;
	upY= 1;
	upZ= 0;
	viewWindowLeft =  -100;
	viewWindowRight  = 100;
	viewWindowBottom =  -100;
	viewWindowTop  = 100;
	cameraReset = true;
}

void display ()
{
	setCamera();

 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals

	if(cameraMode != 2) //For Perspective and Orthogonal modes.
	{
		if(cameraReset)//Reset camera to starting point.
		{
			gluLookAt(0.00, 50.00, 50.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
			cameraReset = false;
		}
		else
			gluLookAt(movX, movY + 50.00, movZ +50.00, movX + rotX, movY + rotY, movZ + rotZ, 0.00, 1.00, 0.00);
	}

	else //For Orbit mode.
	{
		if(cameraReset)//Reset camera to starting point.
		{
			gluLookAt(0.00, 50.00, 50.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
			cameraReset = false;
		}
		else
		{
			gluLookAt(eyeX, eyeY, eyeZ, 0.00, 0.00, 0.00, upX, upY, upZ);
		}
	}


	//Add ambient light
	GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Centers map aroundt he origin for viewing.
	glTranslatef(-25, 0, -25);

	//Objects for drawing.
	Tile t1 = Tile();
	Map m1 = Map();
	Rubble r1 = Rubble();
	Block b1 = Block();
	Controller c1 = Controller();
	Bipod b2 = Bipod();
	Grav g1 = Grav();
	Tracks t2 = Tracks();
	eBrain e1 = eBrain();
	Cannon c2 = Cannon();
	Nuke n1 = Nuke();
	Missiles m2 = Missiles();
	Phaser p1 = Phaser();

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

			//Draw plain half-block
			if(m1.getChar(i,j,1) == '1') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawPH();
				glFlush();
				glPopMatrix();
			}

			//Draw plain full-block
			else if(m1.getChar(i,j,1) == '2') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawPU();
				glFlush();
				glPopMatrix();
			}
			
			//Draw holed half-block
			else if(m1.getChar(i,j,1) == '3'){
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawHH();
				glFlush();
				glPopMatrix();
			}
			
			//Draw holed full-block
			else if(m1.getChar(i,j,1) == '4') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawHU();
				glFlush();
				glPopMatrix();
			}
			
			//Draw HQ block
			else if(m1.getChar(i,j,1) == '5') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawHQ();
				glFlush();
				glPopMatrix();
			}
			
			//Draw delimiter
			else if(m1.getChar(i,j,1) == '6') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawD();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'b') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glScalef(0.25, 0.25, 0.25);
				b2.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'g') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glTranslatef(0.0, 0.15, 0.0);
				g1.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 't') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glTranslatef(0.0, 0.15, 0.0);
				t2.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'e') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				e1.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'c') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				c2.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'p') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(-90,1,0,0);
				p1.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'n') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				n1.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'm') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				m2.draw();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'r') {
				glPushMatrix();
				glTranslatef(i-0.35, 0.15, j);
				t2.draw();
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 1.0, j);
				c2.draw();
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 1.5, j);
				e1.draw();
				glFlush();
				glPopMatrix();
			}

			if (m1.getChar(i,j,2) == '1') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				c1.draw();
				glFlush();
				glPopMatrix();
			}

		}
	}
	
	glEnable(GL_DEPTH_TEST);
	

	glutSwapBuffers();
}

//Function found in the sampleprogram.cpp file from class.
void zoom(unsigned char direction)
{
	if (direction == '+') {
			viewWindowLeft += ZoomSTEP; viewWindowRight -= ZoomSTEP;
			viewWindowBottom += ZoomSTEP; viewWindowTop -= ZoomSTEP;
			fovy = fovy / zoomFactor;
		}
		else if (direction == '-') {
			viewWindowLeft -= ZoomSTEP; viewWindowRight += ZoomSTEP;
			viewWindowBottom -= ZoomSTEP; viewWindowTop += ZoomSTEP;
			fovy = fovy * zoomFactor;
		}

}

//Based on Mouse Coordinates function by H. Shirokawa.
//http://homepages.ius.edu/rwisman/b481/html/notes/FlyAround.htm
void orbit()
{
// Mouse point to angle conversion
  double theta = (360.0/HEIGHT)*50*3.0;
  double phi = (360.0/WIDTH)*orbX*3.0;

// Convert spherical coordinates to eye coordinates.
   eyeX = r * sin(theta*ORBSTEP)* sin(phi*ORBSTEP);
   eyeY = r * cos(theta*ORBSTEP);
   eyeZ = r * sin(theta*ORBSTEP)* cos(phi*ORBSTEP);

// Calculate the coordinates of another point on the same plane as the first.
   double diff = 1.0; //Subtracted from old theta to get new theta.
   double eyeXtemp = r * sin(theta*ORBSTEP-diff)* sin(phi*ORBSTEP);
   double eyeYtemp = r * cos(theta*ORBSTEP-diff);
   double eyeZtemp = r * sin(theta*ORBSTEP-diff)* cos(phi*ORBSTEP);

// Connect these two points to obtain the camera's up vector.
   upX=eyeXtemp-eyeX;
   upY=eyeYtemp-eyeY;
   upZ=eyeZtemp-eyeZ;

	glutPostRedisplay();
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{

	switch (key)
	{

	case 27: //Escape key
		exit(0);
		//These controls only work in Perspective Mode (a and d also work in Orbit Mode).
	case 'a':
		if(cameraMode == 1)
			movX -= STEP;
		if(cameraMode == 2)
		{
			orbX -= STEP;
			orbit();
		}
		break;

	case 'd':
		if(cameraMode == 1)
			movX += STEP;
		if(cameraMode == 2)
		{
			orbX += STEP;
			orbit();
		}
		break;

	case 'w':
		if(cameraMode == 1)
			movZ -= STEP;
		break;

	case 's':
		if(cameraMode == 1)
			movZ += STEP;
		break;

	case 'q':
		if(cameraMode == 1)
			movY -= STEP;
		break;

	case 'e':
		if(cameraMode == 1)
			movY += STEP;
		break;

		//These keys work in all camera modes.
	case '1':
		zoom('+');
		break;

	case '2':
		zoom('-');
		break;

	case 'c':
		if(cameraMode != 2)
			cameraMode++;
		else
			cameraMode = 0;
		break;

	case 'r'://Reset camera.
		resetCam();
		break;

	case 'h'://Displays controls in console window.
		dispKeys();
		break;

	case 'H':
		dispKeys();
		break;
	case 't':
		wireFrame++;
		wireFrame %= 3;
		switch(wireFrame) {
		case 0: 
			glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);	// Solid
			break;
		case 1:
			glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);	// Wireframes
			break;
		case 3:
			glShadeModel(GL_SMOOTH);					// Smooth
			break;
		}
		glutPostRedisplay();
	}

	glutPostRedisplay();
}

void functionKeys (int key, int x, int y)
{
	
	   switch (key)
	   {
		   //These keys work differently depending on the camera mode.
			case GLUT_KEY_LEFT:
				if(cameraMode == 1)//Perspective Mode
				{
					rotX -= STEP;
				}

				if(cameraMode == 0)//Orthogonal Mode
				{
					alpha -= STEP;
					if (alpha > ALL_ROUND)
						alpha -= ALL_ROUND;
				}
				break;

			case GLUT_KEY_RIGHT:
				if(cameraMode == 1)
				{
					rotX += STEP;
				}

				if(cameraMode == 0)
				{
					alpha += STEP;
					if (alpha > ALL_ROUND)
						alpha -= ALL_ROUND;
				}
				break;

			case GLUT_KEY_UP:
				if(cameraMode == 1)
				{
					rotY += STEP;
				}

				if(cameraMode == 0)
				{
					beta += STEP;
					if (beta > ALL_ROUND)
						beta -= ALL_ROUND;
				}
				break;

			case GLUT_KEY_DOWN:
				if(cameraMode == 1)
				{
					rotY -= STEP;
				}

				if(cameraMode == 0)
				{
					beta -= STEP;
					if (beta > ALL_ROUND)
						beta -= ALL_ROUND;
				}
				break;

			//These keys work the same way in both Perspective and Ortohognal camera modes.
			case GLUT_KEY_F1:
				if(cameraMode != 2)
				{
					gamma -= STEP;
					if (gamma > ALL_ROUND)
						gamma -= ALL_ROUND;
					break;
				}
			
			case GLUT_KEY_F2:
				if(cameraMode != 2)
				{
					gamma += STEP;
					if (gamma > ALL_ROUND)
						gamma -= ALL_ROUND;
					break;
				}
	   }

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
	glutInitWindowSize(WIDTH, HEIGHT);
	
	//Create the window
	glutCreateWindow("Nether Earth Test Map");
	
	//Set handler functions
	glutDisplayFunc(display);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(functionKeys);
	glutReshapeFunc(handleResize);
	
	glutMainLoop();
	return 0;
}