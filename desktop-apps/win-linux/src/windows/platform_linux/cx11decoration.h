/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CX11DECORATION_H
#define CX11DECORATION_H

#include <QWidget>
#include <QMouseEvent>

#define FORCE_LINUX_CUSTOMWINDOW_MARGINS

namespace WindowHelper {
    auto check_button_state(Qt::MouseButton b) -> bool;
}

class CX11Decoration
{
public:
    CX11Decoration(QWidget *);
    virtual ~CX11Decoration();

    void setTitleWidget(QWidget *);
    void dispatchMouseDown(QMouseEvent *);
    void dispatchMouseMove(QMouseEvent *);
    void dispatchMouseUp(QMouseEvent *);
    void setCursorPos(int x, int y);

    void turnOn();
    void turnOff();
    bool isDecorated();
    void setMaximized(bool);
    void setMinimized();
    void raiseWindow();

    static int customWindowBorderWith();

    int m_nDirection;
protected:
    double dpi_ratio = 1;
    void onDpiChanged(double);
    bool isNativeFocus();

private:
    QWidget * m_window;
    QWidget * m_title;
    QTimer * m_motionTimer;
    ulong m_currentCursor;
    bool m_decoration;
    int m_nBorderSize;
    bool m_bIsMaximized;
    bool need_to_check_motion = false;
    QSize m_startSize;

    std::map<int, ulong> m_cursors;

    void createCursors();
    void freeCursors();
    int  hitTest(int x, int y) const;
    void checkCursor(QPoint & p);
    void switchDecoration(bool);
    void sendButtonRelease();
};

#endif // CX11DECORATION_H
