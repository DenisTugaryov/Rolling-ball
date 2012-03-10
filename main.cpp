#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QtGui/QPaintEvent>
#include <QPainterPath>

#include "GameField.h"
#include "GameObject.h"
#include "Ball.h"


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	GameField window;

	window.resize(300, 500);
	window.setWindowTitle("Rolling-ball");
	window.show();

	return app.exec();
}
