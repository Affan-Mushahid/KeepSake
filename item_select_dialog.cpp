#include "item_select_dialog.h"

item_select_dialog::item_select_dialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::item_select_dialogClass())
{
	ui->setupUi(this);
}

item_select_dialog::~item_select_dialog()
{
	delete ui;
}
