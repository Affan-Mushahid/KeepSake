#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KeepSake.h"

QT_BEGIN_NAMESPACE
namespace Ui { class KeepSakeClass; };
QT_END_NAMESPACE

class KeepSake : public QMainWindow
{
    Q_OBJECT


private:
    Ui::KeepSakeClass* ui;


public:
    KeepSake(QWidget *parent = nullptr);
    ~KeepSake();
};
