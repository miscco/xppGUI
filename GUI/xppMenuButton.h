#ifndef XPPMENUBUTTON_H
#define XPPMENUBUTTON_H

#include <QDebug>
#include <QMenu>
#include <QPushButton>

#include "xppMenuDialog.h"
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
	QMenu*					buttonMenu;
	QList<xppMenuDialog*>	dialogList;
	QAction					*pushAction;

	friend class xppAutoWindow;
	friend class xppMainWindow;
};

#endif // XPPMENUBUTTON_H
