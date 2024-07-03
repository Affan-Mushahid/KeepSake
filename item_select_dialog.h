#pragma once

#include <QDialog>
#include "ui_item_select_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class item_select_dialogClass; };
QT_END_NAMESPACE

class item_select_dialog : public QDialog
{
	Q_OBJECT

public:
	item_select_dialog(QWidget *parent = nullptr);
	~item_select_dialog();

private:
	Ui::item_select_dialogClass *ui;
};
