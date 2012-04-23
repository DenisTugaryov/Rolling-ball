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
  QVector<QVector<int> > wall_matrix;

public:
  CWall();
  void draw(QPainter& );
  int get_wall_depth();
  int get_wall_length();
  int get_field_height();
  int get_field_breadth();
  bool contain_point(int x_point, int y_point);
};

#endif //WALL_H
