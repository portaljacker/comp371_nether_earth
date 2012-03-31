//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
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
void Nuke::draw(Shade shade, GLuint tex)
{
	glPushMatrix();
	//glEnable(GL_LIGHTING); //Enable lighting
	//glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	//Add ambient light
	GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 0.5f}; 
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add directed light
	GLfloat lightColor1[] = {0.85f, 0.85f, 0.85f, 1.0f}; 
	GLfloat lightPos1[] = {0.0f, 2.0f, -3.0f, 0.0f};
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	GLUquadricObj *cylinder;

	cylinder = gluNewQuadric ( );
	gluQuadricDrawStyle (cylinder, GLU_FILL);

	switch (shade) {
	case FLAT:
		gluQuadricNormals(cylinder, GL_FLAT);
		break;
	case WIRE:
		gluQuadricNormals(cylinder, GL_TRUE);
		break;
	case SMOOTH:
		gluQuadricNormals(cylinder, GL_SMOOTH);
		break;
	}
	gluQuadricTexture(cylinder, GL_TRUE);
	// Situate the robot weapon at the right Y location
	glTranslatef(0,2,0);

	glRotatef(90,1,0,0);

	// Nuke Body
		// Drawing the top disk
		glPushMatrix();
			//glColor3f( 1, 0.0, 0.0 );	
			
			glTranslatef(0, 0, -0.1);
			// Parameters: quadObj, inner rad, outer rad, slices, stacks
			gluDisk(cylinder, 0.0, .25, 10, 5);
		glPopMatrix();

		// Drawing the top cap
		glPushMatrix();
			//glColor3f( 0, 0, 1 );	

			glTranslatef(0.0,0,0.76);
			// Parameters: quadObj, 
			gluDisk(cylinder, 0.0, .75, 10, 5);
		glPopMatrix();

		// Drawing the cylinder frame
		glPushMatrix();
			//glColor3f( 0.0, 0.5, 0.0 );					
			// Parameters: height, radius, slices, stacks
			gluCylinder(cylinder, .75 ,0.75, 0.8, 10, 10 );
		glPopMatrix();

		// Drawing the bottom cap
		glPushMatrix();
			//glColor3f( 0, 0, 1 );	

			// Parameters: quadObj, inner rad, outer rad, slices, stacks
			gluDisk(cylinder, 0.0, .75, 10, 5);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90, 1, 0, 0);
			glBegin(GL_QUADS);

			glColor3d(1,1,1);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.1f, 0.12f, 0.1f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.1f, 0.12f, 0.2f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.1f, 0.12f, 0.2f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.1f, 0.12f, 0.1f);

			//glColor3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.0f, 0.12f, -0.15f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.0f, 0.12f, 0.3f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.1f, 0.12f, 0.3f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.1f, 0.12f, -0.15f);

			//glColor3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.25f, 0.12f, -0.15f);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.25f, 0.12f, 0.2f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.1f, 0.12f, 0.2f);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.1f, 0.12f, -0.15f);

			glEnd();
		glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	//glDisable(GL_LIGHTING);	

	glPopMatrix();
}

