#include "view_menu.h"

view_menu::view_menu(Data* item, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::view_menuClass())
	, m_item(item)
{
	ui->setupUi(this);

	if (item->data_type() == "Password") {
		Password* p = dynamic_cast<Password*>(item);

		ui->view_stack->setCurrentIndex(0);

		ui->p_title->setText(QString::fromStdString(p->title()));
		ui->p_website->setText(QString::fromStdString(p->website()));
		ui->p_pass->setText(QString::fromStdString(p->password()));

	} 
	else if (item->data_type() == "CreditCards") {
		CreditCards* p = dynamic_cast<CreditCards*>(item);

		ui->view_stack->setCurrentIndex(1);

		ui->c_title->setText(QString::fromStdString(p->title()));
		ui->c_card->setText(QString::number(p->card()));
		ui->c_ssn->setText(QString::number(p->ssn()));
		ui->c_exp_date->setDate(QDate((p->expiry().year()), (p->expiry().month()), (p->expiry().day())));
	}
	else if (item->data_type() == "IdentityCards") {
		IdentityCards* p = dynamic_cast<IdentityCards*>(item);

		ui->view_stack->setCurrentIndex(2);

		ui->i_fullname->setText(QString::fromStdString(p->full_name()));
		ui->i_father->setText(QString::fromStdString(p->fathers_name()));
		ui->i_title->setText(QString::fromStdString(p->title()));
		ui->i_birth->setDate(QDate((p->birth().year()), (p->birth().month()), (p->birth().day())));
		ui->i_issue->setDate(QDate((p->issue().year()), (p->issue().month()), (p->issue().day())));
		ui->i_expiry->setDate(QDate((p->expiry().year()), (p->expiry().month()), (p->expiry().day())));
	}
	else if (item->data_type() == "Notes") {
		Notes* p = dynamic_cast<Notes*>(item);

		ui->view_stack->setCurrentIndex(3);

		ui->n_title->setText(QString::fromStdString(p->title()));
		ui->n_content->setText(QString::fromStdString(p->content()));
	}
}

view_menu::~view_menu()
{
	delete ui;
}
