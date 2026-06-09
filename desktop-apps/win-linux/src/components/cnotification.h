/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CNOTIFICATION_H
#define CNOTIFICATION_H

#include "components/cmessage.h"
#include <functional>

#define mbNone  MsgBtns(-1)
#define NOTIF_FAILED    -2
//#define NOTIF_DISMISSED -3


typedef std::function<void(int)> FnVoidInt;

class CNotification {
public:
    CNotification(const CNotification&) = delete;
    CNotification& operator=(const CNotification&) = delete;
    static CNotification& instance();
    bool init();
    bool show(const QString &msg, const QString &content, MsgBtns dlgBtns = mbNone, const FnVoidInt &callback = nullptr);
    void clear();

private:
    CNotification();
    ~CNotification();

    class CNotificationPrivate;
    CNotificationPrivate *pimpl = nullptr;
};

#endif // CNOTIFICATION_H
