#include "player.h"
#include <iostream.h>
#include <GLUT/glut.h>

void player::reset(int col,int row, int chips)
{
	redKeys=0;
	blueKeys=0;
	greenKeys=0;
	yellowKeys=0;
	chipsLeft=chips;
	tileNum=1;
	maskNum=2;
	myWidth=1; 
	myHeight=1;
	myTiles.LoadFromFile("player.bmp");
	myTileCount=8;
	myTileWidth=32/myTiles.GetWidth();
	myPixel=1/myTiles.GetWidth();
	moveTo(col,row);	
}

void player::moveTo(int col,int row)
{
	position.row = row;
	position.col = col;
}

void player::draw()
{
	glPushMatrix();
	glTranslated(position.col,position.row,0);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_DST_COLOR,GL_ZERO);
	drawMe(maskNum);
	glBlendFunc(GL_ONE, GL_ONE);
	drawMe(tileNum);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
}

void player::drawMe(int tile)
{
	glEnable(GL_TEXTURE_2D);
	myTiles.SetActive();
	glPushMatrix();	
	glBegin (GL_QUADS);	
		glTexCoord2f((tile/myTileCount)-(myTileWidth)+myPixel,1);							
		glVertex2f(0-myWidth/2, 0-myHeight/2);					

		glTexCoord2f(tile/myTileCount-myPixel,1);							
		glVertex2f(0 + myWidth/2, 0-myHeight/2);			

		glTexCoord2f(tile/myTileCount-myPixel,0);							
		glVertex2f(0 + myWidth/2, 0 + myHeight/2);

		glTexCoord2f((tile/myTileCount)-(myTileWidth)+myPixel,0);						
		glVertex2f(0-myWidth/2, 0 + myHeight/2);
	glEnd();	
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void player::setDir(int dir)
{
	direction = dir;
	cout << direction << endl;
}

int player::getDir()
{
	return direction;
}
