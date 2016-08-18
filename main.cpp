#include <QApplication>

#include "xppCore.h"
#include "xppMainWindow.h"

int main(int argc, char *argv[])
{
	xppCore xpp;

	QApplication a(argc, argv);
	xppMainWindow w(&xpp);
	w.show();

	return a.exec();
}
