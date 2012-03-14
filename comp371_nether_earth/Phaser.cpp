//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
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
void Phaser::draw(Shade shade, GLuint tex)
{
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	//Add ambient light
	GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 0.5f}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add directed light
	GLfloat lightColor1[] = {0.85f, 0.85f, 0.85f, 1.0f}; 
	GLfloat lightPos1[] = {0.0f, 2.0f, -3.0f, 0.0f};
	glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
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

	// Situate the robot weapon at the right Y location
	glTranslatef(0,1,0);
	glScalef(1.5,1.5,1.5);

	// Push the entire object
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);

		// The cube
		glPushMatrix();

			//glColor3f(1,0,0);
			glTranslatef(0,0.25,0.1);
			glScalef(1,.5,.5);
			glutSolidCube(.6);
		
		glPopMatrix();
		
		// The base cylinder
		glPushMatrix();

			// Drawing the top cap
			glPushMatrix();
				//glColor3f( 0, 0, 1 );	

				glTranslatef(0.0,0,0.15);
				// Parameters: quadObj, 
				gluDisk(disk, 0.0,.5, 10, 5);

				glPushMatrix();
					glRotatef(90, 1, 0, 0);
					glTranslatef(-0.2, -0.05, 0);
					glScalef(0.5, 0.5, 0.5);
					glBegin(GL_QUADS);

					//glColor3f(0.0f, 1.0f, 0.0f);
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
			glPopMatrix();	

			// The Main cylinder
			glPushMatrix();
				//glColor3f( 0.0, 0, 0.80 );					
				// Parameters: height, radius, slices, stacks
				gluCylinder(disk, .5, .5, .15, 15, 20);
			glPopMatrix();

			// The Barrel
			glPushMatrix();
				//glColor3f( .8, 0, 0 );	
				glRotatef(90,1,0,0);
				glTranslatef(0,0.25,-.25);
				// Parameters: height, radius, slices, stacks
				gluCylinder(disk, .1, .1, .6, 15, 20);
			glPopMatrix();

			// Drawing the bottom cap
			glPushMatrix();
				//glColor3f( 0, 0, 1 );	

				// Parameters: quadObj,
				glTranslatef(0.0,0,0.01);
				gluDisk(disk, 0.0, .5, 10, 5);
			glPopMatrix();	

		glPopMatrix();

	// Pop the entire project
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
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
