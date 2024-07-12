#include "../GUI Header Files/category_item_widget.h"

category_item_widget::category_item_widget(std::string category, QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::category_item_widgetClass())
{
	ui->setupUi(this);
	ui->label->setText(QString::fromStdString(category));
}

category_item_widget::~category_item_widget()
{
	delete ui;
}
