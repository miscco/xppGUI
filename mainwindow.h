#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "autowindow.h"
#include "xppMenuButton.h"
#include "xppMenuLabels.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void openAutoWindow(void);

private:
	Ui::MainWindow *ui;

	AutoWindow *Auto;

	/* Buttons of the diferent menus */
	QList<QPushButton*>			mainMenuButtons;
	QList<xppMenuButton*>		menuButtons;

	/* Helper functions for GUI initialization */
	void setupMenus				(void);
	void setupConnections		(void);
};

#endif // MAINWINDOW_H
