#pragma once

#include <QMainWindow>
#include "ui_settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class settingsClass; };
QT_END_NAMESPACE

class settings : public QMainWindow
{
	Q_OBJECT

public:
	settings(QWidget *parent = nullptr);
	~settings();

private:
	Ui::settingsClass *ui;
};
