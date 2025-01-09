#include "maincontroller.h"
#include <QTextStream>
MainController::MainController(QObject *parent)
    : QObject{parent}
{}

void MainController::run(){
    QTextStream out(stdout);
    QTextStream in(stdin);

    QString command;
    QList<Device> devices;

    out << "Welcome Tucker! Enter 1. List IO Devices on current network. 2. Add IO Device 3. Delete IO Device" << Qt::endl;
    command = in.readLine();
    switch (command.toInt()) {
    case 1:
        emit listDevices(devices);
        break;
    case 2:
        addDevice(devices);
        break;
    case 3:
        deleteDevice(devices);
    default:
        break;
    }
}

void MainController::addDevice(){

}

void MainController::deleteDevice(){

}

int MainController::isUp(Device &device){
#ifdef Q_OS_WIN
    int exitCode = QProcess::execute("ping", QStringList() << "-n" << "1" << device.hostName);
#elif defined(Q_OS_MAC) || defined(Q_OS_UNIX)
    int exitCode = QProcess::execute("ping", QStringList() << "-c" << "1" << device.hostName);
#endif
    if(exitCode){
        return -1;
    }else{
        return 1;
    }
}
