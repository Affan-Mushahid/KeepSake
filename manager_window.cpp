#include "manager_window.h"


manager_window::manager_window(Password_Generator& P, Encryption& E, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::manager_windowClass())
{
	ui->setupUi(this);
	

	/*for (int i = 0; i < 12; i++) {
		items_1 = new QListWidgetItem;
		items.push_back(new single_item_widget(this));
		items[i]->show();

		items_1->setSizeHint(items[i]->sizeHint());


		ui->listWidget_2->addItem(items_1);
		ui->listWidget_2->setItemWidget(items_1, items[i]);
	}*/
}

manager_window::~manager_window()
{
	delete ui;
}
