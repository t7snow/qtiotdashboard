#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QObject>
#include "device.h"

class ListView : public QObject
{
    Q_OBJECT
public:
    explicit ListView(QObject *parent = nullptr);

public slots:
    void listView(QList<Device> devices);
};

#endif // LISTVIEW_H
