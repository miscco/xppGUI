#ifndef XPPMENUDIALOG_H
#define XPPMENUDIALOG_H

#include <QButtonGroup>
#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QMenu>

#include "xppMenuLabels.h"

class xppMenuDialog : public QDialog
{
	Q_OBJECT
public:
	xppMenuDialog(QWidget *parent = 0);
	xppMenuDialog(xppDialog, QWidget *);

signals:

public slots:

private:
	QDialogButtonBox	*buttonBox;
	QGridLayout			*dialogLayout;
	QList<QFormLayout*> editLayout;
	QList<QVBoxLayout*> checkLayout;
	QList<QVBoxLayout*> switchLayout;

	QList<QLineEdit*>	lineEdit;
	QList<QCheckBox*>	checkBox;
	QList<QCheckBox*>	switchBox;
	QButtonGroup		*switchGroup;

	int					numCols,
						numRows,
						row;

	friend class xppAutoWindow;
	friend class xppMainWindow;
};

#endif // XPPMENUDIALOG_H
