#include "KeepSake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeepSake w;
    w.show();
    return a.exec();
}
