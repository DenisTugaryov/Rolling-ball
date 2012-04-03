#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <QPainter>

class CGameObject 
{
public:
  virtual void draw(QPainter& ) = 0;
};

#endif //GAME_OBJECT_H
