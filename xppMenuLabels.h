#ifndef MENULABELS_H
#define MENULABELS_H

#include <QString>
#include <QStringList>


struct xppDialog {
	QString				Title;
	QStringList			EditLabels;
	QStringList			SwitchLabels;
	unsigned			actionIndex;
};

struct xppMenu {
	QString				Title;
	QStringList			Labels;
	QList<xppDialog>	Dialogs;
};

extern QList<xppMenu> xppMenus;

#endif // MENULABELS_H
