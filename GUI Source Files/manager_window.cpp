#include "../GUI Header Files/manager_window.h"


manager_window::manager_window(Password_Generator& P, Encryption& E, QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::manager_windowClass())
	, account(new Account(E))
	, password_engine(P)
	, encryption_engine(E)
	, current_user(normal_user)
{
	ui->setupUi(this);

	login_screen = new login_menu(account, P, this);

	connect(login_screen, SIGNAL(account_success(user_type&)), this, SLOT(logged_in(user_type&)));
	connect(login_screen, &login_menu::close_app, this, QCoreApplication::quit, Qt::QueuedConnection);

	login_screen->show();
}


manager_window::~manager_window()
{
	delete ui;
}


void manager_window::logged_in(user_type& usertype) {
	login_screen->hide();
	
	current_user = usertype;

	user = account->user;

	if (current_user == admin_user) {
		ui->admin_panel_btn->show();
	}
	else {
		ui->admin_panel_btn->hide();
	}

	create_items_list();
	create_categories_list();

	setting = new settings(current_user, account, this);
	item_selection_menu = new item_select_dialog(user, this);

	connect(ui->data_category_list, &QListWidget::currentRowChanged, this, &manager_window::change_category);
	connect(setting, SIGNAL(user_deleted()), this, SLOT(logged_out()));
	connect(item_selection_menu, SIGNAL(item_created()), this, SLOT(item_added()));

	this->show();
	
}



void manager_window::logged_out() {

	disconnect(ui->data_category_list, &QListWidget::currentRowChanged, this, &manager_window::change_category);
	disconnect(setting, SIGNAL(user_deleted()), this, SLOT(logged_out()));
	disconnect(item_selection_menu, SIGNAL(item_created()), this, SLOT(item_added()));

	for (int i = 0; i < category.size(); i++) {
		ui->data_category_list->removeItemWidget(category[i]);
		ui->data_category_list->takeItem(i);
		delete category[i];
		category_item[i]->hide();
		delete category_item[i];
	}

	category.clear();
	category_item.clear();

	setting->close();
	item_selection_menu->close();
	delete setting;
	delete item_selection_menu;
	login_screen->show();
	hide();
}


void manager_window::item_added() {
	create_items_list();
}


void manager_window::delete_item(Data* item) {
	for (int i = 0; i < data_item.size(); i++) {
		disconnect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
		disconnect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed())); 
	}
	user->remove_item(item);
	create_items_list();
}

void manager_window::item_changed() {
	for (int i = 0; i < data_item.size(); i++) {
		disconnect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*))); 
		disconnect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
	}

	create_items_list();
}

void manager_window::change_category(int row) {

	for (int i = 0; i < data_item.size(); i++) {
		disconnect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
		disconnect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
	}

	switch (row) {
	case 0:
		create_items_list();
		break;

	case 1:
		create_items_list("Password");
		break;

	case 2:
		create_items_list("CreditCards");
		break;

	case 3:
		create_items_list("IdentityCards");
		break;

	case 4:
		create_items_list("Notes");
		break;
	}

}


void manager_window::on_admin_panel_btn_clicked() {
	admin = new admin_panel(user, this);

	admin->show();
}


void manager_window::on_settings_btn_clicked() {
	setting->show();
}


void manager_window::on_add_btn_clicked() {
	item_selection_menu->show();
}

void manager_window::create_categories_list() {
	category_item.push_back(new category_item_widget("No Category", this));
	category_item.push_back(new category_item_widget("Passwords", this));
	category_item.push_back(new category_item_widget("Credit Cards", this));
	category_item.push_back(new category_item_widget("Identity Cards", this));
	category_item.push_back(new category_item_widget("Notes", this));

	for (int i = 0; i < 5; i++) {
		category.push_back(new QListWidgetItem);
		category[i]->setSizeHint(category_item[i]->sizeHint());

		ui->data_category_list->addItem(category[i]);
		ui->data_category_list->setItemWidget(category[i], category_item[i]);
		//category_item[i]->show();
	}
}

void manager_window::create_items_list(std::string category, std::string search) {
	for (int i = 0; i < items.size(); i++) {
		ui->data_item_list->removeItemWidget(items[i]);
		ui->data_item_list->takeItem(i);
		delete items[i];
		data_item[i]->hide();
		if(data_item[i] != nullptr)
			delete data_item[i];
	}

	items.clear();
	data_item.clear();

	for (int i = 0; i < user->items().size(); i++) {
		user->items();
		if (category == "Password") {
			if ((user->items())[i]->data_type() == "Password") {
				items.push_back(new QListWidgetItem);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
			}
			else {
				items.push_back(nullptr);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
				continue;
			}
		}
		else if (category == "CreditCards") {
			if ((user->items())[i]->data_type() == "CreditCards") {
				items.push_back(new QListWidgetItem);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
			} else {
				items.push_back(nullptr);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
				continue;
			}
		}
		else if (category == "IdentityCards") {
			if ((user->items())[i]->data_type() == "IdentityCards") {
				items.push_back(new QListWidgetItem);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
			} else {
				items.push_back(nullptr);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
				continue;
			}
		}
		else if (category == "Notes") {
			if ((user->items())[i]->data_type() == "Notes") {
				items.push_back(new QListWidgetItem);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
			} else {
				items.push_back(nullptr);
				data_item.push_back(new single_item_widget(user, (user->items())[i], this));
				continue;
			}
		}
		else {
			items.push_back(new QListWidgetItem);
			data_item.push_back(new single_item_widget(user, (user->items())[i], this));
		}

		items[i]->setSizeHint(data_item[i]->sizeHint());

		ui->data_item_list->addItem(items[i]);

		ui->data_item_list->setItemWidget(items[i], data_item[i]);
		//data_item[i]->show();

	}


	for (int i = 0; i < data_item.size(); i++) {
		//connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
		//connect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));

		if (category == "Password") {
			if ((user->items())[i]->data_type() == "Password") {
				connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
				connect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
			}
			else {
				continue;
			}
		}
		else if (category == "CreditCards") {
			if ((user->items())[i]->data_type() == "CreditCards") {
				connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
				connect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
			}
			else {
				continue;
			}
		}
		else if (category == "IdentityCards") {
			if ((user->items())[i]->data_type() == "IdentityCards") {
				connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
				connect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
			}
			else {
				continue;
			}
		}
		else if (category == "Notes") {
			if ((user->items())[i]->data_type() == "Notes") {
				connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
				connect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
			}
			else {
				continue;
			}
		}
		else {
			connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
			connect(data_item[i], SIGNAL(forward_edit_item()), this, SLOT(item_changed()));
		}
	}
}