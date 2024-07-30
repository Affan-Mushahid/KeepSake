#pragma once

#include <QMainWindow>
#include "ui_settings.h"
#include "../Header Files/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class settingsClass; };
QT_END_NAMESPACE

class settings : public QMainWindow
{
	Q_OBJECT


private:
	Ui::settingsClass* ui;
	Account* account;
	User* user;
	user_type current_Type;


public:
	settings(user_type u, Account* acc, QWidget* parent = nullptr);
	~settings();


signals:
	void user_deleted();


public slots:
	void on_email_btn_clicked();
	void on_password_btn_clicked();
	void on_sign_out_btn_clicked();
};
