#include "confirm_dialog.h"

confirm_dialog::confirm_dialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::confirm_dialogClass())
{
	ui->setupUi(this);
}

confirm_dialog::~confirm_dialog()
{
	delete ui;
}
