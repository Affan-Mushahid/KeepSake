#include "view_menu.h"

view_menu::view_menu(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::view_menuClass())
{
	ui->setupUi(this);
}

view_menu::~view_menu()
{
	delete ui;
}
