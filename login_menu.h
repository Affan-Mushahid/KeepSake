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

public:
	login_menu(Password_Generator P, Encryption E, QWidget *parent = nullptr);
	~login_menu();

private slots:
	void on_register_btn_clicked();

private:
	Ui::login_menuClass *ui;
	
	Account* account;
	
	Password_Generator password_engine;
	Encryption encryption_engine;

	user_type current_type;
};
