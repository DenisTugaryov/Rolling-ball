#include <QWidget>
#include <QPainter>
#include <QtGui/QPaintEvent>
#include <cmath>

#include "GameField.h"
#include "Ball.h"
#include "Wall.h"

const int step = 5;

void CGameField::paintEvent(QPaintEvent* /*event*/)
{
  QPainter painter;
  painter.begin(this);
  ball.draw(painter);
  walls.draw(painter);
}

void CGameField::keyPressEvent(QKeyEvent* event)
{
  switch(event->key())
  {
    case Qt::Key_Up : 
    {
      int possible_step = ball.y;
      if (possible_step > 0)
      {
        if (possible_step > step)
        possible_step = step;
        ball.y -= up_step(ball.x, ball.y, ball.diametr, possible_step);
      }	
      break;
    }		
    case Qt::Key_Down : 
    {	
      int possible_step = height() - ball.y - ball.diametr - 1;
      if (possible_step > 0)
      {
        if (possible_step > step)
        possible_step = step;
        ball.y += down_step(ball.x, ball.y, ball.diametr, possible_step);;
      }	
      break;
    }
    case Qt::Key_Right : 
    {
      int possible_step = width() - ball.x - ball.diametr - 1;
      if (possible_step > 0)
      {
        if (possible_step > step)
        possible_step = step;
        ball.x += right_step(ball.x, ball.y, ball.diametr, possible_step);;
      }	
      break;
    }
    case Qt::Key_Left : 
    {
      int possible_step = ball.x;
      if (possible_step > 0)
      {
        if (possible_step > step)
        possible_step = step;
        ball.x -= left_step(ball.x, ball.y, ball.diametr, possible_step);;
      }	
      break;
    }
  }
  update();
}

int CGameField::up_step(int ball_x, int ball_y, int ball_diametr, int step)
{
  int possible_step = 0;
  double check_x = 0;
  double check_y = 0;
  double ball_radius = (double)ball_diametr / 2;
  double ball_center_x = ball_x + ball_radius;
  double ball_center_y = ball_y + ball_radius;
  bool find_wall = false;

  while (possible_step <= step && !find_wall)
  {
    for (double alfa = 0; alfa <= 180; alfa += 1)
    {
      check_x = ball_center_x + ball_radius * cos(M_PI * alfa / 180);
      check_y = ball_center_y - possible_step - ball_radius * sin(M_PI * alfa / 180);
      if (walls.contain_point(check_x, check_y))
      {
        find_wall = true;
        break;
      }  
    }
    if (!find_wall)
      ++possible_step;
  }
  return possible_step - 1;
}

int CGameField::down_step(int ball_x, int ball_y, int ball_diametr, int step)
{
  int possible_step = 0;
  double check_x = 0;
  double check_y = 0;
  double ball_radius = (double)ball_diametr / 2;
  double ball_center_x = ball_x + ball_radius;
  double ball_center_y = ball_y + ball_radius;
  bool find_wall = false;
  while (possible_step <= step && !find_wall)
  {
    for (double alfa = 0; alfa <= 180; alfa += 1)
    {
      check_x = ball_center_x + ball_radius * cos(M_PI * alfa / 180);
      check_y = ball_center_y + possible_step + ball_radius * sin(M_PI * alfa / 180);
      if (walls.contain_point(check_x, check_y))
      {
        find_wall = true;
        break;
      }  
    }
    if (!find_wall)
      ++possible_step;
  }
  return possible_step - 1;
}

int CGameField::left_step(int ball_x, int ball_y, int ball_diametr, int step)
{
  int possible_step = 0;
  double check_x = 0;
  double check_y = 0;
  double ball_radius = (double)ball_diametr / 2;
  double ball_center_x = ball_x + ball_radius;
  double ball_center_y = ball_y + ball_radius;
  bool find_wall = false;
  while (possible_step <= step && !find_wall)
  {
    for (double alfa = -90; alfa <= 90; alfa += 1)
    {
      check_x = ball_center_x - possible_step - ball_radius * cos(M_PI * alfa / 180);
      check_y = ball_center_y - ball_radius * sin(M_PI * alfa / 180);
      if (walls.contain_point(check_x, check_y))
      {
        find_wall = true;
        break;
      }  
    }
    if (!find_wall)
      ++possible_step;
  }
  return possible_step - 1;
}

int CGameField::right_step(int ball_x, int ball_y, int ball_diametr, int step)
{
  int possible_step = 0;
  double check_x = 0;
  double check_y = 0;
  double ball_radius = (double)ball_diametr / 2;
  double ball_center_x = ball_x + ball_radius;
  double ball_center_y = ball_y + ball_radius;
  bool find_wall = false;
  while (possible_step <= step && !find_wall)
  {
    for (double alfa = -90; alfa <= 90; alfa += 1)
    {
      check_x = ball_center_x + possible_step + ball_radius * cos(M_PI * alfa / 180);
      check_y = ball_center_y + ball_radius * sin(M_PI * alfa / 180);
      if (walls.contain_point(check_x, check_y))
      {
        find_wall = true;
        break;
      }  
    }
    if (!find_wall)
      ++possible_step;
  }
  return possible_step - 1;
}
