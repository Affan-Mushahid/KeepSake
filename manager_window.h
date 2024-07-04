#pragma once

#include <QMainWindow>
#include "ui_manager_window.h"
#include "login_menu.h"
#include "admin_panel.h"
#include "pass_generator.h"
#include "encryption.h"
#include "user.h"
#include "single_item_widget.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class manager_windowClass; };
QT_END_NAMESPACE

class manager_window : public QMainWindow
{
	Q_OBJECT



public:
	manager_window(Password_Generator& P, Encryption& E, QWidget *parent = nullptr);
	~manager_window();

public slots:
	void delete_item(Data* item);
	void logged_in(user_type& usertype);
	void on_admin_panel_btn_clicked();

private:

	Ui::manager_windowClass *ui;
	login_menu* login_screen;
	admin_panel* admin;

	std::vector<single_item_widget*> data_item;

	std::vector<QListWidgetItem*> items;

	user_type current_user;

	Account* account;

	User* user;

	Password_Generator& password_engine;

	Encryption& encryption_engine;

	void create_items_list(std::string category = "", std::string search = "");
};
