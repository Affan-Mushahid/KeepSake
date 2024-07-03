#pragma once

#include <QDialog>
#include "ui_confirm_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class confirm_dialogClass; };
QT_END_NAMESPACE

class confirm_dialog : public QDialog
{
	Q_OBJECT

public:
	confirm_dialog(QWidget *parent = nullptr);
	~confirm_dialog();

private:
	Ui::confirm_dialogClass *ui;
};
