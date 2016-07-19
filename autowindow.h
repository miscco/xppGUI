#ifndef AUTOWINDOW_H
#define AUTOWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class AutoWindow;
}

class AutoWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit AutoWindow(QWidget *parent = 0);
	~AutoWindow();

private:
	Ui::AutoWindow *ui;

	QMenu *menuAxes;
	QMenu *menuUserPeriod;
	QMenu *menuFile;

	QPushButton *buttonParameter;
	QPushButton *buttonNumerics;
	QPushButton *buttonRun;
	QPushButton *buttonGrab;
	QPushButton *buttonClear;
	QPushButton *buttonRedraw;

	/* Helper functions for GUI initialization */
	void setupButtonParameter	(void);
	void setupButtonNumerics	(void);
	void setupButtonRun			(void);
	void setupButtonGrab		(void);
	void setupButtonClear		(void);
	void setupButtonRedraw		(void);

	void setupMenus				(void);
	void setupMenuAxes			(void);
	void setupMenuFile			(void);
	void setupMenuUserPeriod	(void);
};

#endif // AUTOWINDOW_H
