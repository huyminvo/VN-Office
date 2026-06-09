/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CMAINPANELIMPL_H
#define CMAINPANELIMPL_H

#include "cmainpanel.h"
#include <QCoreApplication>

class CMainPanelImpl : public CMainPanel
{
    Q_DECLARE_TR_FUNCTIONS(CMainPanelImpl)

public:
    CMainPanelImpl(QWidget *, bool, double);

    void updateScaling(double) override;
    void applyTheme(const std::wstring&) override;

    void onLocalOptions(const QString&) override;
private:
    void refreshAboutVersion() override;
};

#endif // CMAINPANELIMPL_H
