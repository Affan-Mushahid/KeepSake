#include "item_select_dialog.h"

item_select_dialog::item_select_dialog(User* u, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::item_select_dialogClass())
	, user(u)
{
	ui->setupUi(this);
	ui->add_stack->setCurrentIndex(0);
}

item_select_dialog::~item_select_dialog()
{
	delete ui;
}


void item_select_dialog::on_password_btn_clicked() {
	ui->add_stack->setCurrentIndex(1);
}


void item_select_dialog::on_credit_card_btn_clicked() {
	ui->add_stack->setCurrentIndex(2);
}


void item_select_dialog::on_identity_card_btn_clicked() {
	ui->add_stack->setCurrentIndex(3);
}


void item_select_dialog::on_note_btn_clicked() {
	ui->add_stack->setCurrentIndex(4);
}


void item_select_dialog::on_cancel_btn_clicked() {
	close();
}


void item_select_dialog::on_p_enter_btn_clicked() {
	//ui->p_title_text->text().toStdString()
	Password* p = new Password(ui->p_title_text->text().toStdString(), ui->p_website_text->text().toStdString(), ui->p_password->text().toStdString());

	user->add_item(p);
	ui->add_stack->setCurrentIndex(0);
	close();
}

void item_select_dialog::on_c_enter_btn_clicked() {
	CreditCards* c = new CreditCards(ui->c_title_text->text().toStdString(), ui->c_card_text->text().toInt(), ui->c_ssn_text->text().toInt(), ui->c_expiry_text->text().toStdString());

	user->add_item(c);
	ui->add_stack->setCurrentIndex(0);
	close();
}

void item_select_dialog::on_i_enter_btn_clicked() {
	Date* birth = new Date(ui->i_birth->date().day(), ui->i_birth->date().month(), ui->i_birth->date().year());
	Date* issue = new Date(ui->i_issue->date().day(), ui->i_issue->date().month(), ui->i_issue->date().year());
	Date* expiry = new Date(ui->i_issue->date().day(), ui->i_issue->date().month(), ui->i_issue->date().year());

	IdentityCards* i = new IdentityCards(ui->i_title_text->text().toStdString(), ui->i_full_name_text->text().toStdString(), ui->i_father_name_text->text().toStdString(), *birth, *issue, *expiry);
	user->add_item(i);
	ui->add_stack->setCurrentIndex(0);
	close();

}

void item_select_dialog::on_n_enter_btn_clicked() {
	Notes* n = new Notes(ui->n_title_text->text().toStdString(), ui->n_content_text->toPlainText().toStdString());

	user->add_item(n);
	ui->add_stack->setCurrentIndex(0);
	close();
}

void item_select_dialog::on_generate_btn_clicked() {
	ui->p_password->setText(QString::fromStdString(user->m_password_generator.generate(ui->p_size_text->text().toInt(), ui->p_special_include->isChecked())));
}