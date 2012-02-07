//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 1
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the phaser constructing class

#include "Phaser.h" 
#include <GL/glut.h> 

Phaser::Phaser(void)
{
}

Phaser::~Phaser(void)
{
}

// This function is called to display the scene.
void Phaser::draw()
{
	GLUquadricObj *disk;

	disk = gluNewQuadric ( );
	gluQuadricDrawStyle (disk, GLU_FILL);

	// Situate the robot weapon at the right Y location
	glTranslatef(0,1,0);
	glScalef(1.5,1.5,1.5);

	// Push the entire object
	glPushMatrix();

		// The cube
		glPushMatrix();

			glColor3f(1,0,0);
			glTranslatef(0,0.25,0.1);
			glScalef(1,.5,.5);
			glutSolidCube(.6);
		
		glPopMatrix();
		
		// The base cylinder
		glPushMatrix();

			// Drawing the top cap
			glPushMatrix();
				glColor3f( 0, 0, 1 );	

				glTranslatef(0.0,0,0.15);
				// Parameters: quadObj, 
				gluDisk(disk, 0.0,.5, 10, 5);

				glPushMatrix();
					glRotatef(90, 1, 0, 0);
					glTranslatef(-0.2, -0.05, 0);
					glScalef(0.5, 0.5, 0.5);
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

			// The Main cylinder
			glPushMatrix();
				glColor3f( 0.0, 0, 0.80 );					
				// Parameters: height, radius, slices, stacks
				gluCylinder(disk, .5, .5, .15, 15, 20);
			glPopMatrix();

			// The Barrel
			glPushMatrix();
				glColor3f( .8, 0, 0 );	
				glRotatef(90,1,0,0);
				glTranslatef(0,0.25,-.25);
				// Parameters: height, radius, slices, stacks
				gluCylinder(disk, .1, .1, .6, 15, 20);
			glPopMatrix();

			// Drawing the bottom cap
			glPushMatrix();
				glColor3f( 0, 0, 1 );	

				// Parameters: quadObj,
				glTranslatef(0.0,0,0.01);
				gluDisk(disk, 0.0, .5, 10, 5);
			glPopMatrix();	

		glPopMatrix();

	// Pop the entire project
	glPopMatrix();
}

// Drawing the team number
/*
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
*/
