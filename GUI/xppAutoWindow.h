#ifndef AUTOWINDOW_H
#define AUTOWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "xppCore.h"

#include "xppMenuButton.h"
#include "xppMenuLabels.h"

namespace Ui {
class xppAutoWindow;
}

class xppAutoWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit xppAutoWindow(xppCore *XPP, QWidget *parent = 0);
	~xppAutoWindow();

public slots:
	//void displayDialog(void);

private:
	Ui::xppAutoWindow *ui;

	/* Buttons of the diferent menus */
	QList<QPushButton*>			mainMenuButtons;
	QList<xppMenuButton*>		menuButtons;

	/* Pointer to the xpp core structure */
	xppCore		*xpp;

	/* Helper functions for GUI initialization */
	void setupMenus				(void);
	void setupConnections		(void);
};

#endif // AUTOWINDOW_H
