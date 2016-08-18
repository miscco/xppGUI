#include "xppMenuButton.h"

xppMenuButton::xppMenuButton(xppMenu menu, QWidget *parent) :
	QPushButton(menu.Title, parent)
{
	/* Set the button style */
	this->setFlat(true);
	this->setStyleSheet("QPushButton::menu-indicator{ image:url(none.jpg); }");

	/* Set the shortcut to "X" rather than the default "Alt+X" */
	this->setShortcut(QKeySequence(menu.Title.at(menu.Title.indexOf("&")+1)));

	/* Enable buttons without a menu e.g. Continue */
	if(!menu.Labels.isEmpty()) {
		/* Add the menu */
		buttonMenu = new QMenu(this);
		this->setMenu(buttonMenu);

		/* Create the actions of the menu*/
		for (int i=0; i<menu.Labels.size(); i++) {
			buttonMenu->addAction(new QAction(menu.Labels.at(i), buttonMenu));
		}
		/* Get the list of actions */
		actionList = buttonMenu->actions();
	}

	/* Add the dialogs */
	if (!menu.Dialogs.isEmpty()) {
		for (int i=0; i<menu.Dialogs.size(); i++) {
			/* Create the new menu dialog */
			dialogList.push_back(new xppMenuDialog(menu.Dialogs.at(i), this));

			/* Connect it to the corresponding action slot or to the button
			 * itself if there are no labels.
			 */
			if (!menu.Labels.isEmpty()) {
				connect(actionList.at(menu.Dialogs.at(i).actionIndex), SIGNAL(triggered()),
						dialogList.back(), SLOT(exec()));
			} else {
				connect(this, SIGNAL(clicked()), dialogList.back(), SLOT(exec()));
			}
		}
	}
}
