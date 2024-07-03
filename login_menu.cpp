#include "login_menu.h"


login_menu::login_menu(Account* acc, Password_Generator& p, QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::login_menuClass())
	, account(acc)
	, password_engine(p)
	, current_type(normal_user)
{
	ui->setupUi(this);
	ui->error_code_text->setText("");

}

login_menu::~login_menu()
{
	delete ui;
}


void login_menu::on_register_btn_clicked() {
	
	if (!account->register_account(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString(), password_engine)) {
		ui->error_code_text->setText("Account already exists");
	}
	else {
		emit account_success();
	}
}

void login_menu::on_login_btn_clicked() {
	if (!account->sign_in(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString(), password_engine)) {
		ui->error_code_text->setText("Email/Password is incorrect");
	}
	else {
		emit account_success();
	}
}