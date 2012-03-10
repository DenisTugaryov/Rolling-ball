#ifndef _BALL_H_
#define _BALL_H_

#include <QPainter>
#include "GameObject.h"

class Ball : public GameObject
{
public:
	int x;
	int y;
	int z;

	Ball(int x = 100, int y = 200, int z = 0);
	void draw(QPainter& );
	void setX(int a);
	void setY(int a);
	void setZ(int a);
	void setXYZ(int a, int b, int c);
};

#endif //_BALL_H_