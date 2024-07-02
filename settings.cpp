#include "settings.h"

settings::settings(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::settingsClass())
{
	ui->setupUi(this);
}

settings::~settings()
{
	delete ui;
}
