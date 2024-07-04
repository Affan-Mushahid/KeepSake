#include "confirm_dialog.h"

confirm_dialog::confirm_dialog(Data* item, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::confirm_dialogClass())
	, m_item(item)
{
	ui->setupUi(this);
}

confirm_dialog::~confirm_dialog()
{
	delete ui;
}


void confirm_dialog::on_yes_btn_clicked() {
	hide();
	emit delete_item_true(m_item);
}