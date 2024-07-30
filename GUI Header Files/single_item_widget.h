#pragma once

#include <QWidget>
#include "ui_single_item_widget.h"
#include <string>
#include "../Header Files/data.h"
#include "confirm_dialog.h"
#include "view_menu.h"
#include "edit_menu.h"
#include "../Header Files/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class single_item_widgetClass; };
QT_END_NAMESPACE

class single_item_widget : public QWidget
{
	Q_OBJECT


private:
	Ui::single_item_widgetClass* ui; // Managing the UI

	//----- Menus -----//
	confirm_dialog* m_confirm_dialog;
	view_menu* m_view;
	edit_menu* m_edit;

	//----- Data Item -----//
	Data* m_data_item;
	User* user;
	

public:
	single_item_widget(User* u, Data* data_item, QWidget* parent = nullptr);
	~single_item_widget();


signals:
	void forward_delete_item(Data* item); // forwards the delete to refresh main window
	void forward_edit_item(); // forwards the edit to refresh main window


public slots:
	void get_delete_item(Data* item); // get the item to be deleted when delete button is pressed
	void send_edit_item(); // After item has been edited, send the signal back to main window
	void on_view_btn_clicked();
	void on_edit_btn_clicked();
	void on_delete_btn_clicked();
};
