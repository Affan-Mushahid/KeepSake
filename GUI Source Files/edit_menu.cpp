#include "../GUI Header Files/edit_menu.h"



edit_menu::edit_menu(User* u, Data* data_item, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::edit_menuClass())
	, m_data_item(data_item)
	, user(u)
{
	ui->setupUi(this);


	if (data_item->data_type() == "Password") {
		// Dynamic Cast to Password
		Password* p = dynamic_cast<Password*>(data_item);

		// Set edit menu window to show the Password menu
		ui->edit_stack->setCurrentIndex(0);

		// Set the text to be edited
		ui->p_title_text->setText(QString::fromStdString(p->title()));
		ui->p_website_text->setText(QString::fromStdString(p->website()));
		ui->p_password->setText(QString::fromStdString(p->password()));

	}
	else if (data_item->data_type() == "CreditCards") {
		CreditCards* p = dynamic_cast<CreditCards*>(data_item);

		ui->edit_stack->setCurrentIndex(1);

		ui->c_title_text->setText(QString::fromStdString(p->title()));
		ui->c_card_text->setText(QString::number(p->card()));
		ui->c_ssn_text->setText(QString::number(p->ssn()));
		ui->c_expiry_date->setDate(QDate((p->expiry().year()), (p->expiry().month()), (p->expiry().day())));
	}
	else if (data_item->data_type() == "IdentityCards") {
		IdentityCards* p = dynamic_cast<IdentityCards*>(data_item);

		ui->edit_stack->setCurrentIndex(2);

		ui->i_full_name_text->setText(QString::fromStdString(p->full_name()));
		ui->i_father_name_text->setText(QString::fromStdString(p->fathers_name()));
		ui->i_title_text->setText(QString::fromStdString(p->title()));
		ui->i_birth->setDate(QDate((p->birth().year()), (p->birth().month()), (p->birth().day())));
		ui->i_issue->setDate(QDate((p->issue().year()), (p->issue().month()), (p->issue().day())));
		ui->i_expiry->setDate(QDate((p->expiry().year()), (p->expiry().month()), (p->expiry().day())));
	}
	else if (data_item->data_type() == "Notes") {
		Notes* p = dynamic_cast<Notes*>(data_item);

		ui->edit_stack->setCurrentIndex(3);

		ui->n_title_text->setText(QString::fromStdString(p->title()));
		ui->n_content_text->setText(QString::fromStdString(p->content()));
	}
}


edit_menu::~edit_menu()
{
	delete ui;
}


void edit_menu::on_p_enter_btn_clicked() {
	Password* p = dynamic_cast<Password*>(m_data_item);

	p->edit_item(ui->p_title_text->text().toStdString(), ui->p_website_text->text().toStdString(), ui->p_password->text().toStdString());
	hide();
	emit item_edited();
}


void edit_menu::on_c_enter_btn_clicked() {
	Date* expiry = new Date(ui->c_expiry_date->date().day(), ui->c_expiry_date->date().month(), ui->c_expiry_date->date().year());

	CreditCards* c = dynamic_cast<CreditCards*>(m_data_item);

	c->edit_item(ui->c_title_text->text().toStdString(), ui->c_card_text->text().toLongLong(), ui->c_ssn_text->text().toLongLong(), *expiry);
	hide();
	emit item_edited();
}


void edit_menu::on_i_enter_btn_clicked() {
	Date* birth = new Date(ui->i_birth->date().day(), ui->i_birth->date().month(), ui->i_birth->date().year());
	Date* issue = new Date(ui->i_issue->date().day(), ui->i_issue->date().month(), ui->i_issue->date().year());
	Date* expiry = new Date(ui->i_expiry->date().day(), ui->i_expiry->date().month(), ui->i_expiry->date().year());

	IdentityCards* i = dynamic_cast<IdentityCards*>(m_data_item);
	
	i->edit_item(ui->i_title_text->text().toStdString(), ui->i_full_name_text->text().toStdString(), ui->i_father_name_text->text().toStdString(), *birth, *issue, *expiry);
	hide();
	emit item_edited();
	

}


void edit_menu::on_n_enter_btn_clicked() {
	Notes* n = dynamic_cast<Notes*>(m_data_item);

	n->edit_item(ui->n_title_text->text().toStdString(), ui->n_content_text->toPlainText().toStdString());
	hide();
	emit item_edited();
	
}


void edit_menu::on_generate_btn_clicked() {
	ui->p_password->setText(QString::fromStdString(user->m_password_generator.generate(ui->p_size_text->text().toInt(), ui->p_special_include->isChecked())));
}
