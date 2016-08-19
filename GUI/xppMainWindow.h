#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "xppCore.h"

#include "xppAutoWindow.h"
#include "xppMenuButton.h"
#include "xppMenuLabels.h"


namespace Ui {
class xppMainWindow;
}

class xppMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit xppMainWindow(xppCore *XPP, QWidget *parent = 0);
	~xppMainWindow();

private slots:
	void openAutoWindow				(void);
	void evaluateGraphicsDialogs	(void);
	void evaluateIntegrateDialogs	(void);
	void evaluateNumericsDialogs	(void);
	void evaluatePhasespaceDialogs	(void);
	void evaluateViewDialogs		(void);
	void evaluateWindowDialogs		(void);

private:
	Ui::xppMainWindow *ui;

	xppAutoWindow *Auto;

	/* Buttons of the diferent menus */
	QList<QPushButton*>			mainMenuButtons;
	QList<xppMenuButton*>		menuButtons;

	xppCore						*xpp;
	xppPlotWindow				*plot;

	/* Helper functions for GUI initialization */
	void initGraphicsDialogs	(void);
	void initIntegrateDialogs	(void);
	void initNumericsDialogs	(void);
	void initPhasespaceDialogs	(void);
	void initViewDialogs		(void);
	void initWindowDialogs		(void);

	void setupMenus				(void);
	void setupConnections		(void);

	void updatePlot				(void);
};

#endif // MAINWINDOW_H
