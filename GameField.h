#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <QWidget>
#include <QtGui/QPaintEvent>
#include <QPainter>

#include "Ball.h"

class CGameField : public QWidget
{
  CBall ball;
  int myTimerId;

public:
  void paintEvent(QPaintEvent* event );
  void keyPressEvent(QKeyEvent* event);
  void showEvent(QShowEvent* event);
  void timerEvent(QTimerEvent* event);
};

#endif //GAME_FIELD_H
