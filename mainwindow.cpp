#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "xppMenuLabels.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	/* Change the window title */
	this->setWindowTitle("xppaut 8.0");

	/* Prevent toggleable toolbars */
	setContextMenuPolicy(Qt::NoContextMenu);

	/* Setup the individual toolbar menues */
	setupMenus();

	/* Setup the signal connections */
	setupConnections();
}

MainWindow::~MainWindow()
{
	ui->toolBar->deleteLater();
	delete ui;
}

/****************************************************************************************/
/*								GUI initialization helpers								*/
/****************************************************************************************/

/****************************************************************************************/
/*										Windows											*/
/****************************************************************************************/
void MainWindow::openAutoWindow (void) {
	Auto = new AutoWindow(this);
	Auto->show();
}

/****************************************************************************************/
/*										Menus											*/
/****************************************************************************************/
void MainWindow::setupMenus(void) {

	for (int i=0; i<xppMenus.size(); i++) {
		menuButtons.push_back(new xppMenuButton(xppMenus.at(i), this));
		ui->toolBar->addWidget(menuButtons.at(i));
	}
}
/****************************************************************************************/
/*										Connections										*/
/****************************************************************************************/
void MainWindow::setupConnections (void) {
	connect(menuButtons.at(8)->actionList.at(9), SIGNAL(triggered()), this, SLOT(close()));
}
