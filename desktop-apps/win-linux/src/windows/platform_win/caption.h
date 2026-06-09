/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CAPTION_H
#define CAPTION_H

#include <QWidget>
#include <QWindow>
#include <Windows.h>
#include <Windowsx.h>
#include <QStyle>
#include <QPushButton>
#include <QCoreApplication>
#include "utils.h"

#include <qtcomp/qnativeevent.h>

#define RESIZE_AREA_PART 0.14


class Caption: public QWidget
{
public:
    Caption(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags()):
        QWidget(parent, f)
    {
        hwnd_root = ::GetAncestor((HWND)winId(), GA_ROOT);
        snapLayoutAllowed = isArrangingAllowed();
    }

private:
    HWND hwnd_root;
    bool snapLayoutAllowed = false;

    bool isArrangingAllowed() {
        BOOL arranging = FALSE;
        SystemParametersInfoA(SPI_GETWINARRANGING, 0, &arranging, 0);
        return (arranging == TRUE);
    }

    bool isResizingAvailable() {
        return Utils::getWinVersion() >= Utils::WinVer::Win10 && !IsZoomed(hwnd_root);
    }

    bool isPointInResizeArea(int posY) {
        return posY <= RESIZE_AREA_PART * height();
    }

    QPoint cursorPos() {
        POINT pt;
        ::GetCursorPos(&pt);
        return mapFromGlobal(QPoint(pt.x, pt.y));
    }

    QPushButton* buttonAtPos(const QPoint &pos) {
        QWidget *child = childAt(pos);
        return child ? qobject_cast<QPushButton*>(child) : nullptr;
    }

    QPushButton* buttonMaxUnderMouse() {
        QPushButton *btn = buttonAtPos(cursorPos());
        return (btn && btn->objectName() == "toolButtonMaximize") ? btn : nullptr;
    }

    bool postMsg(DWORD cmd) {
        POINT pt;
        ::GetCursorPos(&pt);
        QPoint pos = mapFromGlobal(QPoint(int(pt.x), int(pt.y)));
        if (!buttonAtPos(pos)) {
            ::ReleaseCapture();
            ::PostMessage(hwnd_root, cmd, isResizingAvailable() && isPointInResizeArea(pos.y()) ? HTTOP : HTCAPTION, POINTTOPOINTS(pt));
#ifndef QT_VERSION_6
            // TODO: crash on mouse down
            QCoreApplication::postEvent(parent(), new QEvent(QEvent::MouseButtonPress));
#endif
            return true;
        }
        return false;
    }

    virtual bool nativeEvent(const QByteArray &eventType, void *message, long_ptr *result) override
    {
    #if (QT_VERSION == QT_VERSION_CHECK(5, 11, 1))
        MSG* msg = *reinterpret_cast<MSG**>(message);
    #else
        MSG* msg = reinterpret_cast<MSG*>(message);
    #endif

        switch (msg->message)
        {
        case WM_LBUTTONDOWN: {
            if (postMsg(WM_NCLBUTTONDOWN))
                return true;
            break;
        }
        case WM_LBUTTONDBLCLK: {
            if (postMsg(WM_NCLBUTTONDBLCLK))
                return true;
            break;
        }
        case WM_MOUSEMOVE: {
            if (isResizingAvailable()) {
                int y = GET_Y_LPARAM(msg->lParam);
                setCursor(!buttonAtPos(QPoint(GET_X_LPARAM(msg->lParam), y)) && isPointInResizeArea(y) ? Qt::SizeVerCursor : Qt::ArrowCursor);
            }
            break;
        }
        case WM_NCLBUTTONDOWN: {
            if (Utils::getWinVersion() < Utils::WinVer::Win11)
                break;
            if (QPushButton *btn = buttonMaxUnderMouse()) {
                btn->setProperty("hovered", false);
                btn->setProperty("pressed", true);
                btn->style()->polish(btn);
                btn->repaint();
            }
            break;
        }
        case WM_TIMER: {
            QPushButton *btn = buttonMaxUnderMouse();
            if (!btn) {
                KillTimer(msg->hwnd, msg->wParam);
                if (QPushButton *btn = findChild<QPushButton*>("toolButtonMaximize")) {
                    btn->setProperty("hovered", false);
                    btn->setProperty("pressed", false);
                    btn->style()->polish(btn);
                }
            }
            break;
        }
        case WM_NCHITTEST: {
            if (Utils::getWinVersion() < Utils::WinVer::Win11 || !snapLayoutAllowed)
                break;
            *result = 0;
            if (QPushButton *btn = buttonMaxUnderMouse()) {
                if (!btn->property("hovered").toBool()) {
                    btn->setProperty("hovered", true);
                    btn->style()->polish(btn);
                    SetTimer(msg->hwnd, 1, 200, NULL);
                }
                *result = HTMAXBUTTON;
            }
            return (*result != 0);
        }
        case WM_CAPTURECHANGED: {
            if (Utils::getWinVersion() < Utils::WinVer::Win11)
                break;
            if (QPushButton *btn = buttonMaxUnderMouse())
                btn->click();
            break;
        }
        case WM_SETTINGCHANGE: {
            snapLayoutAllowed = isArrangingAllowed();
            break;
        }
        default:
            break;
        }
        return QWidget::nativeEvent(eventType, message, result);
    }
};

#endif
