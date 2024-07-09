#include <QApplication>
#include "login.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
    }
}
