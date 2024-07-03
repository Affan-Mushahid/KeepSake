#include "single_item_widget.h"

single_item_widget::single_item_widget(Data* data_item, QWidget* parent)
	: QWidget(parent)
	, m_data_item(data_item)
	, ui(new Ui::single_item_widgetClass())
{
	ui->setupUi(this);

	ui->title_label->setText(QString::fromStdString(m_data_item->title()));
	ui->datatype_label->setText(QString::fromStdString(m_data_item->data_type()));
	hide();
}

single_item_widget::~single_item_widget()
{
	delete ui;
}


void single_item_widget::on_view_btn_clicked() {

}


void single_item_widget::on_edit_btn_clicked() {

}


void single_item_widget::on_delete_btn_clicked() {

}