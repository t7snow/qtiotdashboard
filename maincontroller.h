#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QProcess>
#include "device.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    void run();
    void addDevice(QList<Device> devices);
    void deleteDevice(QList<Device> devices);
    int isUp(Device &device);

signals:
    void listDevices(QList<Device> devices);
private:
    QList<Device> devices;
};

#endif // MAINCONTROLLER_H
