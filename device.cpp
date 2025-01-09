#include "device.h"

Device::Device(const QString &name, const QString &ipAddress, bool isUp)
    : m_name(name), m_ipAddress(ipAddress), m_isUp(isUp) {}

QString Device::getName() const {
    return m_name;
}

void Device::setName(const QString &name) {
    if (m_name != name) {
        m_name = name;

    }
}

QString Device::getIpAddress() const {
    return m_ipAddress;
}

void Device::setIpAddress(const QString &ipAddress) {
    if (m_ipAddress != ipAddress) {
        m_ipAddress = ipAddress;

    }
}

bool Device::getIsUp() const {
    QProcess process;
    QString command;
    QStringList arguments;

#ifdef Q_OS_WIN
    command = "ping";
    arguments << "-n" << "1" << m_ipAddress;
#elif defined(Q_OS_MAC) || defined(Q_OS_UNIX)
    command = "ping";
    arguments << "-c" << "1" << m_ipAddress;
#else
    return false;
#endif

    process.start(command, arguments);
    process.waitForFinished();
    QString output = process.readAllStandardOutput();

    if (output.contains("bytes from")) {
        return true;
    } else {
        return false;
    }
}



void Device::setIsUp(bool isUp) {
    if (m_isUp != isUp) {
        m_isUp = isUp;

    }
}
