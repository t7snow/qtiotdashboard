#include "maincontroller.h"
#include <QTextStream>
MainController::MainController(QObject *parent)
    : QObject{parent}
{}

void MainController::run(){
    QTextStream out(stdout);
    QTextStream in(stdin);

    QString command;

    out << "Welcome Tucker! Enter 1. List IO Devices on current network. 2. Add IO Device 3. Delete IO Device" << Qt::endl;
    command = in.readLine();
    switch (command.toInt()) {
    case value:

        break;
    default:
        break;
    }
}
