#include <QCoreApplication>
#include "maincontroller.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainController mc;
    mc.run();

    return a.exec();
}
