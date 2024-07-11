#include "single_item_widget.h"

single_item_widget::single_item_widget(User* u, Data* data_item, QWidget* parent)
	: QWidget(parent)
	, m_data_item(data_item)
	, ui(new Ui::single_item_widgetClass())
	, user(u)
{
	ui->setupUi(this);

	ui->title_label->setText(QString::fromStdString(m_data_item->title()));
	ui->datatype_label->setText(QString::fromStdString(m_data_item->data_type()));
	hide();

	m_confirm_dialog = new confirm_dialog(m_data_item, this);

	m_view = new view_menu(m_data_item, this);
	m_edit = new edit_menu(user, m_data_item, this);

	connect(m_confirm_dialog, SIGNAL(delete_item_true(Data*)), this, SLOT(get_delete_item(Data*)));
	connect(m_edit, SIGNAL(item_edited()), this, SLOT(send_edit_item()));
}

single_item_widget::~single_item_widget()
{
	delete ui;
}


void single_item_widget::get_delete_item(Data* item) {
	emit forward_delete_item(item);
}

void single_item_widget::send_edit_item() {
	emit forward_edit_item();
}

void single_item_widget::on_view_btn_clicked() {
	m_view->show();
}


void single_item_widget::on_edit_btn_clicked() {
	m_edit->show();
}


void single_item_widget::on_delete_btn_clicked() {
	m_confirm_dialog->show();
}