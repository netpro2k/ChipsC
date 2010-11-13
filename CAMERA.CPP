#include "camera.h"
#include <GLUT/glut.h>

void camera::update(int playerX, int playerY)
{
	if (playerX<position.x()-3)
		position.col-=.2;
	if (playerX>position.x()+3)
		position.col+=.2;
	if (playerY<position.y()-3)
		position.row-=.2;
	if (playerY>position.y()+3)
		position.row+=.2;
	gluLookAt(position.x(), -position.y(), 15,     position.x(), -position.y(), 0,     0, 1, 0);			
	glRotated(180,1,0,0);
}

void camera::moveTo(int col, int row)
{
position.row = row;
position.col = col;
}

void camera::updateRatio(int width, int height)
{
	if (height==0)										
	{
		height=1;										
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
 
				  // FOV		// Ratio		  close clip  far clip
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, .5f ,150.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();		
}
