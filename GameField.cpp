#include <QWidget>
#include <QPainter>
#include <QtGui/QPaintEvent>
#include <QPainterPath>

#include "GameField.h"
#include "Ball.h"

#include <iostream>

void CGameField::paintEvent(QPaintEvent* /*event*/)
{
  QPainter painter;
  painter.begin(this);
  ball.draw(painter);
}

void CGameField::keyPressEvent(QKeyEvent* event)
{
  int step = 5;
  switch(event->key())
  {
    case Qt::Key_Up : 
    {
      int possible_step = ball.y;
      if (possible_step > 0)
      {
        if (possible_step > step)
        possible_step = step;
        ball.y -= possible_step;
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
        ball.y += possible_step;
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
        ball.x += possible_step;
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
        ball.x -= possible_step;
      }	
      break;
    }
  }
}

void CGameField::showEvent(QShowEvent* /*event*/)
{
  myTimerId = startTimer(20);
}

void CGameField::timerEvent(QTimerEvent* event)
{
  if (event->timerId() == myTimerId) 
  {
    update();
  }
}