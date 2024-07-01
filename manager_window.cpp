#include "manager_window.h"

manager_window::manager_window(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::manager_windowClass())
{
	ui->setupUi(this);
}

manager_window::~manager_window()
{
	delete ui;
}
