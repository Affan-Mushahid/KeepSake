#pragma once

#include <QWidget>
#include "ui_category_item_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class category_item_widgetClass; };
QT_END_NAMESPACE

class category_item_widget : public QWidget
{
	Q_OBJECT

public:
	category_item_widget(std::string category, QWidget *parent = nullptr);
	~category_item_widget();

private:
	Ui::category_item_widgetClass *ui;
};
