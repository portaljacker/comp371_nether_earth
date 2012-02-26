//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 2
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Nuke constructing class

#include "Nuke.h"
#include <GL/glut.h>

// The GLU Quadric variable necessary for generating cylinders

Nuke::Nuke(void)
{
}

Nuke::~Nuke(void)
{
}

// The draw function for the nuke weapon
void Nuke::draw()
{
	//Add directed light
	GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {0.0f, 1.0f, 1.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
	
	GLUquadricObj *cylinder;

	cylinder = gluNewQuadric ( );
	gluQuadricDrawStyle (cylinder, GLU_FILL);

	// Situate the robot weapon at the right Y location
	glTranslatef(0,2,0);

	glRotatef(90,1,0,0);

	// Nuke Body
	glPushMatrix();

		// Drawing the top disk
		glPushMatrix();
			glColor3f( 1, 0.0, 0.0 );	
			
			glTranslatef(0, 0, -0.1);
			// Parameters: quadObj, inner rad, outer rad, slices, stacks
			gluDisk(cylinder, 0.0, .25, 10, 5);
		glPopMatrix();

		// Drawing the top cap
		glPushMatrix();
			glColor3f( 0, 0, 1 );	

			glTranslatef(0.0,0,0.76);
			// Parameters: quadObj, 
			gluDisk(cylinder, 0.0, .75, 10, 5);
		glPopMatrix();

		// Drawing the cylinder frame
		glPushMatrix();
			glColor3f( 0.0, 0.5, 0.0 );					
			// Parameters: height, radius, slices, stacks
			gluCylinder(cylinder, .75 ,0.75, 0.8, 10, 10 );
		glPopMatrix();

		// Drawing the bottom cap
		glPushMatrix();
			glColor3f( 0, 0, 1 );	

			// Parameters: quadObj, inner rad, outer rad, slices, stacks
			gluDisk(cylinder, 0.0, .75, 10, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90, 1, 0, 0);
			glBegin(GL_QUADS);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.1f, 0.12f, 0.1f);
			glVertex3f(-0.1f, 0.12f, 0.2f);
			glVertex3f(0.1f, 0.12f, 0.2f);
			glVertex3f(0.1f, 0.12f, 0.1f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.0f, 0.12f, -0.15f);
			glVertex3f(-0.0f, 0.12f, 0.3f);
			glVertex3f(0.1f, 0.12f, 0.3f);
			glVertex3f(0.1f, 0.12f, -0.15f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.25f, 0.12f, -0.15f);
			glVertex3f(-0.25f, 0.12f, 0.2f);
			glVertex3f(-0.1f, 0.12f, 0.2f);
			glVertex3f(-0.1f, 0.12f, -0.15f);

			glEnd();
		glPopMatrix();

	glPopMatrix();
	
}

