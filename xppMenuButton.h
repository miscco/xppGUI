#ifndef XPPMENUBUTTON_H
#define XPPMENUBUTTON_H

#include <QCheckBox>
#include <QDebug>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>

#include "xppMenuLabels.h"

class xppMenuButton : public QPushButton
{
	Q_OBJECT
public:
	explicit xppMenuButton(QWidget *parent = 0);
	xppMenuButton(xppMenu, QWidget *parent);

	QList<QAction*>		actionList;

signals:

public slots:

private:
	QMenu*				buttonMenu;
	QList<QDialog*>		dialogList;
};

#endif // XPPMENUBUTTON_H
