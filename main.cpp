#include "KeepSake.h"
#include <login_menu.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //KeepSake w;
    login_menu w;
    w.show();
    return a.exec();

    return 0;
}
