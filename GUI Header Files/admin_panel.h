#pragma once

#include <QMainWindow>
#include "ui_admin_panel.h"
#include "../Header Files/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class admin_panelClass; };
QT_END_NAMESPACE

class admin_panel : public QMainWindow
{
	Q_OBJECT

public:
	admin_panel(User* user, QWidget *parent = nullptr);
	~admin_panel();

public slots:
	void on_change_btn_clicked();

private:
	Ui::admin_panelClass *ui;
	AdministratorUser* m_user;
};
