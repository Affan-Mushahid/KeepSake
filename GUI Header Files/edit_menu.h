#pragma once

#include <QMainWindow>
#include "ui_edit_menu.h"
#include "../Header Files/data.h"
#include "../Header Files/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class edit_menuClass; };
QT_END_NAMESPACE

class edit_menu : public QMainWindow
{
	Q_OBJECT

signals:
	void item_edited();

public:
	edit_menu(User* u, Data* data_item, QWidget *parent = nullptr);
	~edit_menu();

public slots:
	void on_p_enter_btn_clicked();
	void on_c_enter_btn_clicked();
	void on_i_enter_btn_clicked();
	void on_n_enter_btn_clicked();
	void on_generate_btn_clicked();

private:
	Ui::edit_menuClass *ui;

	Data* m_data_item;

	User* user;
};
