//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment 3
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This is the block class. It creates buildings and building components.

#include "Block.h"

Block::Block(void)
{
}


Block::~Block(void)
{
}

void Block::drawPH(GLuint tex) {	// plain half-block
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		//glColor3ub(250, 125, 32); //Color disabled for textures.

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
			glTranslatef(0.0, 0.25, 0.0);
			glScalef(1.0, 0.5, 1.0);
			//glutSolidCube(1.0); //Initial render, now replaced with QUADS.
			glPushMatrix();
				glBegin(GL_QUADS);
				glPushMatrix();
					glNormal3f(0.0, 0.0, 1.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5); //Top Right
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5); //Top Left
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5); //Bottom Left
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5); //Bottom Right
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 0.0, -1.0);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(-1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, -1.0, 0.0);
					glVertex3f( 0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5,-0.5);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 1.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5, 0.5, 0.5);
				glPopMatrix();
				glEnd();
			glPopMatrix();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Block::drawPU(GLuint tex) {	// plain full-block

	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		//glColor3ub(184, 134, 11); //Color disabled for textures.

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
			glTranslatef(0.0, 0.5, 0.0);
			//glutSolidCube(1.0); //Initial render, now replaced with QUADS.
			glPushMatrix();
				glBegin(GL_QUADS);
				glPushMatrix();
					glNormal3f(0.0, 0.0, 1.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5); //Top Right
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5); //Top Left
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5); //Bottom Left
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5); //Bottom Right
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 0.0, -1.0);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(-1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, -1.0, 0.0);
					glVertex3f( 0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5,-0.5);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 1.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5, 0.5, 0.5);
				glPopMatrix();
				glEnd();
			glPopMatrix();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Block::drawHH(GLuint tex) {	// holed half-block
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		//glColor3ub(160, 82, 45); //Color disabled for textures.

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
			glTranslatef(0.0, 0.25, 0.0);
			glScalef(1.0, 0.5, 1.0);
			//glutSolidCube(1.0); //Initial render, now replaced with QUADS.
			glPushMatrix();
				glBegin(GL_QUADS);
				glPushMatrix();
					glNormal3f(0.0, 0.0, 1.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5); //Top Right
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5); //Top Left
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5); //Bottom Left
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5); //Bottom Right
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 0.0, -1.0);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(-1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, -1.0, 0.0);
					glVertex3f( 0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5,-0.5);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 1.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5, 0.5, 0.5);
				glPopMatrix();
				glEnd();
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(0.0, 0.501, 0.0);
			glBegin(GL_QUADS);
				glVertex3f(0.3, 0.0, 0.3);
				glVertex3f(0.3, 0.0, -0.3);
				glVertex3f(-0.3, 0.0, -0.3);
				glVertex3f(-0.3, 0.0, 0.3);
			glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Block::drawHU(GLuint tex) {	// holed full-block
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		//glColor3ub(160, 82, 45); //Color Disabled for textures.

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
			glTranslatef(0.0, 0.5, 0.0);
			//glutSolidCube(1.0); //Initial render, now replaced with QUADS.
			glPushMatrix();
				glBegin(GL_QUADS);
				glPushMatrix();
					glNormal3f(0.0, 0.0, 1.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5); //Top Right
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5); //Top Left
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5); //Bottom Left
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5); //Bottom Right
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 0.0, -1.0);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(-1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, -1.0, 0.0);
					glVertex3f( 0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5,-0.5);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 1.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5, 0.5, 0.5);
				glPopMatrix();
				glEnd();
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			glTranslatef(0.0, 1.001, 0.0);
			glBegin(GL_QUADS);
				glVertex3f(0.3, 0.0, 0.3);
				glVertex3f(0.3, 0.0, -0.3);
				glVertex3f(-0.3, 0.0, -0.3);
				glVertex3f(-0.3, 0.0, 0.3);
			glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Block::drawHQ(GLuint tex) {	// plain half-block
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		//glColor3ub(139, 50, 0); Color disabled for textures.

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glPushMatrix();
			glTranslatef(0.0, 0.5, 0.0);
			//glutSolidCube(1.0); //Initial render, now replaced with QUADS.
			glPushMatrix();
				glBegin(GL_QUADS);
				glPushMatrix();
					glNormal3f(0.0, 0.0, 1.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5); //Top Right
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5); //Top Left
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5); //Bottom Left
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5); //Bottom Right
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 0.0, -1.0);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(-1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5,-0.5,-0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f(-0.5,-0.5, 0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(1.0, 0.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f( 0.5, 0.5, 0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f( 0.5,-0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, -1.0, 0.0);
					glVertex3f( 0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5, 0.5);
					glVertex3f(-0.5,-0.5,-0.5);
					glVertex3f( 0.5,-0.5,-0.5);
				glPopMatrix();
				
				glPushMatrix();
					glNormal3f(0.0, 1.0, 0.0);
					glTexCoord2f(1.0f, 1.0f);
					glVertex3f( 0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 1.0f);
					glVertex3f(-0.5, 0.5,-0.5);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-0.5, 0.5, 0.5);
					glTexCoord2f(1.0f, 0.0f);
					glVertex3f( 0.5, 0.5, 0.5);
				glPopMatrix();
				glEnd();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0, 1.001, 0.0);
			glBegin(GL_QUADS);
			glPushMatrix();
				glColor3f(1.0,1.0,1.0);	//White (Team Number On Top)
				glVertex3f( 0.25, 0.001,-0.25);	//Long vetical bar.
				glVertex3f( 0.15, 0.001,-0.25);
				glVertex3f( 0.15, 0.001, 0.35);
				glVertex3f( 0.25, 0.001, 0.35);
			glPopMatrix();
			glPushMatrix();
				glVertex3f(-0.15, 0.001,-0.25);	//Short vertical bar.
				glVertex3f(-0.25, 0.001,-0.25);
				glVertex3f(-0.25, 0.001, 0.0);
				glVertex3f(-0.15, 0.001, 0.0);
			glPopMatrix();
			glPushMatrix();
				glVertex3f( 0.25, 0.001, 0.0);	//Horizontal bar.
				glVertex3f(-0.25, 0.001, 0.0);
				glVertex3f(-0.25, 0.001, 0.1);
				glVertex3f( 0.25, 0.001, 0.1);
			glPopMatrix();
			glEnd();
		glPopMatrix();
	glPopMatrix();
}

void Block::drawD() {
	glPushMatrix();
		float matDiffuse[] = { 1.0, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, matDiffuse);
		glColor3ub(105, 105, 105);
		glPushMatrix();
			glTranslatef(0.0, 0.25, 0.0);
			glScalef(0.5, 0.5, 0.5);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 0.75, 0.0);
			glScalef(0.25, 0.5, 0.25);
			glutSolidCube(1.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 1.25, 0.0);
			glScalef(0.125, 0.5, 0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();
}