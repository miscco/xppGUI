#include "xppAutoWindow.h"
#include "ui_autowindow.h"

AutoWindow::AutoWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AutoWindow)
{
	ui->setupUi(this);

	/* Remove the margins */
	ui->gridLayout->setMargin(0);

	/* Change the window title */
	this->setWindowTitle("It's AUTO man!");

	/* Prevent togleable toolbars */
	setContextMenuPolicy(Qt::NoContextMenu);

	/* Setup the individual toolbar menues */
	setupMenus();

	/* Setup the signal connections */
	setupConnections();
}

AutoWindow::~AutoWindow()
{
	delete ui;
}

/****************************************************************************************/
/*								GUI initialization helpers								*/
/****************************************************************************************/


/****************************************************************************************/
/*										Menus											*/
/****************************************************************************************/
void AutoWindow::setupMenus(void) {
	for (int i=0; i<autoMenus.size(); i++) {
		menuButtons.push_back(new xppMenuButton(autoMenus.at(i), this));
		ui->toolBar->addWidget(menuButtons.at(i));
	}
}

/****************************************************************************************/
/*										Connections										*/
/****************************************************************************************/
void AutoWindow::setupConnections (void) {
	connect(menuButtons.at(8)->actionList.at(15), SIGNAL(triggered()), this, SLOT(close()));
}
