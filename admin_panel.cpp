#include "admin_panel.h"

admin_panel::admin_panel(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::admin_panelClass())
{
	ui->setupUi(this);
}

admin_panel::~admin_panel()
{
	delete ui;
}
