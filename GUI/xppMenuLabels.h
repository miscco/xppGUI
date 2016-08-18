#ifndef MENULABELS_H
#define MENULABELS_H

#include <QString>
#include <QStringList>


struct xppDialog {
	QString				Title;
	QStringList			EditLabels;
	QStringList			CheckLabels;
	QStringList			SwitchLabels;
	unsigned			actionIndex;
};

struct xppMenu {
	QString				Title;
	QStringList			Labels;
	QList<xppDialog>	Dialogs;
};

extern QList<xppMenu> xppMenus;
extern QList<xppMenu> autoMenus;

#endif // MENULABELS_H
