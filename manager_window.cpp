#include "manager_window.h"


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

	login_screen->show();
}


void manager_window::logged_in(user_type& usertype) {
	login_screen->close();
	
	current_user = usertype;

	user = account->user;

	if (current_user == admin_user) {
		ui->admin_panel_btn->show();
	}
	else {
		ui->admin_panel_btn->hide();
	}

	create_items_list();

	this->show();
}


void manager_window::delete_item(Data* item) {
	for (int i = 0; i < data_item.size(); i++) {
		disconnect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
	}
	user->remove_item(item);
	create_items_list();
}



void manager_window::on_admin_panel_btn_clicked() {
	admin = new admin_panel(this);

	admin->show();
}


void manager_window::create_items_list(std::string category, std::string search) {
	/*for (int i = 0; i < 12; i++) {
		items_1 = new QListWidgetItem;
		items.push_back(new single_item_widget(this));
		items[i]->show();

		items_1->setSizeHint(items[i]->sizeHint());


		ui->listWidget_2->addItem(items_1);
		ui->listWidget_2->setItemWidget(items_1, items[i]);
	}*/

	for (int i = 0; i < items.size(); i++) {
		ui->data_item_list->removeItemWidget(items[i]);
		ui->data_item_list->takeItem(i);
		delete items[i];
		delete data_item[i];
	}

	items.clear();
	data_item.clear();

	for (int i = 0; i < user->items().size(); i++) {
		items.push_back(new QListWidgetItem);
		user->items();
		if (category == "Password") {
			if ((user->items())[i]->data_type() == "Password") {
				data_item.push_back(new single_item_widget((user->items())[i], this));
			}
			else {
				continue;
			}
		}
		else if (category == "CreditCards") {
			if ((user->items())[i]->data_type() == "CreditCards") {
				data_item.push_back(new single_item_widget((user->items())[i], this));
			} else {
				continue;
			}
		}
		else if (category == "IdentityCards") {
			if ((user->items())[i]->data_type() == "IdentityCards") {
				data_item.push_back(new single_item_widget((user->items())[i], this));
			} else {
				continue;
			}
		}
		else if (category == "Notes") {
			if ((user->items())[i]->data_type() == "Notes") {
				data_item.push_back(new single_item_widget((user->items())[i], this));
			} else {
				continue;
			}
		}
		else {
			data_item.push_back(new single_item_widget((user->items())[i], this));
		}

		//data_item.push_back(new single_item_widget((user->items())[i], this));
		

		items[i]->setSizeHint(data_item[i]->sizeHint());

		ui->data_item_list->addItem(items[i]);

		ui->data_item_list->setItemWidget(items[i], data_item[i]);
		data_item[i]->show();

	}


	for (int i = 0; i < data_item.size(); i++) {
		connect(data_item[i], SIGNAL(forward_delete_item(Data*)), this, SLOT(delete_item(Data*)));
	}
}





manager_window::~manager_window()
{
	delete ui;
}
