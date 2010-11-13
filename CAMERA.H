#if !defined(_CAMERA_H_)
#define _CAMERA_H_

#include "pos.h"
class camera  
{
public:
	void updateRatio(int width, int height);
	void update(int playerX, int playerY);
	void moveTo(int col, int row);
	pos position;

};

#endif 