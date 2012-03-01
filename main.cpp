#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QtGui/QPaintEvent>
#include <QPainterPath>


class myWidget : public QWidget
{
public:
	void paintEvent(QPaintEvent * event )
	 {
	    QPainter painter;
	    painter.begin(this);
		painter.setBrush(QBrush(Qt::red, Qt::SolidPattern)); 
		painter.drawEllipse(150, 250, 50, 50);  
	    painter.end();
	 }
};


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	myWidget window;

	window.resize(300, 500);
	window.setWindowTitle("Rolling-ball");
	window.show();

	return app.exec();
}
