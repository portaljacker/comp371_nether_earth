#include "SkyBox.h"

SkyBox::SkyBox(void)
{
	im = loadBMP("star2.bmp");
	tex1 = loadTexture(im);
	im = loadBMP("ngc281.bmp");
	tex2 = loadTexture(im);
	im = loadBMP("sun.bmp");
	tex3 = loadTexture(im);
	im = loadBMP("moon.bmp");
	tex4 = loadTexture(im);
	im = loadBMP("star1.bmp");
	tex5 = loadTexture(im);
}


SkyBox::~SkyBox(void)
{
}

void SkyBox::draw()
{
	glPushMatrix();
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, tex1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
					glBegin(GL_QUADS);
						glNormal3f(0.0, 0.0, -1.0);

						glTexCoord2f(1.0f, 1.0f);
						glVertex3f( 0.5, 0.5, 0.5); //Top Right

						glTexCoord2f(0.0f, 1.0f);
						glVertex3f(-0.5, 0.5, 0.5); //Top Left

						glTexCoord2f(0.0f, 0.0f);
						glVertex3f(-0.5,-0.5, 0.5); //Bottom Left

						glTexCoord2f(1.0f, 0.0f);
						glVertex3f( 0.5,-0.5, 0.5); //Bottom Right
					glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
				
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBegin(GL_QUADS);
			glNormal3f(0.0, 0.0, 1.0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f( 0.5,-0.5,-0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5,-0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f( 0.5, 0.5,-0.5);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
				
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex3);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBegin(GL_QUADS);
			glNormal3f(1.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5,-0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5,-0.5,-0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5,-0.5, 0.5);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
				
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex4);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBegin(GL_QUADS);
			glNormal3f(-1.0, 0.0, 0.0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( 0.5, 0.5,-0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f( 0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f( 0.5,-0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f( 0.5,-0.5,-0.5);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
				
		glPushMatrix();
			glColor3f(0, 0, 0);
			glNormal3f(0.0, -1.0, 0.0);
			glVertex3f( 0.5,-0.5, 0.5);
			glVertex3f(-0.5,-0.5, 0.5);
			glVertex3f(-0.5,-0.5,-0.5);
			glVertex3f( 0.5,-0.5,-0.5);
		glPopMatrix();
			
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, tex5);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			glNormal3f(0.0, -1.0, 0.0);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( 0.5, 0.5,-0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5,-0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f( 0.5, 0.5, 0.5);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glPopMatrix();
}

//Makes the image into a texture, and returns the id of the texture
GLuint SkyBox::loadTexture(Image* image)
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