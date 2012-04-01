#ifndef _BALL_H_
#define _BALL_H_

#include <QPainter>
#include "GameObject.h"

struct Ball : public GameObject
{
	int x;
	int y;
	int z;
	int diametr;

	Ball(int x = 100, int y = 200, int z = 0, int diametr = 50);
	void draw(QPainter& );
	
};

#endif //_BALL_H_