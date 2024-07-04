#include "view_menu.h"

view_menu::view_menu(Data* item, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::view_menuClass())
	, m_item(item)
{
	ui->setupUi(this);

	if (item->data_type() == "Password") {
		ui->

	} 
	else if (item->data_type() == "CreditCards") {

	}
	else if (item->data_type() == "IdentityCards") {

	}
	else if (item->data_type() == "Notes") {

	}
}

view_menu::~view_menu()
{
	delete ui;
}
