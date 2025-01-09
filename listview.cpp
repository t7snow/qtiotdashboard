#include "listview.h"
#include <iostream>
#include <iomanip>
#include <QTextStream>

ListView::ListView(QObject *parent)
    : QObject{parent}
{}

void ListView::listView(QList<Device> devices) {
    QTextStream out(stdout);
    QTextStream in(stdin);

    out << "Device List\n";
    out << "----------------------------------------\n";
    std::cout << std::left << std::setw(20) << "Name"
              << std::setw(20) << "IP Address"
              << "Status\n";
    out << "----------------------------------------\n";

    for (const Device &device : devices) {
        std::cout << std::left << std::setw(20) << device.getName().toStdString()
        << std::setw(20) << device.getIpAddress().toStdString();
        if (device.getIsUp()) {
            std::cout << "\033[42;1m UP \033[0m";
        } else {
            std::cout << "\033[41;1m DOWN \033[0m";
        }
        std::cout << "\n";
    }
}



