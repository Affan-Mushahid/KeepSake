#include "../GUI Header Files/admin_panel.h"



admin_panel::admin_panel(User* user, QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::admin_panelClass())
{
	ui->setupUi(this);
	m_user = dynamic_cast<AdministratorUser*>(user);  // To ensure we can access admin functions
}


admin_panel::~admin_panel()
{
	delete ui;
}


void admin_panel::on_change_btn_clicked() {
	if (ui->email_text->text().toStdString() != "" && ui->pass_text->text().toStdString() != "") {
		m_user->change_user_password(ui->pass_text->text().toStdString(), ui->email_text->text().toStdString());
	}
	close();
}
