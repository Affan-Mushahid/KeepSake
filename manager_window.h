#pragma once

#include <QMainWindow>
#include "ui_manager_window.h"
#include <pass_generator.h>
#include <encryption.h>
#include "user.h"
#include <single_item_widget.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class manager_windowClass; };
QT_END_NAMESPACE

class manager_window : public QMainWindow
{
	Q_OBJECT



public:
	manager_window(Password_Generator& P, Encryption& E, QWidget *parent = nullptr);
	~manager_window();

signals:
	void closing();

private:

	Ui::manager_windowClass *ui;

	std::vector<single_item_widget*> items;
	QListWidgetItem* items_1;

};
