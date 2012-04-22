#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <QWidget>
#include <QtGui/QPaintEvent>
#include <QPainter>

#include "Ball.h"
#include "Wall.h"

class CGameField : public QWidget
{
  CBall ball;
  CWall walls;
  int myTimerId;

public:
  void paintEvent(QPaintEvent* event );
  void keyPressEvent(QKeyEvent* event);
};

#endif //GAME_FIELD_H
