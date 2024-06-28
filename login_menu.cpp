#include "login_menu.h"

login_menu::login_menu(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::login_menuClass())
{
	ui->setupUi(this);
}

login_menu::~login_menu()
{
	delete ui;
}