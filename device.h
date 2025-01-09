#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>

class Device : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setname NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString ipAddress READ getIpAddress WRITE setIpAddress NOTIFY ipAddressChanged FINAL);
    Q_PROPERTY(bool isUp READ getIsUp WRITE setIsUp NOTIFY statusChanged)

public:
    explicit Device(QObject *parent = nullptr);
    Device(const QString &name, const QString &ipAddress, bool isUp, QObject *parent = nullptr);

    QString getName() const;
    QString getIpAddress() const;
    bool getIsUp() const;

    void setName(const QString &name);
    void setIpAddress(const QString &ipAddress);
    void setIsUp(bool isUp);

signals:
    void nameChanged(const QString &name);
    void ipAddressChanged(const QString &ipAddress);
    void statusChanged(bool isUp);

private:
    QString m_name;
    QString m_ipAddress;
    bool m_isUp;
};

#endif // DEVICE_H
