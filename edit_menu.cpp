#include "edit_menu.h"

edit_menu::edit_menu(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::edit_menuClass())
{
	ui->setupUi(this);
}

edit_menu::~edit_menu()
{
	delete ui;
}
