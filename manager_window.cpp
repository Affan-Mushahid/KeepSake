#include "manager_window.h"

manager_window::manager_window(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::manager_windowClass())
{
	ui->setupUi(this);
	items.push_back(new single_item_widget(this));
	items[0]->show();

	ui->items_container->addWidget(items[0]);
}

manager_window::~manager_window()
{
	delete ui;
}
