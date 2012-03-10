#include <QPainter>
#include <QPainterPath>
#include "Ball.h"

Ball::Ball(int x /*= 100*/, int y /*= 200*/, int z /*=0*/) :
	x(x), y(y), z(z)
{}

void Ball::draw(QPainter& painter)
{
	//painter.setBrush(QBrush(Qt::red, Qt::SolidPattern)); 
	QRadialGradient rg(x, y, 50, x-20, x-20);
	//rg.setColorAt(0.0, Qt::lightRed);
	rg.setColorAt(0.8, Qt::darkRed);
	rg.setColorAt(0.9, Qt::white);
	rg.setColorAt(1.0, Qt::black);
	painter.setBrush(rg);
	painter.drawEllipse(x, y, 50, 50);  
}

void Ball::setX(int a)
{
	x = a;
}

void Ball::setY(int a)
{
	y = a;
}

void Ball::setZ(int a)
{
	z = a;
}

void Ball::setXYZ(int a, int b, int c)
{
	x = a;
	y = b;
	z = c;
}