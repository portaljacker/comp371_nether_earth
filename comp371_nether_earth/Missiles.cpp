//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the Nuke constructing class

#include "Cube.h"
#include "Missiles.h"
#include <GL/glut.h>

Missiles::Missiles(void)
{
}

Missiles::~Missiles(void)
{
}

void Missiles::draw(Shade shade, GLuint tex)
{
	//Push entire object
	glPushMatrix();
	//glEnable(GL_LIGHTING); //Enable lighting
	//glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	////Add ambient light
	//GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 0.5f}; 
	////glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	//
	////Add directed light
	//GLfloat lightColor1[] = {0.85f, 0.85f, 0.85f, 1.0f}; 
	//GLfloat lightPos1[] = {0.0f, 2.0f, -3.0f, 0.0f};
	//glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
	//glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	GLUquadricObj *disk;

	disk = gluNewQuadric ( );
	gluQuadricDrawStyle (disk, GLU_FILL);

	switch (shade) {
	case FLAT:
		gluQuadricNormals(disk, GL_FLAT);
		break;
	case WIRE:
		gluQuadricNormals(disk, GL_TRUE);
		break;
	case SMOOTH:
		gluQuadricNormals(disk, GL_SMOOTH);
		break;
	}
	gluQuadricTexture(disk, GL_TRUE);
	// Situate the robot weapon at the right Y location
	//glTranslatef(0,1,0);

	// Translate entire object
	glTranslatef(0,0.1,0);
	glScalef(1.5,1.5,1.5);

		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

		// The base cube
		glPushMatrix();

			//glColor3f(0,0,1);
			glTranslatef(0,0.01,0);
			glScalef(.8,.2,.8);
			glScalef(0.75,.75,.75);
			pj::cube();

		glPopMatrix();

		// The gunnery turret
		glPushMatrix();

			//glColor3f(0,1,1);
			glTranslatef(0,0.2,0);
		
			glScalef(.25,.25,.25);
			pj::cube();

			glPushMatrix();
				glTranslatef(0.0, 0.1, 0.0);
				glScalef(0.5, 0.5, 0.5);
				glBegin(GL_QUADS);

				glColor3d(1,1,1);
				glVertex3f(-0.1f, 0.12f, 0.1f);
				glVertex3f(-0.1f, 0.12f, 0.2f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(0.1f, 0.12f, 0.2f);
				glVertex3f(0.1f, 0.12f, 0.1f);

				//glColor3f(0.0f, 0.0f, 0.0f);
				glVertex3f(-0.0f, 0.12f, -0.15f);
				glVertex3f(-0.0f, 0.12f, 0.3f);
				glVertex3f(0.1f, 0.12f, 0.3f);
				glVertex3f(0.1f, 0.12f, -0.15f);

				//glColor3f(0.0f, 0.0f, 0.0f);
				glVertex3f(-0.25f, 0.12f, -0.15f);
				glVertex3f(-0.25f, 0.12f, 0.2f);
				glVertex3f(-0.1f, 0.12f, 0.2f);
				glVertex3f(-0.1f, 0.12f, -0.15f);

				glEnd();
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();

				// The Barrel 1
				glPushMatrix();
					//glColor3f( .8, 0, 0 );	
					glTranslatef(-.14,.2,0);
					// Parameters: height, radius, slices, stacks
					gluCylinder(disk, .04, .04, .3, 15, 20);
				glPopMatrix();

				// The Barrel 2 
				glPushMatrix();
					//glColor3f( 1, 0, 0 );	
					glTranslatef(.14,0.2,0);
					// Parameters: height, radius, slices, stacks
					gluCylinder(disk, .04, .04, .3, 15, 20);
				glPopMatrix();

		glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	//glDisable(GL_LIGHTING);
	glPopMatrix();
}
