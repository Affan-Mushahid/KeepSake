#include "settings.h"

settings::settings(user_type u, Account* acc, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::settingsClass())
	, account(acc)
	,current_Type(u)
{
	ui->setupUi(this);

	user = account->user;
}

settings::~settings()
{
	delete ui;
}


void settings::on_email_btn_clicked() {
	if (ui->email_text->text().toStdString() != "") {
		user->change_email(ui->email_text->text().toStdString());
	}
	else {
		return;
	}
}


void settings::on_password_btn_clicked() {
	if (ui->password_text->text().toStdString() != "") {
		user->change_password(ui->password_text->text().toStdString());
	}
	else {
		return;
	}
	
}


void settings::on_sign_out_btn_clicked() {
	account->sign_out(current_Type);
	hide();
	emit user_deleted();
}