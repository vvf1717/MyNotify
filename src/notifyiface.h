#ifndef NOTIFYIFACE_H
#define NOTIFYIFACE_H

#include <QObject>
#include <QtCore/QSharedPointer>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusConnectionInterface>
#include <QtDBus/QDBusReply>

class NotifyIface : public QObject
{
    Q_OBJECT
public:
    explicit NotifyIface(QObject *parent = nullptr);

    Q_INVOKABLE void showNotify(QString strNotify);

private:

 QDBusInterface *m_iface { nullptr };

};

#endif // NOTIFYIFACE_H
