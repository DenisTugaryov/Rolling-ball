#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include "GameObject.h"

struct CBall : public CGameObject
{
  int x;
  int y;
  int z;
  int diametr;

  CBall(int x = 100, int y = 200, int z = 0, int diametr = 50);
  void draw(QPainter& );
};

#endif //BALL_H
