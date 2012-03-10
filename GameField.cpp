#include <QWidget>
#include <QPainter>
#include <QtGui/QPaintEvent>
#include <QPainterPath>

#include "GameField.h"
#include "Ball.h"

void GameField::paintEvent(QPaintEvent* /*event*/)
{
	QPainter painter;
	painter.begin(this);
	ball.draw(painter);
}

void GameField::keyPressEvent(QKeyEvent* event)
{
	int step = 5;
	switch(event->key())
	{
		case Qt::Key_Up : 
		{
			ball.y -= step;
			break;
		}		
		case Qt::Key_Down : 
		{
			ball.y += step;
			break;
		}
		case Qt::Key_Right : 
		{
			ball.x += step;
			break;
		}
		case Qt::Key_Left : 
		{
			ball.x -= step;
			break;
		}
	}
}
void GameField::showEvent(QShowEvent* event)
{
	myTimerId = startTimer(20);
}

void GameField::timerEvent(QTimerEvent* event)
{
	if (event->timerId() == myTimerId) 
	{
		update();
	}
}