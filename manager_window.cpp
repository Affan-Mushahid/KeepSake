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

	/*for (int i = 0; i < 12; i++) {
		items_1 = new QListWidgetItem;
		items.push_back(new single_item_widget(this));
		items[i]->show();

		items_1->setSizeHint(items[i]->sizeHint());


		ui->listWidget_2->addItem(items_1);
		ui->listWidget_2->setItemWidget(items_1, items[i]);
	}*/

	connect(login_screen, SIGNAL(account_success(user_type&)), this, SLOT(logged_in(user_type&)));

	login_screen->show();
}

void manager_window::logged_in(user_type& usertype) {
	login_screen->close();

	
	current_user = usertype;

	if (current_user == admin_user) {
		ui->admin_panel_btn->show();
	}
	else {
		ui->admin_panel_btn->hide();
	}

	this->show();
}

manager_window::~manager_window()
{
	delete ui;
}
