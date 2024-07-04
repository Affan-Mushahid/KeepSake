#pragma once

#include <QMainWindow>
#include "ui_edit_menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class edit_menuClass; };
QT_END_NAMESPACE

class edit_menu : public QMainWindow
{
	Q_OBJECT

public:
	edit_menu(QWidget *parent = nullptr);
	~edit_menu();

private:
	Ui::edit_menuClass *ui;
};
