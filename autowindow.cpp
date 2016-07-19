#include "autowindow.h"
#include "ui_autowindow.h"

AutoWindow::AutoWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AutoWindow)
{
	ui->setupUi(this);

	/* Change the window title */
	this->setWindowTitle("It's AUTO man!");

	/* Prevent togleable toolbars */
	setContextMenuPolicy(Qt::NoContextMenu);

	/* Setup the individual toolbar menues */
	setupMenus();
}

AutoWindow::~AutoWindow()
{
	delete ui;
}

/****************************************************************************************/
/*								GUI initialization helpers								*/
/****************************************************************************************/

/****************************************************************************************/
/*										Buttons											*/
/****************************************************************************************/
void AutoWindow::setupButtonClear (void) {
	/* Create the button and add it to the toolbar */
	buttonClear = new QPushButton("&Clear", this);
	buttonClear->setShortcut(QKeySequence("C"));
	buttonClear->setFlat(true);
	buttonClear->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonClear->addAction(new QAction("&Clear", buttonClear));
	ui->toolBar->addWidget(buttonClear);
}

void AutoWindow::setupButtonGrab (void) {
	/* Create the button and add it to the toolbar */
	buttonGrab = new QPushButton("&Grab", this);
	buttonGrab->setShortcut(QKeySequence("G"));
	buttonGrab->setFlat(true);
	buttonGrab->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonGrab->addAction(new QAction("&Grab", buttonGrab));
	ui->toolBar->addWidget(buttonGrab);
}

void AutoWindow::setupButtonNumerics (void) {
	/* Create the button and add it to the toolbar */
	buttonNumerics = new QPushButton("&Numerics", this);
	buttonNumerics->setShortcut(QKeySequence("N"));
	buttonNumerics->setFlat(true);
	buttonNumerics->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonNumerics->addAction(new QAction("&Numerics",	buttonNumerics));
	ui->toolBar->addWidget(buttonNumerics);
}

void AutoWindow::setupButtonParameter (void) {
	/* Create the button and add it to the toolbar */
	buttonParameter = new QPushButton("&Parameter", this);
	buttonParameter->setShortcut(QKeySequence("P"));
	buttonParameter->setFlat(true);
	buttonParameter->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonParameter->addAction(new QAction("&Parameter", buttonParameter));
	ui->toolBar->addWidget(buttonParameter);
}

void AutoWindow::setupButtonRedraw (void) {
	/* Create the button and add it to the toolbar */
	buttonRedraw= new QPushButton("Re&draw", this);
	buttonRedraw->setShortcut(QKeySequence("D"));
	buttonRedraw->setFlat(true);
	buttonRedraw->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonRedraw->addAction(new QAction("&Redraw", buttonRedraw));
	ui->toolBar->addWidget(buttonRedraw);
}

void AutoWindow::setupButtonRun (void) {
	/* Create the button and add it to the toolbar */
	buttonRun = new QPushButton("&Run", this);
	buttonRun->setShortcut(QKeySequence("R"));
	buttonRun->setFlat(true);
	buttonRun->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonRun->addAction(new QAction("&Run", buttonRun));
	ui->toolBar->addWidget(buttonRun);
}

/****************************************************************************************/
/*										Menus											*/
/****************************************************************************************/
void AutoWindow::setupMenus(void) {
	setupButtonParameter();
	setupMenuAxes();
	setupButtonNumerics();
	setupButtonRun();
	setupButtonGrab();
	setupMenuUserPeriod();
	setupButtonClear();
	setupButtonRedraw();
	setupMenuFile();
}

void AutoWindow::setupMenuAxes (void) {
	/* Create the menu */
	menuAxes = new QMenu();

	/* Create the button and add it to the toolbar */
	QPushButton *buttonAxes = new QPushButton("&Axes", ui->toolBar);
	buttonAxes->setShortcut(QKeySequence("A"));
	buttonAxes->setFlat(true);
	buttonAxes->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonAxes->setMenu(menuAxes);
	ui->toolBar->addWidget(buttonAxes);

	/* Create the actions and associate the actions with the menu */
	menuAxes->addAction(new QAction("&Range",	menuAxes));
	menuAxes->addAction(new QAction("&No show",	menuAxes));
	menuAxes->addAction(new QAction("&Show",	menuAxes));
	menuAxes->addAction(new QAction("&Periodic",menuAxes));
}

void AutoWindow::setupMenuFile (void) {
	/* Create the menu */
	menuFile = new QMenu();

	/* Create the button and add it to the toolbar */
	QPushButton *buttonFile = new QPushButton("&File", ui->toolBar);
	buttonFile->setShortcut(QKeySequence("F"));
	buttonFile->setFlat(true);
	buttonFile->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonFile->setMenu(menuFile);
	ui->toolBar->addWidget(buttonFile);

	/* Create the actions and associate the actions with the menu */
	menuFile->addAction(new QAction("&Import Orbit",		menuFile));
	menuFile->addAction(new QAction("&Save diagram",		menuFile));
	menuFile->addAction(new QAction("&Load diagram",		menuFile));
	menuFile->addAction(new QAction("&Postscript",			menuFile));
	menuFile->addAction(new QAction("&SVG",					menuFile));
	menuFile->addAction(new QAction("&Reset diagram",		menuFile));
	menuFile->addAction(new QAction("&Clear grab",			menuFile));
	menuFile->addAction(new QAction("&Write points",		menuFile));
	menuFile->addAction(new QAction("&All info",			menuFile));
	menuFile->addAction(new QAction("Init &Data",			menuFile));
	menuFile->addAction(new QAction("&Toggle redraw",		menuFile));
	menuFile->addAction(new QAction("Auto ra&nge",			menuFile));
	menuFile->addAction(new QAction("S&elect 2par point",	menuFile));
	menuFile->addAction(new QAction("Draw la&bled",			menuFile));
	menuFile->addAction(new QAction("L&oad branch",			menuFile));
	menuFile->addAction(new QAction("&Quit",				menuFile));

	/* Create a QList for the actions of the menu */
	QList<QAction*> actions = menuFile->actions();

	/* Connect the actions with the corresponding signals */
	connect(actions.at(15), SIGNAL(triggered()), this, SLOT(close()));
}

void AutoWindow::setupMenuUserPeriod (void) {
	/* Create the menu */
	menuUserPeriod = new QMenu();

	/* Create the button and add it to the toolbar */
	QPushButton *buttonUserPeriod = new QPushButton("&Graphics", ui->toolBar);
	buttonUserPeriod->setShortcut(QKeySequence("G"));
	buttonUserPeriod->setFlat(true);
	buttonUserPeriod->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");
	buttonUserPeriod->setMenu(menuUserPeriod);
	ui->toolBar->addWidget(buttonUserPeriod);

	/* Create the actions and associate the actions with the menu */
	menuUserPeriod->addAction(new QAction("&0",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&1",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&2",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&3",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&4",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&5",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&6",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&7",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&8",	menuUserPeriod));
	menuUserPeriod->addAction(new QAction("&9",	menuUserPeriod));
}
