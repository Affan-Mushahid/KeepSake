#include "KeepSake.h"
#include <login_menu.h>
#include <manager_window.h>
#include <pass_generator.h>
#include <encryption.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Password_Generator p;
    Encryption e;
    //login_menu w(p, e);
    //w.show();

    manager_window w(p, e);
    return a.exec();

    return 0;
}
