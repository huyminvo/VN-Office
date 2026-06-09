/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CWINDOWPLATFORM_H
#define CWINDOWPLATFORM_H

#include "windows/cwindowbase.h"
#include <QtWidgets/QApplication>
#include <qtcomp/qnativeevent.h>

struct FRAME {
    FRAME() : left(0), top(0)
    {}
    FRAME(FRAME &frame) {
        left = frame.left;
        top = frame.top;
    }
    int left, top;
};

class CWindowPlatform : public CWindowBase
{
public:
    explicit CWindowPlatform(const QRect&);
    virtual ~CWindowPlatform();

//    void toggleBorderless(bool);
//    void toggleResizeable();
    void bringToTop();
    virtual void show(bool);
    virtual void setWindowColors(const QColor&, const QColor& border = QColor(), bool isActive = false) final;
    virtual void adjustGeometry() final;

protected:
    bool isSessionInProgress();
    void onWindowActivate(bool is_active);
    virtual bool event(QEvent *event) override;
    virtual void onLayoutDirectionChanged() = 0;
#ifdef __OS_WIN_XP
    virtual void resizeEvent(QResizeEvent *ev) override;
#endif

private:
    virtual void changeEvent(QEvent*) final;
    virtual bool nativeEvent(const QByteArray&, void*, long_ptr*) final;

    QTimer *m_propertyTimer;
    double m_dpi;
    HWND m_hWnd;
    int  m_resAreaWidth;
    FRAME m_frame;
    bool m_borderless,
         m_closed,
         m_isResizeable,
//         m_allowMaximize,
         m_isMaximized = false,
         m_isThemeActive = true,
         m_isTaskbarAutoHideOn = false,
         m_scaleChanged = false,
         m_isSessionInProgress = true;
};

#endif // CWINDOWPLATFORM_H
