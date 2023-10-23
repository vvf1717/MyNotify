#include "notifyiface.h"

NotifyIface::NotifyIface(QObject *parent) : QObject(parent)
{
    m_iface = new QDBusInterface("org.freedesktop.Notifications", "/org/freedesktop/Notifications", "org.freedesktop.Notifications", QDBusConnection::sessionBus(), this);
    if (!m_iface->isValid()) {
        return;
    }
}

void NotifyIface::showNotify(QString strNotify)
{
    QString title = "MyNotify new message";
    QVariantList args;
    args << QString("MyNotify");
    args << QVariant(QVariant::UInt);
    args << QVariant("image://theme/icon-m-about");
    args << QString(title);
    args << QString(strNotify);
    args << QStringList();
    args << QVariantMap();
    args << 5000;

    m_iface->callWithArgumentList(QDBus::AutoDetect, "Notify", args);
}
