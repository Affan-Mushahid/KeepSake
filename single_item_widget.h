#pragma once

#include <QWidget>
#include "ui_single_item_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class single_item_widgetClass; };
QT_END_NAMESPACE

class single_item_widget : public QWidget
{
	Q_OBJECT

public:
	single_item_widget(QWidget *parent = nullptr);
	~single_item_widget();

private:
	Ui::single_item_widgetClass *ui;
};
