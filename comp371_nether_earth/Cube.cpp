//Comp371_w12 Section R
//Prof. S. Mokhov
//Programming Assignment Final Build
//Team 4
//Jordan V. 1300520
//Taras K. 6901204
//Gianni T. 1938878
//Sebastien S. 9500782
//This class is used to draw a cube complete with normals and texture coordinates.

#include <gl\glut.h>
#include "Cube.h"

namespace pj {
	void cube() {
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
	}
}