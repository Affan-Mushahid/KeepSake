#pragma once

#include <QDialog>
#include "ui_login_menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login_menuClass; };
QT_END_NAMESPACE

class login_menu : public QDialog
{
	Q_OBJECT

public:
	login_menu(QWidget *parent = nullptr);
	~login_menu();

private:
	Ui::login_menuClass *ui;
	
	void test();
};
