#include "KeepSake.h"
#include <login_menu.h>
#include <pass_generator.h>
#include <encryption.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Password_Generator p;
    Encryption e;
    e.create_crypt();
    //KeepSake w;
    login_menu w(p, e);
    w.show();
    return a.exec();

    return 0;
}
