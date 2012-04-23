#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <QWidget>
#include <QPainter>

#include "Ball.h"
#include "Wall.h"

class CGameField : public QWidget
{
  CBall ball;
  CWall walls;

public:
  void paintEvent(QPaintEvent* event );
  void keyPressEvent(QKeyEvent* event);
  int up_step(int ball_x, int ball_y ,int ball_diametr, int step);
  int down_step(int ball_x, int ball_y ,int ball_diametr, int step);
  int left_step(int ball_x, int ball_y ,int ball_diametr, int step);
  int right_step(int ball_x, int ball_y ,int ball_diametr, int step);
};

#endif //GAME_FIELD_H
