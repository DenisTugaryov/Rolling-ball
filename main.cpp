#include <QApplication>
#include <QWidget>
#include <QPainter>

#include "GameField.h"
#include "GameObject.h"
#include "Ball.h"
#include "Wall.h"


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  CGameField window;

  //window.resize(300, 500);
  window.setWindowTitle("Rolling-ball");
  window.show();

  return app.exec();
}
