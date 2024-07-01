#include "login_menu.h"


login_menu::login_menu(Password_Generator P, Encryption E, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::login_menuClass())
	, account(new Account(E))
	, encryption_engine(E)
	, password_engine(P)
	, current_type(normal_user)
{
	ui->setupUi(this);
}

login_menu::~login_menu()
{
	delete ui;
}

void login_menu::on_register_btn_clicked() {
	
	if (!account->register_account(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString())) {
		ui->register_btn->setText("Incorrect");
	}
	else {
		this->close();
	}
}

void login_menu::on_login_btn_clicked() {
	if (!account->sign_in(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString())) {
		ui->register_btn->setText("Incorrect");
	}
	else {
		this->close();
	}
}