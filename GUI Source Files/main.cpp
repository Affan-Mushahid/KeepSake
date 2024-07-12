#include "../GUI Header Files/KeepSake.h"
#include "../GUI Header Files/login_menu.h"
#include "../GUI Header Files/manager_window.h"
#include "../Header Files/pass_generator.h"
#include "../Header Files/encryption.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Password_Generator p;
    Encryption e;

    manager_window w(p, e);
    return a.exec();

    return 0;
}
