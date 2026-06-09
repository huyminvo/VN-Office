/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef SINGLEAPPLICATION_H
#define SINGLEAPPLICATION_H

#include <QApplication>
#include <QByteArray>
#include <Windows.h>


class SingleApplication : public QApplication
{
    Q_OBJECT
public:
    explicit SingleApplication(int &argc, char *argv[]);
    ~SingleApplication();

    bool isPrimary() const;
    bool sendMessage(const QByteArray &message);

signals:
    void receivedMessage(QByteArray message);

private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    void startPrimary();

    HANDLE      m_hMutex = nullptr;
    HWND        m_hWnd = nullptr;
    bool        m_isPrimary;

private slots:
    void invokeSignal(const QString&);
};

#endif // SINGLEAPPLICATION_H
