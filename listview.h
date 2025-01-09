#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QObject>
#include "device.h"

class ListView : public QObject
{
    Q_OBJECT
public:
    explicit ListView(QObject *parent = nullptr);
    int isUp(Device &device);
    void listView();


signals:
};

#endif // LISTVIEW_H
