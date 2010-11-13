#include "world.h"
#include <iostream.h>
#include <fstream.h>
#include <GLUT/glut.h>
void world::setup()
{
	currentLevel = 1;
	myWidth=1; 
	myHeight=1;
	myTiles.LoadFromFile("tiles.bmp");
	myTileCount=16;
	myTileWidth=32/myTiles.GetWidth();
	myPixel=1/myTiles.GetWidth();
	alive = true;
	loadLevel(1);
}


void world::loadLevel(int level)
{
alive =true;
int i,j;
ifstream inFile;
inttostring(level);
char lev[200] = {'.','/','l','e','v','e','l','s','/','l','e','v','e','l',levelchar[0],levelchar[1],'.','d','a','t'};
inFile.open(lev);

inFile >> rows >> cols >> chips >> startRow >> startCol;

	map = (int **)malloc(rows * sizeof(int *));
	for(i = 0; i < rows; i++)
		map[i] = (int *)malloc(cols * sizeof(int));

	bound = (int **)malloc(rows * sizeof(int *));
	for(i = 0; i < rows; i++)
		bound[i] = (int *)malloc(cols * sizeof(int));


	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{	
			inFile >> map[i][j];
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{	
			inFile >> bound[i][j];
			cout << bound[i][j] << " ";
		}
		cout << endl;
	}
chip.reset(startCol,startRow,chips);
}
void world::checkNewPosition(int key)
{
int	playerNewX=chip.position.x();
int	playerNewY=chip.position.y();
	switch (key)
	{
	case GLUT_KEY_UP:	playerNewY--;
						chip.setDir(UP);
						break;
	case GLUT_KEY_DOWN:	playerNewY++;
						chip.setDir(DOWN);
						break;
	case GLUT_KEY_LEFT:	playerNewX--;
						chip.setDir(LEFT);
						break;
	case GLUT_KEY_RIGHT:playerNewX++;
						chip.setDir(RIGHT);
						break;
	}
	
	/*---------------------*\
	|						|
	|	  BOUND NUMBERS		|
	|						|
	+-----------------------+
	|						|
	|	0  : nothing		|
	|	1  : wall			|
	|	2  : red door		|
	|	3  : blue door		|
	|	4  : green door		|
	|	5  : yellow door	|
	|	6  : red key		|
	|	7  : blue key		|
	|	8  : green key		|
	|	9  : yellow key		|
	|	10 : chips			|
	|	11 : chip door		|
	|	12 : finish			|
	|	13 : movable block	|
	|	14 : water			|
	|						|
	\*---------------------*/

	if(bound[playerNewY][playerNewX]==0)//nothing, just move
	{
		chip.moveTo(playerNewX,playerNewY);
	}
	
	/////////////////// RED ////////////////////////////////////////
	if(bound[playerNewY][playerNewX]==2 && chip.redKeys > 0)// door
	{
		chip.redKeys--;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}
	if(bound[playerNewY][playerNewX]==6)// key
	{
		chip.redKeys++;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}				
	/////////////////// END RED ///////////////////////////////////

	/////////////////// BLUE ////////////////////////////////////////
	if(bound[playerNewY][playerNewX]==3 && chip.blueKeys > 0)// door
	{
		chip.blueKeys--;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}
	if(bound[playerNewY][playerNewX]==7)// key
	{
		chip.blueKeys++;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}				
	/////////////////// END BLUE ///////////////////////////////////

	/////////////////// GREEN ////////////////////////////////////////
	if(bound[playerNewY][playerNewX]==4 && chip.greenKeys > 0)// door
	{
		chip.greenKeys--;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}
	if(bound[playerNewY][playerNewX]==8)// key
	{
		chip.greenKeys++;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}				
	/////////////////// END GREEN ///////////////////////////////////

	/////////////////// YELLOW ////////////////////////////////////////
	if(bound[playerNewY][playerNewX]==5 && chip.yellowKeys > 0)// door
	{
		chip.yellowKeys--;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}
	if(bound[playerNewY][playerNewX]==9)// key
	{
		chip.yellowKeys++;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}				
	/////////////////// END YELLOW ///////////////////////////////////

	////////////////////MOVABLE BLOCK/////////////////////////////////
	if(bound[playerNewY][playerNewX]==13)
	{
		int dir = chip.getDir();
		int blockX, blockY;
		
		switch (dir)
		{
		case UP:	blockX = playerNewX;
					blockY = playerNewY-1;
					break;
		case DOWN:	blockX = playerNewX;
					blockY = playerNewY+1;
					break;
		case LEFT:	blockX = playerNewX-1;
					blockY = playerNewY;
					break;
		case RIGHT:	blockX = playerNewX+1;
					blockY = playerNewY;
					break;
		}

		if (bound[blockY][blockX] == 0)
		{
			/// clear old spot///////////
			map[playerNewY][playerNewX]=1;
			bound[playerNewY][playerNewX]=0;
			/// set new spot/////////
			map[blockY][blockX]=9;
			bound[blockY][blockX]=13;
			/// move player /////////////
			chip.moveTo(playerNewX,playerNewY);
		}

		if (bound[blockY][blockX] == 14)
		{
			/// clear old spot///////////
			map[playerNewY][playerNewX]=1;
			bound[playerNewY][playerNewX]=0;
			/// set new spot/////////
			map[blockY][blockX]=1;
			bound[blockY][blockX]=0;
			/// move player /////////////
			chip.moveTo(playerNewX,playerNewY);
		}
	}
	//////////////////// END MOVABLE BLOCK/////////////////////////////////

	/////////////////// CHIP ///////////////////////////////////////
	if(bound[playerNewY][playerNewX]==11 && chip.chipsLeft==0)// door
	{
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}	

	if(bound[playerNewY][playerNewX]==10)// chip
	{
		chip.chipsLeft--;
		chip.moveTo(playerNewX,playerNewY);
		bound[playerNewY][playerNewX]=0;
		map[playerNewY][playerNewX]=1;
	}	
	////////////////// CHIP END ///////////////////////////////////

	///////////////// LEVEL EXIT //////////////////////////////////
	if(bound[playerNewY][playerNewX]==12)// chip
	{
		chip.moveTo(playerNewX,playerNewY);
		nextLevel();
	}	
	///////////////// LEVEL EXIT END //////////////////////////////////

	///////////////// WATER ///////////////////////////////////////////
	if(bound[playerNewY][playerNewX]==14)
	{
		chip.moveTo(playerNewX,playerNewY);
		alive = false;
	}
	///////////////// WATER END ///////////////////////////////////////
}

void world::nextLevel()
{
currentLevel++;
loadLevel(currentLevel);
}


void world::draw()
{
	int j;
	mainCam.update(chip.position.x(),chip.position.y());
	for (int i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			drawTile(map[i][j],j,i);
		}
	}
	chip.draw();
	if(!alive)		//you dead?
	{
//		MessageBox(NULL,"YOUR DEAD", "YOUR DEAD",NULL);
//		Sleep(500);
		loadLevel(currentLevel);
	}
}
void world::drawTile(int tile,int x, int y)
{
	glEnable(GL_TEXTURE_2D);
	myTiles.SetActive();
	glPushMatrix();	
	glBegin (GL_QUADS);	
		glTexCoord2f((tile/myTileCount)-(myTileWidth)+myPixel,1);							
		glVertex2f(x-myWidth/2, y-myHeight/2);					

		glTexCoord2f(tile/myTileCount-myPixel,1);							
		glVertex2f(x + myWidth/2, y-myHeight/2);			

		glTexCoord2f(tile/myTileCount-myPixel,0);							
		glVertex2f(x + myWidth/2, y + myHeight/2);

		glTexCoord2f((tile/myTileCount)-(myTileWidth)+myPixel,0);						
		glVertex2f(x-myWidth/2, y + myHeight/2);
	glEnd();	
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void world::inttostring(int numberoflevel)
{
	int firstnum, secondnum;
	if (numberoflevel >= 10)
	{
		firstnum  = numberoflevel / 10;
		secondnum = numberoflevel % (firstnum * 10);
		firstnum = firstnum + 48;
		secondnum = secondnum + 48;
		levelchar[0] = firstnum;
		levelchar[1] = secondnum;
	}
	else
	{
		levelchar[0] = 48;
		levelchar[1] = numberoflevel + 48;
	}
}
	