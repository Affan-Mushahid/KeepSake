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

	QPixmap pix(":/KeepSake/KeepSake_New.png");
	QTransform tr;
	tr.rotate(270);
	ui->img_label->setPixmap(pix.scaled(230, 230, Qt::KeepAspectRatio).transformed(tr));
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
		ui->email_text->setText("");
		ui->password_text->setText("");
		ui->error_code_text->setText("");
		emit account_success(current_type);
	}
}

void login_menu::on_login_btn_clicked() {
	if (!account->sign_in(current_type, ui->email_text->text().toStdString(), ui->password_text->text().toStdString(), password_engine)) {
		ui->error_code_text->setText("Email/Password is incorrect");
	}
	else {
		ui->email_text->setText("");
		ui->password_text->setText("");
		ui->error_code_text->setText("");
		emit account_success(current_type);
	}
}

void login_menu::on_admin_btn_clicked() {
	

	switch (current_type) {
	case normal_user:
		current_type = admin_user;
		ui->admin_btn->setText("User? Click here");
		ui->error_code_text->setText("");
		break;

	case admin_user:
		current_type = normal_user;
		ui->admin_btn->setText("Admin? Click here");
		ui->error_code_text->setText("");
	}
	
}


void login_menu::closeEvent(QCloseEvent* event) {
	emit close_app();
}