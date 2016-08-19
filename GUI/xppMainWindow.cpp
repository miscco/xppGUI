#include "xppMainWindow.h"
#include "ui_xppMainWindow.h"

enum xppMainButtons {
	buttonIntegrate= 0,
	buttonContinue,
	buttonNullclines,
	buttonDirectionField,
	buttonPhasespace,
	buttonKinescope,
	buttonGraphics,
	buttonNumerics,
	buttonFile,
	buttonParameters,
	buttonErase,
	buttonWindow,
	buttonText,
	buttonSingular,
	buttonView,
	buttonPlot,
	buttonRestore,
	buttonParameter3D,
	buttonBoundaryValues
};

xppMainWindow::xppMainWindow(xppCore *XPP, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::xppMainWindow)
{
	ui->setupUi(this);

	/* Remove the margins */
	ui->gridLayout->setMargin(0);

	/* Change the window title */
	this->setWindowTitle("xppaut 8.0");

	/* Prevent toggleable toolbars */
	setContextMenuPolicy(Qt::NoContextMenu);

	/* Connect to xpp core structure */
	xpp  = XPP;
	plot =&xpp->mainSettings.mainPlotWindow;

	/* Setup the individual toolbar menues */
	setupMenus();

	/* Setup the signal connections */
	setupConnections();

	/* Initialize the plot widget */
	initPlot();
	initGraphicsDialogs();
	initIntegrateDialogs();
	initNumericsDialogs();
	initPhasespaceDialogs();
	initViewDialogs();
	initWindowDialogs();
}

xppMainWindow::~xppMainWindow()
{
	ui->toolBar->deleteLater();
	delete ui;
}

/****************************************************************************************/
/*								GUI initialization helpers								*/
/****************************************************************************************/
void xppMainWindow::initPlot (void) {
	ui->plottWidget->xAxis->setLabel(QString::fromStdString(plot->xLabel));
	ui->plottWidget->xAxis->setRange(plot->xLim.first, plot->xLim.second);
	ui->plottWidget->xAxis->setAutoTickStep(false);
	ui->plottWidget->xAxis->setTickStep(ceil(plot->xLim.second-plot->xLim.first)/4);

	ui->plottWidget->yAxis->setLabel(QString::fromStdString(plot->yLabel));
	ui->plottWidget->yAxis->setRange(plot->yLim.first, plot->yLim.second);
	ui->plottWidget->yAxis->setAutoTickStep(false);
	ui->plottWidget->yAxis->setTickStep(ceil(plot->yLim.second-plot->yLim.first)/4);

	ui->plottWidget->replot();
}

/****************************************************************************************/
/*										Windows											*/
/****************************************************************************************/
void xppMainWindow::openAutoWindow (void) {
	Auto = new xppAutoWindow(xpp, this);
	Auto->show();
}

/****************************************************************************************/
/*										Menus											*/
/****************************************************************************************/
void xppMainWindow::setupMenus(void) {
	for (int i=0; i<xppMenus.size(); i++) {
		menuButtons.push_back(new xppMenuButton(xppMenus.at(i), this));
		ui->toolBar->addWidget(menuButtons.at(i));
	}
}

/****************************************************************************************/
/*									Dialog inits										*/
/****************************************************************************************/
void xppMainWindow::initGraphicsDialogs(void) {
	QList<xppMenuDialog*> dList = menuButtons.at(buttonGraphics)->dialogList;

	/* New Curve */
	unsigned i=0;
	dList.at(0)->lineEdit.at(i++)->setText(QString::fromStdString(plot->xLabel));
	dList.at(0)->lineEdit.at(i++)->setText(QString::fromStdString(plot->yLabel));
	dList.at(0)->lineEdit.at(i++)->setText(QString::fromStdString(plot->zLabel));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(0));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(1));

	/* Edit Curve */
	i=0;
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(1));
	dList.at(1)->lineEdit.at(i++)->setText(QString::fromStdString(plot->xLabel));
	dList.at(1)->lineEdit.at(i++)->setText(QString::fromStdString(plot->yLabel));
	dList.at(1)->lineEdit.at(i++)->setText(QString::fromStdString(plot->zLabel));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(0));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(1));

	/* Postscript options */
	i=0;
	dList.at(2)->lineEdit.at(i++)->setText(QString::number(1));
	dList.at(2)->lineEdit.at(i++)->setText(QString::fromStdString(plot->xLabel));
	dList.at(2)->lineEdit.at(i++)->setText(QString::fromStdString(plot->yLabel));
	i=0;
	dList.at(2)->checkBox.at(i++)->setChecked(true);
	dList.at(2)->checkBox.at(i++)->setChecked(true);

	/* Axes Options */
	i=0;
	dList.at(3)->lineEdit.at(i++)->setText(QString::number(plot->xOrigin));
	dList.at(3)->lineEdit.at(i++)->setText(QString::number(plot->yOrigin));
	dList.at(3)->lineEdit.at(i++)->setText(QString::number(plot->zOrigin));
	i=0;
	dList.at(3)->checkBox.at(i++)->setChecked(plot->useXOrigin);
	dList.at(3)->checkBox.at(i++)->setChecked(plot->useYOrigin);
	dList.at(3)->checkBox.at(i++)->setChecked(plot->useZOrigin);

	/* Colormap */
	i = 0;
	dList.at(4)->switchBox.at(0)->setChecked(true);
}

void xppMainWindow::initIntegrateDialogs(void) {
	QList<xppMenuDialog*> dList = menuButtons.at(buttonIntegrate)->dialogList;

	/* Range Integrate */
	unsigned i=0;
	dList.at(0)->lineEdit.at(i++)->setText(QString::fromStdString(plot->xLabel));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(20));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(plot->xLim.first));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(plot->xLim.second));
	i=0;
	dList.at(0)->checkBox.at(i++)->setChecked(true);
	dList.at(0)->checkBox.at(i++)->setChecked(true);
	dList.at(0)->checkBox.at(i++)->setChecked(false);
	dList.at(0)->checkBox.at(i++)->setChecked(false);

	/* Double Range Integrate */
	i=0;
	dList.at(1)->lineEdit.at(i++)->setText(QString::fromStdString(plot->xLabel));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(20));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(plot->xLim.first));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(plot->xLim.second));
	dList.at(1)->lineEdit.at(i++)->setText(QString::fromStdString(plot->yLabel));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(20));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(plot->yLim.first));
	dList.at(1)->lineEdit.at(i++)->setText(QString::number(plot->yLim.second));
	i=0;
	dList.at(1)->checkBox.at(i++)->setChecked(true);
	dList.at(1)->checkBox.at(i++)->setChecked(true);
	dList.at(1)->checkBox.at(i++)->setChecked(false);
	dList.at(1)->checkBox.at(i++)->setChecked(false);
	dList.at(1)->checkBox.at(i++)->setChecked(false);

	/* TODO PARSE */
}

void xppMainWindow::initNumericsDialogs(void) {
	QList<xppMenuDialog*> dList = menuButtons.at(buttonNumerics)->dialogList;

	/* Method */
	dList.at(0)->switchBox.at(0)->setChecked(true);
}

void xppMainWindow::initPhasespaceDialogs(void) {
	QList<xppMenuDialog*> dList = menuButtons.at(buttonPhasespace)->dialogList;

	/* Period */
	dList.at(0)->lineEdit.at(0)->setText(QString::number(2));

	/* TODO READ ODE */
}

void xppMainWindow::initViewDialogs(void) {
	for (xppMenuDialog *dialog : menuButtons.at(buttonView)->dialogList) {
		unsigned i=0;
		bool is3D = dialog->lineEdit.size()==12;
		/* Variable names */
		dialog->lineEdit.at(i++)->setText("t");
		dialog->lineEdit.at(i++)->setText("");
		if(is3D) {
			dialog->lineEdit.at(i++)->setText("");
		}
		/* Axis label */
		dialog->lineEdit.at(i++)->setText(QString::fromStdString(plot->xLabel));
		dialog->lineEdit.at(i++)->setText(QString::fromStdString(plot->yLabel));
		if(is3D) {
			dialog->lineEdit.at(i++)->setText(QString::fromStdString(plot->zLabel));
		}
		/* Axis limits */
		dialog->lineEdit.at(i++)->setText(QString::number(plot->xLim.first));
		dialog->lineEdit.at(i++)->setText(QString::number(plot->xLim.second));
		dialog->lineEdit.at(i++)->setText(QString::number(plot->yLim.first));
		dialog->lineEdit.at(i++)->setText(QString::number(plot->yLim.second));
		if(is3D) {
			dialog->lineEdit.at(i++)->setText(QString::number(plot->zLim.first));
			dialog->lineEdit.at(i++)->setText(QString::number(plot->zLim.second));
		}
	}
}

void xppMainWindow::initWindowDialogs(void) {
	QList<xppMenuDialog*> dList = menuButtons.at(buttonWindow)->dialogList;
	/* Window Range */
	unsigned i=0;
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(plot->xLim.first));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(plot->xLim.second));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(plot->yLim.first));
	dList.at(0)->lineEdit.at(i++)->setText(QString::number(plot->yLim.second));
}

/****************************************************************************************/
/*										Connections										*/
/****************************************************************************************/
void xppMainWindow::setupConnections (void) {
	connect(menuButtons.at(8)->actionList.at(9), SIGNAL(triggered()), this, SLOT(close()));
	connect(menuButtons.at(8)->actionList.at(3), SIGNAL(triggered()), this, SLOT(openAutoWindow()));
}
