/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CEVENTDRIVER_H
#define CEVENTDRIVER_H

#include <QObject>
#include <QWidget>

/*#ifdef Q_OS_WIN
#include <Windows.h>
using NativeHandle = HWND;
#else*/
#include <QWidget>
using NativeHandle = WId;
//#endif

class CInAppEventBase
{
public:
    enum class CEventType
    {
        etModal
        ,etEditorClosed
    };

    CInAppEventBase(CEventType t)
        : m_type(t)
    {}

    virtual ~CInAppEventBase(){}
    virtual CEventType type() const { return m_type; }

private:
    CEventType m_type;
};

class CInAppRunnigEvent : public CInAppEventBase
{
public:
    CInAppRunnigEvent(CEventType t) : CInAppEventBase(t) {}
    virtual ~CInAppRunnigEvent(){}

    bool finished() const { return m_finished; }
    void setFinished(bool f) { m_finished = f; }
private:
    bool m_finished = false;
};

class CInAppEventModal : public CInAppRunnigEvent
{
    NativeHandle m_handle;

public:
    CInAppEventModal(NativeHandle h)
        : CInAppRunnigEvent(CEventType::etModal)
        , m_handle(h)
    {}

    NativeHandle handle() const { return m_handle; }
    void setHandle(NativeHandle h) { m_handle = h; }
};

class CEventDriver : public QObject
{
    Q_OBJECT

public:
    explicit CEventDriver(QObject *parent = nullptr);

//    void signal(edEventType);
    void signal(CInAppEventBase *);
signals:
    void onModalDialog(bool status, NativeHandle handle);
    void onEditorClosed();

public slots:
};

class CRunningEventHelper
{
public:
    CRunningEventHelper(CInAppRunnigEvent *);
    ~CRunningEventHelper();

private:
    CInAppRunnigEvent * m_event;
};

#endif // CEVENTDRIVER_H
