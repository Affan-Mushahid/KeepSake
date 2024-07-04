#pragma once

#include <QWidget>
#include "ui_single_item_widget.h"
#include <string>
#include "data.h"
#include "confirm_dialog.h"
#include "view_menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class single_item_widgetClass; };
QT_END_NAMESPACE

class single_item_widget : public QWidget
{
	Q_OBJECT



signals:
	void forward_delete_item(Data* item);

public:
	single_item_widget(Data* data_item, QWidget *parent = nullptr);
	~single_item_widget();


public slots:
	void get_delete_item(Data* item);
	void on_view_btn_clicked();
	void on_edit_btn_clicked();
	void on_delete_btn_clicked();

private:
	Ui::single_item_widgetClass *ui;

	Data* m_data_item;
	confirm_dialog* m_confirm_dialog;
	view_menu* m_view;

};
