/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CPRESENTERWINDOW_H
#define CPRESENTERWINDOW_H

#ifdef _WIN32
# include "windows/platform_win/cwindowplatform.h"
#else
# include "windows/platform_linux/cwindowplatform.h"
#endif
#include "qcefview.h"


class CPresenterWindow : public CWindowPlatform
{
public:
    explicit CPresenterWindow(const QRect&, const QString&, QCefView*);
    virtual ~CPresenterWindow();

    virtual void applyTheme(const std::wstring&) final;
    virtual bool holdView(int id) const final;

protected:
    void closeEvent(QCloseEvent *) final;
    virtual void onLayoutDirectionChanged() final;

private:
    QWidget * createMainPanel(QWidget *, const QString&, QWidget * view = nullptr);
    virtual void setScreenScalingFactor(double, bool resize = true) final;
    virtual void onCloseEvent() final;
    virtual void focus() final;
};

#endif // CPRESENTERWINDOW_H
