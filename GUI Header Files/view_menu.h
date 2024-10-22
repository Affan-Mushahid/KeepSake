#pragma once

#include <QMainWindow>
#include "ui_view_menu.h"
#include "../Header Files/data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class view_menuClass; };
QT_END_NAMESPACE

class view_menu : public QMainWindow
{
	Q_OBJECT


private:
	Ui::view_menuClass* ui;
	Data* m_item; // The data item to be viewed


public:
	view_menu(Data* item, QWidget *parent = nullptr);
	~view_menu();
};
