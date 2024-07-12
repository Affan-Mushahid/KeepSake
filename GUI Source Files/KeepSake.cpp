#include "../GUI Header Files/KeepSake.h"

KeepSake::KeepSake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KeepSakeClass())
{
    ui->setupUi(this);
}

KeepSake::~KeepSake()
{
    delete ui;
}

