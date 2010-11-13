
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "pos.h"
#include "textures.h"

const int LEFT	= 1;
const int RIGHT	= 2;
const int UP	= 3;
const int DOWN	= 4;



class player  
{
public:
	void reset(int col, int row, int chips);
	void draw();
	void moveTo(int col,int row);
	void setDir(int dir);
	int getDir();

	int redKeys;
	int blueKeys;
	int greenKeys;
	int yellowKeys;
	int chipsLeft;
	int tileNum;
	int maskNum;

	pos position;

private:
	void drawMe(int tile);
	float myWidth; 
	float myHeight;
	float myTileCount;
	float myTileWidth;
	float myPixel;
	int direction;
	COGLTexture myTiles;
};

#endif
