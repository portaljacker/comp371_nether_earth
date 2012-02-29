//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the light post constructing class

#include "lightPostConstruct.h"
#include <GL/glut.h>
#include <math.h>

// Constant look at point of the light and the camera
const GLfloat lookAtPoint = 3.0 * sqrt(2.0);

// Constructor
lightPostConstruct::lightPostConstruct(void)
{
}

// Destructor
lightPostConstruct::~lightPostConstruct(void)
{
}

// function for drawing a light construct
void lightPostConstruct::draw()
{
	GLUquadricObj *cylinder;

	// New Quadric object
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_FILL);

	// Orient the light post along the y axis
	glRotatef(-90,1,0,0);

	/* Situate the light post at a 45 degree angle from the scene
	// **NECESSARY WHEN PLACING ON THE MAP**
	//glRotatef(45,0,1,0);
	*/

	// The Light Post Construct
	glPushMatrix();

		// Drawing the scaled square light post base
		glPushMatrix();

			glColor3f( 0.5, 0.5, 0.5); 
			glutSolidCube(.5);

		glPopMatrix();

		// Drawing the cylinder post
		glPushMatrix();

			glColor3f( 0.5, 0.5, 0.5); 
			gluCylinder(cylinder, .15, .15, 6, 10, 12);

		glPopMatrix();

		// Drawing the spherical cylinder connector
		glPushMatrix();

			glColor3f( 0.5, 0.5, 0.5); 
			glTranslatef(0,0,6);
			// Radius = .25 (d=.5)
			glutSolidSphere(.25,20,20);

		glPopMatrix();

		// The Cone 
		glPushMatrix();

			glColor3f(0.5, 0.5, 0.5); // Color
			glTranslatef(0,0,6); // Translate
			glRotatef(90,1,0,0); // Rotate
			//       obj   bottom .15  top .65  ht  slices stacks
			gluCylinder(cylinder, .15, .65, 1, 10, 12);
			
		glPopMatrix();

		// The Area Light
		glPushMatrix();

			// First Bulb
			glPushMatrix();

				// Semi-transparent white bulb
				glTranslatef(0,-1.05,6.1);
				glColor3f(1.0, 1.0, 1.0);
				glutSolidSphere(0.1,30,30);

			glPopMatrix();
				
			// Second bulb
			glPushMatrix();
					
				// Semi-transparent white bulb
				glTranslatef(.3, -1.05, 5.9);
				glColor3f(1.0, 1.0, 1.0);
				glutSolidSphere(.1,30,30);

			glPopMatrix();

			// Third bulb
			glPushMatrix();

				// Semi-transparent white bulb
				glTranslatef(-.3, -1.05, 5.9);
				glColor3f(1.0, 1.0, 1.0);
				glutSolidSphere(.1,30,30);
				
			glPopMatrix();

		glPopMatrix();

	// Pop the entire light post object
	glPopMatrix();
	
}

// Customized initialize function
void lightPostConstruct::createLight(void)
{
	glEnable(GL_LIGHTING);
	// Enable the light source (from the post)
	glEnable(GL_LIGHT0);

	/*
	
	// Ambient -- used for testing
	glEnable(GL_LIGHT1);
	GLfloat ambientLight[] = {0.6, 0.6, 0.6, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	*/

	// Specular light set to 'dim'
	GLfloat specularLight[] = {1.5, 0.5, 0.5, 1.0};
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	// Diffuse light property set
	GLfloat diffLight[] = {0.5, 0.5, 0.5, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffLight);

	// Used to compare each incoming pixel depth value with the depth value
	// present in the depth buffer
	//glDepthFunc(GL_LESS);   //--- necessary? ---
	// GL_LESS -> passes if the incoming depth value is less than the stored depth value 

	// Define the position of the light
	GLfloat lightpos[] = { 0, 6.0, 1.055, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	// Define the look at point of the light
	GLfloat spotDir[] = { lookAtPoint, 0, lookAtPoint};
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);

	// Define the intensity of light (def= 25)
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 150);
	
	// Define the Cutt-Off angle   (12.5 * 2 = 25)
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 12.5);

	// Enable the depth test -- testing --
	//glEnable(GL_DEPTH_TEST);
}

/*
void specialFuncKeys(unsigned char key, int x, int y)
{

	switch(key)
	{
		// Open the light source 
		case 'o'
			glEnable(GL_LIGHT0);
		// Close the light source 
		case 'O'
			glDisable(GL_LIGHT0);
	}

}
*/