#pragma once

#include <QDialog>
#include "ui_login_menu.h"
#include "user.h"
#include <pass_generator.h>
#include <encryption.h>


QT_BEGIN_NAMESPACE
namespace Ui { class login_menuClass; };
QT_END_NAMESPACE

class login_menu : public QDialog
{
	Q_OBJECT


signals:
	void account_success();


public:
	login_menu(Account* acc, Password_Generator& p, QWidget *parent = nullptr);
	~login_menu();


public slots:
	void on_register_btn_clicked();
	void on_login_btn_clicked();


private:
	Ui::login_menuClass *ui;
	
	Account* account;
	Password_Generator password_engine;

	user_type current_type;
};
