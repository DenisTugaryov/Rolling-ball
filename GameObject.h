#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <QPainter>

class GameObject 
{
public:
	virtual void draw (QPainter& ) = 0;
};


#endif //_GAME_OBJECT_H_