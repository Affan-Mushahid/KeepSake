#pragma once

#include <QMainWindow>
#include "ui_manager_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class manager_windowClass; };
QT_END_NAMESPACE

class manager_window : public QMainWindow
{
	Q_OBJECT

public:
	manager_window(QWidget *parent = nullptr);
	~manager_window();

private:
	Ui::manager_windowClass *ui;
};
