#ifndef _GAME_FIELD_H_
#define _GAME_FIELD_H_

#include <QWidget>
#include <QtGui/QPaintEvent>
#include <QPainter>

#include "Ball.h"

class GameField : public QWidget
{
public:
	Ball ball;
	int myTimerId;

	void paintEvent(QPaintEvent* event );
	void keyPressEvent(QKeyEvent* event);
	void showEvent(QShowEvent* event);
	void timerEvent(QTimerEvent* event);
};

#endif //_GAME_FIELD_H_