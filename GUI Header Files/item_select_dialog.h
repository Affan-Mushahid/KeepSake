#pragma once

#include <QDialog>
#include "ui_item_select_dialog.h"
#include "../Header Files/user.h"
#include "../Header Files/data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class item_select_dialogClass; };
QT_END_NAMESPACE

class item_select_dialog : public QDialog
{
	Q_OBJECT


private:
	Ui::item_select_dialogClass* ui;
	User* user; // The user to add the item to once entered


signals:
	void item_created(); // Send signal back to manager window after entering item


public:
	item_select_dialog(User* u, QWidget *parent = nullptr);
	~item_select_dialog();


public slots:
	void on_password_btn_clicked();
	void on_credit_card_btn_clicked();
	void on_identity_card_btn_clicked();
	void on_note_btn_clicked();
	void on_cancel_btn_clicked();
	void on_p_enter_btn_clicked();
	void on_c_enter_btn_clicked();
	void on_i_enter_btn_clicked();
	void on_n_enter_btn_clicked();
	void on_generate_btn_clicked();
};
