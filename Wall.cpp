#include <fstream>
#include <QVector>
#include <QPainter>
#include "Wall.h"

const int wd = 10;
const int wl = 55;

CWall::CWall() :
  wall_depth(wd),
  wall_length(wl),
  field_height(0),
  field_breadth(0)
{
  std::ifstream file("walls_map.txt");
  file>> field_height >> field_breadth;

  QVector<int> null_string(2 * field_breadth + 1, 0);
  for (int i = 0; i <= 2 * field_height; ++i)
    wall_matrix.push_back(null_string);

  for(int i = 0; i <= 2 * field_height; ++i)
    for (int j = 0; j <= 2 * field_breadth; ++j)
      file >> wall_matrix[i][j];
}

void CWall::draw(QPainter& painter)
{
  painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
  int x = 0;
  int y = 0;
  for(int i = 0; i <= 2 * field_height; ++i)
  {
    for (int j = 0; j <= 2 * field_breadth; ++j)
    {
      if (i % 2 == 0 && j % 2 == 0)
      {
        if (wall_matrix[i][j] == 1)
          painter.drawRect(x, y, wall_depth, wall_depth);
        x += wall_depth;
      }
      else if (i % 2 == 0 && j % 2 == 1)
      {
        if (wall_matrix[i][j] == 1)
          painter.drawRect(x, y, wall_length, wall_depth);
        x += wall_length;
      }
      else if (i % 2 == 1 && j % 2 == 0)
      {
        if (wall_matrix[i][j] == 1)
          painter.drawRect(x, y, wall_depth, wall_length);
        x += wall_depth + wall_length;
      }
    }
  x = 0;
  if (i % 2 == 0)
    y += wall_depth;
  else 
    y += wall_length;
  }
}

int CWall::get_wall_depth()
{
  return wall_depth;
}
int CWall::get_wall_length()
{
  return wall_length;
}
int CWall::get_field_height()
{
  return field_height;
}
int CWall::get_field_breadth()
{
  return field_breadth;
}

bool CWall::contain_point(int x_point, int y_point)
{
  int x = 0;
  int y = 0;
  for(int i = 0; i <= 2 * field_height; ++i)
  {
    for (int j = 0; j <= 2 * field_breadth; ++j)
    {
      if (i % 2 == 0 && j % 2 == 0)
      {
        if (wall_matrix[i][j] == 1)
          if (x_point >= x && x_point <= x + wall_depth && y_point >= y && y_point <= y + wall_depth)
            return true;
        x += wall_depth;
      }
      else if (i % 2 == 0 && j % 2 == 1)
      {
        if (wall_matrix[i][j] == 1)
          if (x_point >= x && x_point <= x + wall_length && y_point >= y && y_point <= y + wall_depth)
            return true;
        x += wall_length;
      }
      else if (i % 2 == 1 && j % 2 == 0)
      {
        if (wall_matrix[i][j] == 1)
          if (x_point >= x && x_point <= x + wall_depth && y_point >= y && y_point <= y + wall_length)
            return true;
        x += wall_depth + wall_length;
      }
    }
  x = 0;
  if (i % 2 == 0)
    y += wall_depth;
  else 
    y += wall_length;
  }
  return false;
}
