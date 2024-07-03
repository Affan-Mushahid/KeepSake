#pragma once

#include <QDialog>
#include "ui_login_menu.h"
#include "user.h"
#include <pass_generator.h>
#include <encryption.h>
#include <manager_window.h>


QT_BEGIN_NAMESPACE
namespace Ui { class login_menuClass; };
QT_END_NAMESPACE

class login_menu : public QDialog
{
	Q_OBJECT

public:
	login_menu(Account* acc, QWidget *parent = nullptr);
	~login_menu();

public slots:
	void on_register_btn_clicked();
	void on_login_btn_clicked();
	void close_everything();

private:
	Ui::login_menuClass *ui;
	
	Account* account;

	user_type current_type;
};
