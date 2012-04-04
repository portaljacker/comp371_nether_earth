//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the main driver. It uses some functions from the sample skeleton.cpp and sampleprogram.cpp files from class, such as camera control and related variables.
//Orbit camera function based on code by H. Shirokawa. (Link in comments.)

#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <Windows.h>


#include <strstream>
#include <iomanip>
#include "Enumerations.h"
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
#include "lightPostConstruct.h"
#include "ImageLoader.h"
#include "SkyBox.h"
using namespace std;

enum Dir {NORTH, SOUTH, EAST, WEST};

struct point {	// Defines a 2D point for use in collision detection
	GLfloat x;
	GLfloat z;
};

GLuint loadTexture(Image* image);
bool willCollide(int object, GLfloat deltaX, GLfloat deltaZ);

// positions of the center of moving objects
point robot1;
point robot2;
point control;
point pew;

// direction of moving objects
Dir dRobot1 = SOUTH;
Dir dRobot2 = SOUTH;
Dir dPew;

// counters for movement
int robot1Count = 0;

bool docked = false;	// is controller docked
bool pewpew = false;	// has a shot been fired
bool destroyed = false;	// has robot1 been destroyed
int health = 2;	// health of robot 1
int spin = 0;	// spin of pew
GLfloat pewD = .25;
GLfloat tempX;
GLfloat tempZ;

// Initial size of graphics window.
const int WIDTH  = 600;
const int HEIGHT = 600;

bool fullscreen = false;

// Current size of window.
int width  = WIDTH;
int height = HEIGHT;

const double STEP = 2; //Used in Perspective and Orthogonal camera modes.
const double ORBSTEP = 0.01; //Used to lessen rotation during Orbit Mode.
const double ALL_ROUND = 360;

// Mouse origin variables. (Used in Perspective mode with mouse controls.)
double originX = 0.0;
double originY = 0.0;

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

//Tilt variables (Perspective mode).
double rotX = 0;
double rotY = 0;
double rotZ = 0;
double upX = 0;
double upY = 0;
double upZ = 0;

//Coordinates for Orbit Mode.
double orbX = 0;
double eyeX = 0;
double eyeY = 35;
double eyeZ = 35;
double r = 44; //Orbit Radius

Shade shade = FLAT;	//For wireframe mode.

int cameraMode = 1; //For camera modes.
int mouseControls = 0; //For mouse controls in camera mode 1 (Perspective mode).
bool cameraReset = false;

// Constant look at point of the lightpost's light and the camera 
const GLfloat lookAtPoint = 3.0 * sqrt(2.0); 

//Variables for storing textures.
GLuint blockTexId1;
GLuint blockTexId2;
GLuint blockTexId3;
GLuint blockTexId4;
GLuint blockTexId5;
GLuint hole; //Hole texture stored here.
Image* im;
GLuint tileTex;
GLuint tex1;
GLuint tex2;
GLuint tex3;

SkyBox sky;

bool fEquals(float a, float b) {
	return fabs(a - b) < .001;
}

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

	if(cameraMode != 0)
	{
		gluPerspective(fovy, width/height, nearPlane, farPlane);
	}
	else
	{
		glOrtho(viewWindowLeft, viewWindowRight, viewWindowBottom, viewWindowTop, nearPlane, farPlane);
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
	cout << "mouse: If mouse controls are enabled, hold down left mouse button" << endl;
	cout << " and move the mouse to tilt the camera (same function as arrow keys)." << endl;
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
	cout << "c: Toggle Perspective / Orbit / Orthogonal mode / First Person Robot View /" << endl;
	cout << " Light Post Views" << endl;
	cout << "m: Toggle mouse controls for Perspective mode." << endl;
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
	eyeY = 35;
	eyeZ = 35;
	upX = 0;
	upY = 0;
	upZ = 0;
	originX = 0.0;
	originY = 0.0;
	viewWindowLeft =  -100;
	viewWindowRight  = 100;
	viewWindowBottom =  -100;
	viewWindowTop  = 100;
	cameraReset = true;
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image)
{
	GLuint tempTexture;
	glGenTextures(1, &tempTexture);
	glBindTexture(GL_TEXTURE_2D, tempTexture);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);
	return tempTexture;
}

bool willCollide(int object, GLfloat deltaX, GLfloat deltaZ) {
	switch(object) {
	case 0:	//robot
		if(fabs(deltaX) > 0) {
			if(fabs(robot1.z - robot2.z) < 1)
				if(fabs((robot1.x + deltaX) - robot2.x) < 1)
					return true;
		}
		else if(fabs(deltaZ) > 0) {
			if(fabs(robot1.x - robot2.x) < 1)
				if(fabs((robot1.z + deltaZ) - robot2.z) < 1)
					return true;
		}
		break;
	case 1:	//controlled robot
		if(fabs(deltaX) > 0) {
			if(fabs(robot1.z - robot2.z) < 1)
				if(fabs((robot2.x + deltaX) - robot1.x) < 1)
					return true;
		}
		else if(fabs(deltaZ) > 0) {
			if(fabs(robot1.x - robot2.x) < 1)
				if(fabs((robot2.z + deltaZ) - robot1.z) < 1)
					return true;
		}
		break;
	case 2:	//pew
		if(fabs(deltaX) > 0) {
			if(fabs(robot1.z - pew.z) < 1)
				if(fabs((pew.x + deltaX) - robot1.x) < 1)
					return true;
		}
		else if(fabs(deltaZ) > 0) {
			if(fabs(robot1.x - pew.x) < 1)
				if(fabs((pew.z + deltaZ) - robot1.z) < 1)
					return true;
		}
		break;
	}
	return false;
}

void display ()
{
	setCamera();

 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	//glEnable(GL_LIGHTING); //Enable lighting
	//glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1
	//glEnable(GL_LIGHT2); //Enable light #2	
	//glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 20);
	//glEnable(GL_NORMALIZE); //Automatically normalize normals

	if(cameraMode == 0) //For Orthogonal mode.
	{
		if(cameraReset)//Reset camera to starting point.
		{
			gluLookAt(0.00, 35.00, 35.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
			cameraReset = false;
		}
		else
			gluLookAt(0.00, 35.00, 35.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
	}


	else if(cameraMode == 1) //For Perspective mode.
	{
		if(cameraReset)//Reset camera to starting point.
		{
			gluLookAt(0.00, 35.00, 35.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
			cameraReset = false;
		}
		else
			gluLookAt(movX, movY +35.00, movZ +35.00, movX + rotX, movY + rotY, movZ + rotZ, 0.00, 1.00, 0.00);
	}

	else if(cameraMode == 2) //For Orbit mode.
	{
		if(cameraReset)//Reset camera to starting point.
		{
			gluLookAt(0.00, 35.00, 35.00, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
			cameraReset = false;
		}
		else
		{
			gluLookAt(eyeX, eyeY, eyeZ, 0.00, 0.00, 0.00, 0.00, 1.00, 0.00);
		}
	}

	else if(cameraMode == 3)//First person robot view.
	{
		//if(cameraReset)//Reset camera to starting point.
		//{
			gluLookAt(8.00, 1.50, -5.00, 8.00, 0.00, 1.00, 0.00, 1.00, 0.00);
			//cameraReset = false;
		//}
		//else
			//gluLookAt(8.00, 1.50, -5.00, 8.00, 0.00, 1.00, 0.00, 1.00, 0.00);
	}

	
	else if(cameraMode == 4)//First person lightpost 1 view
	{
		
		gluLookAt(23, 6.0, 23, 0, 0.1, 0, 0.00, 1.00, 0.00);
			
	}

	else if(cameraMode == 5)//First person lightpost 2 view
	{
		
		gluLookAt(23, 6.0, -23, 0, 0.1, 0, 0.00, 1, 0.00);
			
	}

	else if(cameraMode == 6) //First person lightpost 3 view
	{
		
		gluLookAt(-23, 6.0, 23, 0, 0.1, 0, 0.00, 1.00, 0.00);
			
	}

	else if(cameraMode == 7) //First person lightpost 4 view
	{
		gluLookAt(-23, 6.0, -23, 0, 0, 0, 0.00, 1.00, 0.00);
			
	}

	else if(cameraMode == 8) //Controller 3rd-person view
	{
		if(docked)
			gluLookAt(control.x - 25, 6, control.z + 10 - 25, control.x -25, 3.5, control.z - 25, 0.00, 1.00, 0.00);
		else
			gluLookAt(control.x - 25, 7, control.z + 10 - 25, control.x -25, 3.5, control.z - 25, 0.00, 1.00, 0.00);
	}


	
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
	lightPostConstruct l1 = lightPostConstruct();

	// Draw Skybox
	glPushMatrix();
		glTranslatef(25,0,25);
		glScalef(75,75,75);
		sky.draw();
	glPopMatrix();

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
				t1.draw(tileTex);
				glFlush();
				glPopMatrix();
			}

			//Draw standard tile and small rubble pile.
			else if(m1.getChar(i, j, 0) == 's')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				t1.draw(tileTex);
				glFlush();
				glPopMatrix();

				Image* image = loadBMP("debris.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				r1.drawSmall(shade, blockTexId2);
				glFlush();
				glPopMatrix();
			}

			//Draw standard tile and medium rubble pile.
			else if(m1.getChar(i, j, 0) == 'm')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				t1.draw(tileTex);
				glFlush();
				glPopMatrix();

				Image* image = loadBMP("debris.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				r1.drawMedium(shade, blockTexId2);
				glFlush();
				glPopMatrix();
			}

			//Draw standard tile and large rubble pile.
			else if(m1.getChar(i, j, 0) == 'l')
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				t1.draw(tileTex);
				glFlush();
				glPopMatrix();

				Image* image = loadBMP("debris.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				r1.drawLarge(shade, blockTexId2);
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit.
			else if(m1.getChar(i, j, 0) == 'h') //h = horizontal pit
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(90, 0, 1, 0); //rotate to horizontal position
				t1.drawHole();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit.
			else if(m1.getChar(i, j, 0) == 'v') //v = vertical pit
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				t1.drawHole();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'e') //e = east edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(-90, 0, 1, 0); //rotate to proper position
				t1.drawHoleEdge();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'w') //w = west edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(90, 0, 1, 0); //rotate to proper position
				t1.drawHoleEdge();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'n') //n = north edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				t1.drawHoleEdge();
				glFlush();
				glPopMatrix();
			}

			//Draw tile with pit edge.
			else if(m1.getChar(i, j, 0) == 'd') //d = south edge
			{
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(180, 0, 1, 0); //rotate to proper position
				t1.drawHoleEdge();
				glFlush();
				glPopMatrix();
			}

			//Draw plain half-block
			if(m1.getChar(i,j,1) == '1') {
				Image* image = loadBMP("mud.bmp"); //Create Image object with the .bmp
				blockTexId1 = loadTexture(image); //Store the texture from the object in texture variable.
				delete image; //Delete Image object.
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawPH(blockTexId1);
				glFlush();
				glPopMatrix();
			}

			//Draw plain full-block
			else if(m1.getChar(i,j,1) == '2') {
				Image* image = loadBMP("ice.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawPU(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			//Draw plain full-block (alternate texture)
			else if(m1.getChar(i,j,1) == '7') {
				Image* image = loadBMP("gold.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawPU(blockTexId2);
				glFlush();
				glPopMatrix();
			}
			
			//Draw holed half-block
			else if(m1.getChar(i,j,1) == '3'){
				Image* image = loadBMP("stone.bmp");
				blockTexId3 = loadTexture(image);
				delete image;

				Image* image2 = loadBMP("hole2.bmp");
				hole = loadTexture(image);
				delete image2;

				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawHH(blockTexId3, hole);
				glFlush();
				glPopMatrix();
			}
			
			//Draw holed full-block
			else if(m1.getChar(i,j,1) == '4') {
				Image* image = loadBMP("wood.bmp");
				blockTexId4 = loadTexture(image);
				delete image;

				Image* image2 = loadBMP("hole2.bmp");
				hole = loadTexture(image);
				delete image2;

				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawHU(blockTexId4, hole);
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

			//Draw HQ block
			else if(m1.getChar(i,j,1) == '@') {
				Image* image = loadBMP("camo1.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawHQ(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			//Draw Factory
			else if(m1.getChar(i,j,1) == '$') {
				Image* image = loadBMP("camo2.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				b1.drawF(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			// Draw light post 1 
			else if(m1.getChar(i,j,1) == '%') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(45,0,1,0);
				l1.draw();
				//l1.createLight();
				glFlush();
				glPopMatrix();
			}

			// Draw light post 2 
			else if(m1.getChar(i,j,1) == '^') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(135,0,1,0);
				l1.draw();
				//l1.createLight();
				glFlush();
				glPopMatrix();
			}

			// Draw light post 3 
			else if(m1.getChar(i,j,1) == '&') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(-45,0,1,0);
				l1.draw();
				//l1.createLight();
				glFlush();
				glPopMatrix();
			}

			// Draw light post 4
			else if(m1.getChar(i,j,1) == '*') {
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(-135,0,1,0);
				l1.draw();
				//l1.createLight();
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'b') {
				Image* image = loadBMP("steel.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				b2.draw(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'g') {
				Image* image = loadBMP("steel.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				g1.draw(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 't') {
				Image* image = loadBMP("steel.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				t2.draw(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'e') {
				Image* image = loadBMP("metal.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				e1.draw(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'c') {
				Image* image = loadBMP("metal.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				c2.draw(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'p') {
				Image* image = loadBMP("metal.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				glRotatef(-90,1,0,0);
				p1.draw(shade, blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'n') {
				Image* image = loadBMP("metal.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				n1.draw(shade, blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'm') {
				Image* image = loadBMP("metal.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				m2.draw(shade, blockTexId2);
				glFlush();
				glPopMatrix();
			}

			else if(m1.getChar(i,j,1) == 'r') {
				Image* image = loadBMP("metal.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0.5, j);
				g1.draw(blockTexId2);
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 1.0, j);
				c2.draw(blockTexId2);
				glFlush();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(i, 2.0, j);
				e1.draw(blockTexId2);
				glFlush();
				glPopMatrix();
			}

			if (m1.getChar(i,j,2) == '1') {
				Image* image = loadBMP("cgold.bmp");
				blockTexId2 = loadTexture(image);
				delete image;
				glPushMatrix();
				glTranslatef(i, 0, j);
				c1.draw(shade,blockTexId2);
				glFlush();
				glPopMatrix();
			}

		}
	}

	
	// moving object section
	
	// NPC robot
	if(!destroyed) {
		glPushMatrix();
			switch(dRobot1) {
			case NORTH:
				glPushMatrix();
					glTranslatef(robot1.x, 0, robot1.z);
					glRotatef(180,0,1,0);
					glPushMatrix();
						glTranslatef(0, 0.5,0);
						g1.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 1.0, 0);
						c2.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 2.0, 0);
						e1.draw(tex1);
						glFlush();
					glPopMatrix();
				glPopMatrix();
				break;
			case SOUTH:
				glPushMatrix();
					glTranslatef(robot1.x, 0, robot1.z);
					glPushMatrix();
						glTranslatef(0, 0.5, 0);
						g1.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 1.0, 0);
						c2.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 2.0, 0);
						e1.draw(tex1);
						glFlush();
					glPopMatrix();
				glPopMatrix();
				break;
			case EAST:
				glTranslatef(robot1.x, 0, robot1.z);
				glRotatef(90,0,1,0);
				glPushMatrix();
					glPushMatrix();
						glTranslatef(0, 0.5, 0);
						g1.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 1.0, 0);
						c2.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 2.0, 0);
						e1.draw(tex1);
						glFlush();
					glPopMatrix();
				glPopMatrix();
				break;
			case WEST:
				glPushMatrix();
					glTranslatef(robot1.x, 0, robot1.z);
					glRotatef(-90,0,1,0);
					glPushMatrix();
						glTranslatef(0, 0.5,0);
						g1.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 1.0, 0);
						c2.draw(tex1);
						glFlush();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0, 2.0, 0);
						e1.draw(tex1);
						glFlush();
					glPopMatrix();
				glPopMatrix();
				break;
			}
		glPopMatrix();
	}
	else {
		Image* image = loadBMP("debris.bmp");
		blockTexId2 = loadTexture(image);
		delete image;
		glPushMatrix();
		glTranslatef(robot1.x, 0, robot1.z);
		r1.drawLarge(shade, blockTexId2);
		glFlush();
		glPopMatrix();
	}
	
	// Player-controlled Controller
	glPushMatrix();
		if(docked)
			glTranslatef(control.x, 2, control.z);
		else
			glTranslatef(control.x, 3, control.z);
		c1.draw(shade, tex3);
		glFlush();
	glPopMatrix();

	// Player-controllable robot
	if(docked) {
		robot2.x = control.x;
		robot2.z = control.z;
	}

	switch(dRobot2) {
	case NORTH:
		glPushMatrix();
			glTranslatef(robot2.x, 0, robot2.z);
			glRotatef(180,0,1,0);
			glPushMatrix();
				glTranslatef(0,0,0);
				b2.draw(tex2);
				glFlush();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, 1.0, 0);
				c2.draw(tex2);
				glFlush();
			glPopMatrix();
		glPopMatrix();
		break;

	case SOUTH:
		glPushMatrix();
			glTranslatef(robot2.x, 0, robot2.z);
			glPushMatrix();
				glTranslatef(0,0,0);
				b2.draw(tex2);
				glFlush();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, 1.0, 0);
				c2.draw(tex2);
				glFlush();
			glPopMatrix();
		glPopMatrix();
		break;

	case EAST:
		glPushMatrix();
			glTranslatef(robot2.x, 0, robot2.z);
			glRotatef(90,0,1,0);
			glPushMatrix();
				glTranslatef(0,0,0);
				b2.draw(tex2);
				glFlush();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, 1.0, 0);
				c2.draw(tex2);
				glFlush();
			glPopMatrix();
		glPopMatrix();
		break;

	case WEST:
		glPushMatrix();
			glTranslatef(robot2.x, 0, robot2.z);
			glRotatef(-90,0,1,0);
			glPushMatrix();
				glTranslatef(0,0,0);
				b2.draw(tex2);
				glFlush();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, 1.0, 0);
				c2.draw(tex2);
				glFlush();
			glPopMatrix();
		glPopMatrix();
		break;
	}

	// Pew
	if(pewpew) {
		glPushMatrix();
			glTranslatef(pew.x, 1.5, pew.z);
			glRotated(spin, 1, 0, 0);
			glScalef(.25,.25,.25);
			glutSolidIcosahedron();
		glPopMatrix();
	}

	glEnable(GL_DEPTH_TEST);
	
	/*glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);*/

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

//orbit() - Based on Mouse Coordinates function by H. Shirokawa.
//http://homepages.ius.edu/rwisman/b481/html/notes/FlyAround.htm
void orbit()
{
// Coordinate to angle conversion
  double theta = (360.0/HEIGHT)*40*3.0;
  double phi = (360.0/WIDTH)*orbX*3.0;

// Convert spherical coordinates to eye coordinates.
   eyeX = r * sin(theta*ORBSTEP)* sin(phi*ORBSTEP);
   eyeY = r * cos(theta*ORBSTEP);
   eyeZ = r * sin(theta*ORBSTEP)* cos(phi*ORBSTEP);

	glutPostRedisplay();
}

void mouseCam(int x, int y)
{
	if(cameraMode == 1 && mouseControls != 0)
	{
		if(x > originX) //Mouse moves to the 'right' of origin.
		{
			rotX += STEP; //Rotate camera right.
			originX = x; //Update origin.
		}
		else
		{
			rotX -= STEP; //Rotate camera left.
			originX = x; //Update origin.
		}

		if(y < originY) //Mouse moves 'below' origin
		{
			rotY += STEP; //Rotate camera downwards.
			originY = y; //Update origin.
		}
		else
		{
			rotY -= STEP; //Rotate camera upwards.
			originY = y; //Update origin.
		}
	}

	glutPostRedisplay();
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	GLuint temp;
	switch (key)
	{

	case 27: //Escape key
		exit(0);
	case '/':
		temp = tex1;
		tex1 = tex2;
		tex2 = temp;
		//These controls only work in Perspective Mode (a and d also work in Orbit Mode & WASD switched to controller controls).
	case 13: //Enter key
		if(docked == false) {
			if(robot2.x == control.x && robot2.z == control.z) {
				PlaySound("dock.wav",NULL,SND_FILENAME|SND_ASYNC);
				docked = true;
			}
		}
		else {
			PlaySound("undock.wav",NULL,SND_FILENAME|SND_ASYNC);
			docked = false;
		}
		break;
	case 32: //Space key
		if(docked) {
			switch(dRobot2) {
			case NORTH:
				pew.x = control.x;
				pew.z = control.z - 1;
				dPew = NORTH;
				break;

			case SOUTH:
				pew.x = control.x;
				pew.z = control.z + 1;
				dPew = SOUTH;
				break;

			case EAST:
				pew.x = control.x + 1;
				pew.z = control.z;
				dPew = EAST;
				break;

			case WEST:
				pew.x = control.x - 1;
				pew.z = control.z;
				dPew = WEST;
				break;
			}
			tempX = pew.x;
			tempZ = pew.z;
		}
		if(!pewpew)
			PlaySound("pew.wav",NULL,SND_FILENAME|SND_ASYNC);
		pewpew = true;
		break;
	case 'a':
		if(cameraMode == 1)
			movX -= STEP;
		else if(cameraMode == 2)
		{
			orbX -= STEP;
			orbit();
		}
		else if(cameraMode == 8) {
			if(docked) {
				dRobot2 = WEST;
				if(willCollide(1, -fabs(.25), 0) == false)
					control.x -= .25;
			}
			else
				control.x -= .5;
		}
		break;

	case 'd':
		if(cameraMode == 1)
			movX += STEP;
		else if(cameraMode == 2)
		{
			orbX += STEP;
			orbit();
		}
		else if(cameraMode == 8) {
			if(docked) {
				dRobot2 = EAST;
				if(willCollide(1, fabs(.25), 0) == false)
					control.x += .25;
			}
			else
				control.x += .5;
		}
		break;

	case 'w':
		if(cameraMode == 1)
			movZ -= STEP;
		else if(cameraMode == 8) {
			if(docked) {
				dRobot2 = NORTH;
				if(willCollide(1, 0, -fabs(.25)) == false)
					control.z -= .25;
			}
			else
				control.z -= .5;
		}
		break;

	case 's':
		if(cameraMode == 1)
			movZ += STEP;
		else if(cameraMode == 8) {
			if(docked) {
				dRobot2 = SOUTH;
				if(willCollide(1, 0, fabs(.25)) == false)
					control.z += .25;
			}
			else
				control.z += .5;
		}
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
	case '=':
		zoom('+');
		break;

	case '-':
		zoom('-');
		break;

	case 'c':
		if(cameraMode != 8)
			cameraMode++;
		else
			cameraMode = 0;
		break;
	case '0':
		cameraMode = 0;
		break;
	case '1':
		cameraMode = 1;
		break;
	case '2':
		cameraMode = 2;
		break;
	case '3':
		cameraMode = 3;
		break;
	case '4':
		cameraMode = 4;
		break;
	case '5':
		cameraMode = 5;
		break;
	case '6':
		cameraMode = 6;
		break;
	case '7':
		cameraMode = 7;
		break;
	case '8':
		cameraMode = 8;
		break;
	case 'm':
		if(mouseControls == 0)
			mouseControls++;
		else
			mouseControls = 0;
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
		switch(shade) {
			case FLAT: 
			shade = WIRE;
			break;
		case WIRE:
			shade = SMOOTH;
			break;
		case SMOOTH:
			shade = FLAT;
			break;
		}

		switch(shade) {
			case FLAT: 
			glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);	// Solid
			glShadeModel(GL_FLAT);
			break;
		case WIRE:
			glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);	// Wireframes
			break;
		case SMOOTH:
			glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
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

				else if(cameraMode == 0)//Orthogonal Mode
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

				else if(cameraMode == 0)
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

				else if(cameraMode == 0)
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

				else if(cameraMode == 0)
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
			case GLUT_KEY_F11:
				fullscreen = !fullscreen;
				if (fullscreen)
					glutFullScreen();
				else
				{
					glutReshapeWindow(width, height);
					glutPositionWindow(10,30);
				}
				break;
	   }

   	glutPostRedisplay();
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void timedStuff(int value) {
	// NPC robot movement
	if(!destroyed) {
		if(robot1Count < 12) {
			dRobot1 = SOUTH;
			if (willCollide(0, 0, fabs(.25)) == false) {
				robot1.z += .25;
				robot1Count++;
			}
		}
		else if(robot1Count < 24) {
			dRobot1 = EAST;
			if (willCollide(0, fabs(.25), 0) == false) {
				robot1.x += .25;
				robot1Count++;
			}
		}
		else if(robot1Count < 36) {
			dRobot1 = NORTH;
			if (willCollide(0, 0, -fabs(.25)) == false) {
				robot1.z -= .25;
				robot1Count++;
			}
		}
		else if(robot1Count < 48) {
			dRobot1 = WEST;
			if (willCollide(0, -fabs(.25), 0) == false) {
				robot1.x -= .25;
				robot1Count++;
			}
		}
		else {
			robot1Count = 0;
		}
	}

	if(pewpew) {
		switch(dPew) {
			case NORTH:
				if(willCollide(2, 0, -fabs(.25))) {
					pewpew = false;
					health--;
					if(health <= 0) {
						if(!destroyed)
							PlaySound("explode.wav",NULL,SND_FILENAME|SND_ASYNC);
						destroyed = true;
					}
					pewD = .25;
				}
				else {
					pewD += .25;
					pew.z = tempZ - pewD;
				}
				break;

			case SOUTH:
				if(willCollide(2, 0, fabs(.25))) {
					pewpew = false;
					health--;
					if(health <= 0) {
						if(!destroyed)
							PlaySound("explode.wav",NULL,SND_FILENAME|SND_ASYNC);
						destroyed = true;
					}
					pewD = .25;
				}
				else {
					pewD += .25;
					pew.z = tempZ + pewD;
				}
				break;

			case EAST:
				if(willCollide(2, fabs(.25), 0)) {
					pewpew = false;
					health--;
					if(health <= 0) {
						if(!destroyed)
							PlaySound("explode.wav",NULL,SND_FILENAME|SND_ASYNC);
						destroyed = true;
					}
					pewD = .25;
				}
				else {
					pewD += .25;
					pew.x = tempX + pewD;
				}
				break;

			case WEST:
				if(willCollide(2, -fabs(.25), 0)) {
					pewpew = false;
					health--;
					if(health <= 0) {
						if(!destroyed)
							PlaySound("explode.wav",NULL,SND_FILENAME|SND_ASYNC);
						destroyed = true;
					}
					pewD = .25;
				}
				else {
					pewD += .25;
					pew.x = tempX - pewD;
				}
				break;
			}
		if((int)pewD == 3) {
			pewpew = false;
			pewD = .25;
		}
		spin += 10;
		if(spin == 360)
			spin = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(5, timedStuff, 0);
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
	glutMotionFunc(mouseCam);
	glutReshapeFunc(handleResize);
	glutTimerFunc(0, timedStuff,0);

	glShadeModel(GL_FLAT);
	
	sky = SkyBox();
	im = loadBMP("trust.bmp");
	tileTex = loadTexture(im);
	im = loadBMP("steel.bmp");
	tex1 = loadTexture(im);
	im = loadBMP("metal.bmp");
	tex2 = loadTexture(im);
	im = loadBMP("cgold.bmp");
	tex3 = loadTexture(im);
	delete im;

	robot1.x = 15.000; robot1.z = 30.000;
	robot2.x = 25.000; robot2.z = 30.000;
	control.x = 30.000; control.z = 30.000;

	glutMainLoop();
	return 0;
}