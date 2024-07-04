#pragma once

#include <QMainWindow>
#include "ui_settings.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class settingsClass; };
QT_END_NAMESPACE

class settings : public QMainWindow
{
	Q_OBJECT


signals:
	void user_deleted();

public:
	settings(user_type u, Account* acc, QWidget *parent = nullptr);
	~settings();

public slots:
	void on_email_btn_clicked();
	void on_password_btn_clicked();
	void on_sign_out_btn_clicked();

private:
	Ui::settingsClass *ui;
	Account* account;
	User* user;
};
