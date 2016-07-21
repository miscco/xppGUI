#ifndef AUTOWINDOW_H
#define AUTOWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <xppMenuButton.h>
#include <xppMenuLabels.h>

namespace Ui {
class AutoWindow;
}

class AutoWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit AutoWindow(QWidget *parent = 0);
	~AutoWindow();

public slots:
	//void displayDialog(void);

private:
	Ui::AutoWindow *ui;

	/* Buttons of the diferent menus */
	QList<QPushButton*>			mainMenuButtons;
	QList<xppMenuButton*>		menuButtons;

	/* Helper functions for GUI initialization */
	void setupMenus				(void);
	void setupConnections		(void);
};

#endif // AUTOWINDOW_H
