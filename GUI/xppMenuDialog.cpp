#include "xppMenuDialog.h"

xppMenuDialog::xppMenuDialog(xppDialog dialog, QWidget *parent):
	QDialog(parent)
{
	/* Create the new dialog */
	this->setWindowTitle(dialog.Title);
	this->setWindowFlags(Qt::Dialog |
						 Qt::CustomizeWindowHint |
						 Qt::WindowTitleHint);

	/* Overarching layout for multiple columns */
	dialogLayout = new QGridLayout(this);

	/* Calculate the number of rows, to make the window appear more square like */
	int length = std::max(std::max(dialog.EditLabels.size(),
								   dialog.CheckLabels.size()),
						  dialog.SwitchLabels.size());
	numCols = ceil((double)length/6);
	numRows = ceil((double)length/numCols);
	row =0;

	/* Use a layout allowing to have a label next to each field */
	if (!dialog.EditLabels.isEmpty()) {
		editLayout.push_back(new QFormLayout());
		for (int i=0; i<dialog.EditLabels.size(); i++) {
			if(i%numRows==0 && i!=0 && i!=dialog.EditLabels.size()-1) {
				dialogLayout->addLayout(editLayout.back(), 0, row++);
				editLayout.push_back(new QFormLayout());
			}
			lineEdit.push_back(new QLineEdit());
			editLayout.back()->addRow(dialog.EditLabels.at(i), lineEdit.back());
		}
		dialogLayout->addLayout(editLayout.back(), 0, row++);
	}

	/* Use a vertical layout for the checkboxes */
	if (!dialog.CheckLabels.isEmpty()) {
		QVBoxLayout* layoutChecks = new QVBoxLayout();
		for (int i=0; i<dialog.CheckLabels.size(); i++) {
			if(i%numRows==0 && i!=0 && i!=dialog.CheckLabels.size()-1) {
				dialogLayout->addLayout(layoutChecks, 0, row++, Qt::AlignTop);
				layoutChecks = new QVBoxLayout();
			}
			checkBox.push_back(new QCheckBox(dialog.CheckLabels.at(i)));
			layoutChecks->addWidget(checkBox.back());
		}
		dialogLayout->addLayout(layoutChecks, 0, row++, Qt::AlignTop);
	}

	/* Use a vertical layout for the checkboxes and add a QActionGroup
	 * for exclusive switches */
	if (!dialog.SwitchLabels.isEmpty()) {
		QVBoxLayout  *layoutSwitch = new QVBoxLayout();
		switchGroup  = new QButtonGroup(this);
		for (int i=0; i<dialog.SwitchLabels.size(); i++) {
			if(i%numRows==0 && i!=0 && i!=dialog.SwitchLabels.size()-1) {
				dialogLayout->addLayout(layoutSwitch, 0, row++, Qt::AlignTop);
				layoutSwitch = new QVBoxLayout();
			}
			switchBox.push_back(new QCheckBox(dialog.SwitchLabels.at(i)));
			switchGroup->addButton(switchBox.back(), i);
			layoutSwitch->addWidget(switchGroup->button(i));
		}
		/* Define the selected version */
		switchGroup->button(0)->setChecked(true);
		dialogLayout->addLayout(layoutSwitch, 0, row++, Qt::AlignTop);
	}

	/* Add some standard buttons (Cancel/Ok) at the bottom of the dialog */
	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
									 QDialogButtonBox::Cancel,
									 Qt::Horizontal,this);
	dialogLayout->addWidget(buttonBox, 1, 0);

	/* Connect the button to the respective signals */
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
