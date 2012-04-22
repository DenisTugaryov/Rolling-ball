#ifndef WALL_H
#define WALL_H

#include <QVector>
#include <QPainter>
#include "GameObject.h"

class CWall : public CGameObject
{  
  int wall_depth;
  int wall_length;
  int field_height;
  int field_breadth;
  QVector<QVector<int> > horizontal_walls;
  QVector<QVector<int> > vertical_walls;

public:
  CWall();
  void draw(QPainter& );
};

#endif //WALL_H