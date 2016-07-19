#include "xppMenuButton.h"

xppMenuButton::xppMenuButton(QWidget *parent) :
	QPushButton(parent)
{
}

xppMenuButton::xppMenuButton(xppMenu menu, QWidget *parent) :
	QPushButton(menu.Title, parent)
{
	/* Set the button style */
	this->setFlat(true);
	this->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");

	/* Set the shortcut to "X" rather than the default "Alt+X" */
	this->setShortcut(QKeySequence(menu.Title.at(menu.Title.indexOf("&")+1)));

	/* Add the menu */
	buttonMenu = new QMenu(this);
	this->setMenu(buttonMenu);

	/* Enable buttons without a menu e.g. Continue */
	if(menu.Labels.isEmpty()) {
		this->addAction(new QAction(menu.Title, this));
	} else {
		/* Create the actions of the menu*/
		for (int i=0; i<menu.Labels.size(); i++) {
			buttonMenu->addAction(new QAction(menu.Labels.at(i), buttonMenu));
		}
	}

	/* Get the list of actions */
	actionList = buttonMenu->actions();

	/* Add the dialogs */
	if (!menu.Dialogs.isEmpty()) {
		for (int i=0; i<menu.Dialogs.size(); i++) {
			/* Create the new dialog */
			dialogList.push_back(new QDialog(this));
			dialogList.back()->setWindowTitle(menu.Dialogs.at(i).Title);

			/* Overarching layout for multiple columns */
			QGridLayout *dialogLayout = new QGridLayout(dialogList.back());

			/* Even the number of fields */
			int numCols   = ceil((double)menu.Dialogs.at(i).EditLabels.size()/6);
			int numFields = ceil((double)menu.Dialogs.at(i).EditLabels.size()/numCols);

			/* Use a layout allowing to have a label next to each field */
			int nrows =0;
			QFormLayout* editLayout = new QFormLayout();
			for (int j=0; j<menu.Dialogs.at(i).EditLabels.size(); ++j) {
				if(j%numFields==0 && j!=0 &&j!=menu.Dialogs.at(i).EditLabels.size()-1) {
					dialogLayout->addLayout(editLayout, 0, nrows++);
					editLayout = new QFormLayout();
				}
				editLayout->addRow(menu.Dialogs.at(i).EditLabels.at(j), new QLineEdit());
			}
			dialogLayout->addLayout(editLayout, 0, nrows++);

			/* Use a layout allowing to have a label next to each field */
			QVBoxLayout* layoutSwitches = new QVBoxLayout();
			for (int j=0; j<menu.Dialogs.at(i).SwitchLabels.size(); ++j) {
				if(j%numFields==0 && j!=0 && j!=menu.Dialogs.at(i).EditLabels.size()-1) {
					dialogLayout->addLayout(layoutSwitches, 0, nrows++, Qt::AlignTop);
					layoutSwitches = new QVBoxLayout();
				}
				layoutSwitches->addWidget(new QCheckBox(menu.Dialogs.at(i).SwitchLabels.at(j)));
			}
			dialogLayout->addLayout(layoutSwitches, 0, nrows, Qt::AlignTop);

			/* Add some standard buttons (Cancel/Ok) at the bottom of the dialog */
			QDialogButtonBox *buttonBox =
					new QDialogButtonBox(QDialogButtonBox::Ok |QDialogButtonBox::Cancel,
										 Qt::Horizontal,dialogList.back());
			dialogLayout->addWidget(buttonBox, 1, 0);

			connect(buttonBox, SIGNAL(accepted()), dialogList.back(), SLOT(accept()));
			connect(buttonBox, SIGNAL(rejected()), dialogList.back(), SLOT(reject()));
			connect(actionList.at(menu.Dialogs.at(i).actionIndex), SIGNAL(triggered()),
					dialogList.back(), SLOT(show()));
		}
	}
}
