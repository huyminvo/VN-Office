/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CMAINWINDOWIMPL_H
#define CMAINWINDOWIMPL_H

#include <QCoreApplication>
#include "windows/cmainwindow.h"

#define MAIN_ICON_SIZE QSize(85,20)
#define MAIN_ICON_PATH QString(":/logo.svg")

class CMainWindowImpl : public CMainWindow
{
    Q_DECLARE_TR_FUNCTIONS(CMainWindowImpl)
public:
    CMainWindowImpl(const QRect &rect);
    void doOpenLocalFile(COpenOptions&);

public slots:
    void onLocalOptions(const QString&);
    void onLocalFileSaveAs(void *);

private:
    virtual QString getSaveMessage() const final;
    virtual void refreshAboutVersion() final;
};

#endif // CMAINWINDOWIMPL_H
