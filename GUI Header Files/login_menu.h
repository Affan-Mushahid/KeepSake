#pragma once

#include <QDialog>
#include "ui_login_menu.h"
#include "../Header Files/user.h"
#include "../Header Files/pass_generator.h"
#include "../Header Files/encryption.h"


QT_BEGIN_NAMESPACE
namespace Ui { class login_menuClass; };
QT_END_NAMESPACE

class login_menu : public QDialog
{
	Q_OBJECT

private:
	Ui::login_menuClass* ui;
	Account* account; // Create or login the user
	Password_Generator password_engine;
	user_type current_type; // The type of user logging in


public:
	login_menu(Account* acc, Password_Generator& p, QWidget* parent = nullptr);
	~login_menu();
	void closeEvent(QCloseEvent* event); // Overriding the default close Event


signals:
	void account_success(user_type& usertype);
	void close_app(); // When pressing the close button, send signal to manager window to close app


public slots:
	void on_register_btn_clicked();
	void on_login_btn_clicked();
	void on_admin_btn_clicked();
};
