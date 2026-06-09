/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef SINGLE_APPLICATION_H
#define SINGLE_APPLICATION_H

#include <QApplication>
#include <QByteArray>
#pragma push_macro("signals")
#undef signals
#include <gio/gio.h>
#pragma pop_macro("signals")


class CSocket;
class SingleApplication : public QApplication
{
    Q_OBJECT
public:
    explicit SingleApplication( int &argc, char *argv[]);
    ~SingleApplication();

    bool isPrimary();
    bool sendMessage(const QByteArray&);

signals:
    void receivedMessage(QByteArray message);

private slots:
    void invokeSignal(const QString&);

private:
    CSocket *m_socket = nullptr;
    GDBusConnection *m_conn = nullptr;
    std::string m_client_id;
    uint    m_subscrId = 0;
    bool    m_isPrimary = false;
};

#endif // SINGLE_APPLICATION_H
