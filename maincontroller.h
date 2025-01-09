#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QProcess>
#include "device.h"
#include "listview.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    void run();
    void addDevice(QList<Device> &devices);
    void deleteDevice(QList<Device> &devices);


signals:
    \
    void listViewSignal(QList<Device> devices);
private:
    QList<Device> devices;
    ListView *listView;
};

#endif // MAINCONTROLLER_H
