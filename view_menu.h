#pragma once

#include <QMainWindow>
#include "ui_view_menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class view_menuClass; };
QT_END_NAMESPACE

class view_menu : public QMainWindow
{
	Q_OBJECT

public:
	view_menu(QWidget *parent = nullptr);
	~view_menu();

private:
	Ui::view_menuClass *ui;
};
