#include "single_item_widget.h"

single_item_widget::single_item_widget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::single_item_widgetClass())
{
	ui->setupUi(this);
}

single_item_widget::~single_item_widget()
{
	delete ui;
}
