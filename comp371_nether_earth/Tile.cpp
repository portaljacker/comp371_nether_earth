#include "Tile.h"
#include <GL/glut.h>


Tile::Tile()
{
	/*ttrx = 0.5;
	ttry = 0.0;
	ttrz = -0.5;
	ttlx = -0.5;
	ttly = 0.0;
	ttlz = -0.5;
	tblx = -0.5;
	tbly = 0.0;
	tblz = 0.5;
	tbrx = 0.5;
	tbry = 0.0;
	tbrz = 0.5;
	btrx = 0.5;
	btry = -0.2;
	btrz = -0.5;
	btlx = -0.5;
	btly = -0.2;
	btlz = -0.5;
	bblx = -0.5;
	bbly = -0.2;
	bblz = 0.5;
	bbrx = 0.5;
	bbry = -0.2;
	bbrz = 0.5;

	ltrx = 0.25;
	ltry = 0.001;
	ltrz = -0.25;

	ltlx = 0.15;
	ltly = 0.001;
	ltlz = -0.25;

	lblx = 0.15;
	lbly = 0.001;
	lblz = 0.35;

	lbrx = 0.25;
	lbry = 0.001;
	lbrz = 0.35;

	strx = -0.15;
	stry = 0.001;
	strz = -0.25;

	stlx = -0.25;
	stly = 0.001;
	stlz = -0.25;

	sblx = -0.25;
	sbly = 0.001;
	sblz = 0.0;

	sbrx = -0.15;
	sbry = 0.001;
	sbrz = 0.0;

	htrx = 0.25;
	htry = 0.001;
	htrz = 0.0;

	htlx = -0.25;
	htly = 0.001;
	htlz = 0.0;

	hblx = -0.25;
	hbly = 0.001;
	hblz = 0.1;

	hbrx = 0.25;
	hbry = 0.001;
	hbrz = 0.1;*/
}


Tile::~Tile(void)
{
}
void Tile::draw()
{
	//Hardcoded coordinates version

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glBegin(GL_QUADS);
		glPushMatrix();
			glPushMatrix();
				glColor3f(1.0f,0.0f,0.0f);	//CRed (Front Side)	
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(1.0f,1.0f,0.0f);	//Yellow (Back Side)
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Bottom  Left Vertex
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,0.0f,1.0f);	//Blue (Left Side)
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(1.0f,0.0f,1.0f);	//Violet (Right Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Top Left Vertex
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(1.0f,0.5f,0.0f);	//Orange (Bottom Side)
				glVertex3f( 0.5f,-0.2f, 0.5f);	//Top Right Vertex
				glVertex3f(-0.5f,-0.2f, 0.5f);	//Top Left Vertex
				glVertex3f(-0.5f,-0.2f,-0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f,-0.2f,-0.5f);	//Bottom Right Vertex
			glPopMatrix();
				
			glPushMatrix();
				glColor3f(0.0f,1.0f,0.0f);	//Green (Top Side)
				glVertex3f( 0.5f, 0.0f,-0.5f);	//Top Right Vertex
				glVertex3f(-0.5f, 0.0f,-0.5f);	//Top Left Vertex
				glVertex3f(-0.5f, 0.0f, 0.5f);	//Bottom Left Vertex
				glVertex3f( 0.5f, 0.0f, 0.5f);	//Bottom Right Vertex
			glPopMatrix();

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

		glPopMatrix();
	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.

	//Input coordinates version.

	//GLfloat vertices[][3] = {{btlx, btly, btlz},   {btrx, btry, btrz},   {ttrx, ttry, ttrz},   {ttlx, ttly, ttlz},    {bblx, bbly, bblz},   {bbrx, bbry, bbrz},   {tbrx, tbry, tbrz},  {tblx, tbly, tblz}};

	//GLfloat teamNumVer[][3] = {{ltrx, ltry, ltrz},   {ltlx, ltly, ltlz},   {lblx, lbly, lblz},   {lbrx, lbry, lbrz},   {strx, stry, strz},   {stlx, stly, stlz},   {sblx, sbly, sblz},   {sbrx, sbry, sbrz},
	//{htrx, htry, htrz},   {htlx, htly, htlz},   {hblx, hbly, hblz},   {hbrx, hbry, hbrz}};

	//GLfloat normals[][3] = {{btlx, btly, btlz},   {btrx, btry, btrz},   {ttrx, ttry, ttrz},   {ttlx, ttly, ttlz},    {bblx, bbly, bblz},   {bbrx, bbry, bbrz},   {tbrx, tbry, tbrz},  {tblx, tbly, tblz}};

	//GLfloat colors[][3] = {{0.0,1.0,0.0},{1.0,0.0,0.0},
	//{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, 
	//{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};


	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	//glBegin(GL_QUADS);
	/*glPushMatrix();
		glPushMatrix();
			glColor3f(1.0f,0.0f,0.0f);	//CRed (Front Side)
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[4]);
			glVertex3fv(vertices[5]);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f,1.0f,0.0f);	//Yellow (Back Side)
			glVertex3fv(vertices[1]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[3]);
			glVertex3fv(vertices[2]);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.0f,0.0f,1.0f);	//Blue (Left Side)
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[3]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[4]);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f,0.0f,1.0f);	//Violet (Right Side)
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[6]);
			glVertex3fv(vertices[5]);
			glVertex3fv(vertices[1]);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f,0.5f,0.0f);	//Orange (Bottom Side)
			glVertex3fv(vertices[5]);
			glVertex3fv(vertices[4]);
			glVertex3fv(vertices[0]);
			glVertex3fv(vertices[1]);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.0f,1.0f,0.0f);	//Green (Top Side)
			glVertex3fv(vertices[2]);
			glVertex3fv(vertices[3]);
			glVertex3fv(vertices[7]);
			glVertex3fv(vertices[6]);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f,1.0f,1.0f);	//White (Team Number On Top)
			glVertex3fv(teamNumVer[0]); //Long vetical bar.
			glVertex3fv(teamNumVer[1]);
			glVertex3fv(teamNumVer[2]);
			glVertex3fv(teamNumVer[3]);
		glPopMatrix();

		glPushMatrix();
			glVertex3fv(teamNumVer[4]); //Short vetical bar.
			glVertex3fv(teamNumVer[5]);
			glVertex3fv(teamNumVer[6]);
			glVertex3fv(teamNumVer[7]);
		glPopMatrix();

		glPushMatrix();
			glVertex3fv(teamNumVer[8]); //Horizontal bar.
			glVertex3fv(teamNumVer[9]);
			glVertex3fv(teamNumVer[10]);
			glVertex3fv(teamNumVer[11]);
		glPopMatrix();

	glPopMatrix();*/
	//glEnd();
	//glFlush();
	//glEnable(GL_DEPTH_TEST); //Enables depth.
}
