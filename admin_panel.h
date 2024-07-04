#pragma once

#include <QMainWindow>
#include "ui_admin_panel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class admin_panelClass; };
QT_END_NAMESPACE

class admin_panel : public QMainWindow
{
	Q_OBJECT

public:
	admin_panel(QWidget *parent = nullptr);
	~admin_panel();

private:
	Ui::admin_panelClass *ui;
};
