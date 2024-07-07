#pragma once

#include <QMainWindow>
#include "ui_manager_window.h"
#include "login_menu.h"
#include "admin_panel.h"
#include "pass_generator.h"
#include "encryption.h"
#include "user.h"
#include "single_item_widget.h"
#include "category_item_widget.h"
#include "settings.h"
#include "item_select_dialog.h"
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
	void on_settings_btn_clicked();
	void on_add_btn_clicked();
	void logged_out();
	void item_added();
	void item_changed(); 

private:

	Ui::manager_windowClass *ui;
	login_menu* login_screen;
	admin_panel* admin;
	settings* setting;
	item_select_dialog* item_selection_menu;

	std::vector<single_item_widget*> data_item;

	std::vector<QListWidgetItem*> items;

	//std::vector<category_item_widget*> category_item;

	//std::vector<QListWidgetItem*> category;

	user_type current_user;

	Account* account;

	User* user;

	Password_Generator& password_engine;

	Encryption& encryption_engine;

	void create_categories_list();
	void create_items_list(std::string category = "", std::string search = "");
};
