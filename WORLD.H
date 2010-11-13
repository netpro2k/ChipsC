#if !defined(_WORLD_H_)
#define _WORLD_H_

#include "camera.h"
#include "pos.h"	
#include "textures.h"
#include "player.h"

class world  
{
public:
	camera mainCam;
	void draw();
    void setup();
	void nextLevel();
	void loadLevel(int level);
	void checkNewPosition(int key);

	player chip;

	int rows;
	int cols;
	int chips;
	int startRow;
	int startCol;
	int **map;
	int **bound;

	
private:
	int currentLevel;
	void drawTile(int tile, int x, int y);
	void inttostring(int numberoflevel);

	float myWidth; 
	float myHeight;
	float myTileCount;
	float myTileWidth;
	float myPixel;
	char levelchar[2];
	bool alive;
	COGLTexture myTiles;
};

#endif