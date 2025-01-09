#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>
#include <QProcess>

class Device
{
public:

    Device(const QString &name, const QString &ipAddress, bool isUp);


    QString getName() const;
    QString getIpAddress() const;
    bool getIsUp() const;

    void setName(const QString &name);
    void setIpAddress(const QString &ipAddress);
    void setIsUp(bool isUp);

private:
    QString m_name;
    QString m_ipAddress;
    bool m_isUp;
};

#endif // DEVICE_H
