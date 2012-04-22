#include <QVector>
#include <fstream>
#include <iostream>
#include <QPainter>
#include <QPainterPath>
#include "Wall.h"

CWall::CWall() :
  wall_depth(10),
  wall_length(60),
  field_height(0),
  field_breadth(0)
{
  int tmp = 0;
  std::ifstream file("walls_map.txt");
  file>> field_height >> field_breadth;
  QVector<int> string(field_breadth, 0);
  for (int i = 0; i <= field_height; ++i)
    horizontal_walls.push_back(string);
  for(int i = 0; i <= field_height; ++i)
  {
    for (int j = 0; j < field_breadth; ++j)
    {
      file >> tmp;
      horizontal_walls[i][j] = tmp;
    }
  }

  QVector<int> colomn(field_breadth + 1, 0);
  for (int i = 0; i < field_height; ++i)
    vertical_walls.push_back(colomn);
  for(int i = 0; i < field_height; ++i)
  {
    for (int j = 0; j <= field_breadth; ++j)
    {
      file >> tmp;
      vertical_walls[i][j] = tmp;
    }
  }
}

void CWall::draw(QPainter& painter)
{
  painter.setBrush(QBrush(Qt::black, Qt::SolidPattern)); 
  for(int i = 0; i <= field_height; ++i)
    for (int j = 0; j < field_breadth; ++j)
      if (horizontal_walls[i][j] == 1)
        painter.drawRect(j * (wall_length + wall_depth), i * (wall_length + wall_depth),
                            					wall_length + 2 * wall_depth, wall_depth);

  for(int i = 0; i < field_height; ++i)
    for (int j = 0; j <= field_breadth; ++j)
      if (vertical_walls[i][j] == 1)
        painter.drawRect(j * (wall_length + wall_depth), wall_depth + i * (wall_length + wall_depth),
                                        									wall_depth, wall_length);
}

