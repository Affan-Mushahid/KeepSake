#include "login_menu.h"


login_menu::login_menu(Account* acc, QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::login_menuClass())
	, account(acc)
	, current_type(normal_user)
{
	ui->setupUi(this);
	ui->error_code_text->setText("");

}

login_menu::~login_menu()
{
	delete ui;
}

void login_menu::close_everything() {
	this->close();
}


void login_menu::on_register_btn_clicked() {
	
	if (!account->register_account(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString())) {
		ui->error_code_text->setText("Account already exists");
	}
	else {
		this->close();
	}
}

void login_menu::on_login_btn_clicked() {
	if (!account->sign_in(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString())) {
		ui->error_code_text->setText("Email/Password is incorrect");
	}
	else {
		this->close();
	}
}