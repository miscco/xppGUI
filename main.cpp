#include <QApplication>

#include <xppCore.h>

#include "GUI/xppMainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
