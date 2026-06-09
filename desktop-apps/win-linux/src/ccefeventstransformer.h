/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CCEFEVENTTRANSFORMER_H
#define CCEFEVENTTRANSFORMER_H

#include <QObject>
#include "applicationmanager_events.h"

class CCefEventsTransformer : public NSEditorApi::CAscCefMenuEventListener
{

public:
    explicit CCefEventsTransformer(QObject *parent = 0);

protected:
    virtual void OnEvent(NSEditorApi::CAscCefMenuEvent *);
    virtual void OnEvent(QObject *, NSEditorApi::CAscCefMenuEvent *);

signals:
private:
    QObject * pObjTarget;

public slots:
};

#endif // CCEFEVENTTRANSFORMER_H
