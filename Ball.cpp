#include <QPainter>
#include "Ball.h"

CBall::CBall(int x /*= 100*/, int y /*= 200*/, int z /*=0*/, int diametr /*= 50*/) :
  x(x), y(y), z(z), diametr(diametr)
{}

void CBall::draw(QPainter& painter)
{
  //painter.setBrush(QBrush(Qt::red, Qt::SolidPattern)); 
  QRadialGradient rg(x, y, 5, x + 30, x + 30);
  //rg.setColorAt(0.0, Qt::lightRed);
  rg.setColorAt(0.8, Qt::darkRed);
  rg.setColorAt(0.7, Qt::white);
  //rg.setColorAt(1.0, Qt::black);
  painter.setBrush(rg);
  painter.drawEllipse(x, y, diametr, diametr);  
}
