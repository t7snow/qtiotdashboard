#include "maincontroller.h"
#include <QTextStream>

MainController::MainController(QObject *parent)
    : QObject{parent}
{
    listView = new ListView(this);

    connect(this, &MainController::listViewSignal, listView, &ListView::listView);
}

void MainController::run(){
    QTextStream out(stdout);
    QTextStream in(stdin);

    QString command;
    QList<Device> devices;
    while(1){
        out << "Welcome Tucker! "
               << "Enter 1. List IO Devices on current network."
               << "2. Add IO Device"
               << "3. Delete IO Device"
                << Qt::endl;
        command = in.readLine();
        switch (command.toInt()) {
        case 1:
            emit listViewSignal(devices);
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
}

void MainController::addDevice(QList<Device> &devices){
    QTextStream out(stdout);
    QTextStream in(stdin);

    out << "Enter device name: " << Qt::endl;
    QString name = in.readLine();

    out << "Enter IP address: " << Qt::endl;
    QString ipAddress = in.readLine();

    out << "Enter status (1 for Up, 0 for Down): " << Qt::endl;
    bool isUp = (in.readLine().toInt() == 1);

    for (const Device &existingDevice : devices) {
        if (existingDevice.getName() == name) {
            out << "Device with the same name already exists." << Qt::endl;
            return;
        }
    }

    devices.append(Device(name, ipAddress, isUp));
    out << "Device added successfully." << Qt::endl;
}

void MainController::deleteDevice(QList<Device> &devices){
    QTextStream out(stdout);
    QTextStream in(stdin);

    out << "Enter the name of the device to delete: " << Qt::endl;
    QString name = in.readLine();

    for (int i = 0; i < devices.size(); ++i) {
        if (devices[i].getName() == name) {
            devices.removeAt(i);
            out << "Device deleted successfully." << Qt::endl;
            return;
        }
    }

    out << "Device not found." << Qt::endl;
}

