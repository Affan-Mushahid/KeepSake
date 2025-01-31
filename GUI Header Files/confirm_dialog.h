#pragma once

#include <QDialog>
#include "ui_confirm_dialog.h"
#include "../Header Files/data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class confirm_dialogClass; };
QT_END_NAMESPACE

class confirm_dialog : public QDialog
{
	Q_OBJECT


private:
	Ui::confirm_dialogClass* ui; // Manages the UI
	Data* m_item; // The item to delete when confirmed


signals:
	void delete_item_true(Data* item);


public:
	confirm_dialog(Data* item, QWidget *parent = nullptr);
	~confirm_dialog();


public slots:
	void on_yes_btn_clicked();
};
