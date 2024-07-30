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


private:
	Ui::admin_panelClass* ui; // Manages UI
	AdministratorUser* m_user; // User opening the admin panel


public:
	admin_panel(User* user, QWidget *parent = nullptr);
	~admin_panel();


public slots:
	void on_change_btn_clicked();
};
