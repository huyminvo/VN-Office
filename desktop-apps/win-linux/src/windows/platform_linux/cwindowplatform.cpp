/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "windows/platform_linux/cwindowplatform.h"
#include "cascapplicationmanagerwrapper.h"
#include "defines.h"
#include "utils.h"
#include <QTimer>
#include <QPainter>
#include <QPainterPath>
#include <QX11Info>
#include <xcb/xcb.h>

#ifdef DOCUMENTSCORE_OPENSSL_SUPPORT
# include "platform_linux/cdialogopenssl.h"
#endif
#define WINDOW_CORNER_RADIUS 6


CWindowPlatform::CWindowPlatform(const QRect &rect) :
    CWindowBase(rect),
    CX11Decoration(this)
{
    if (AscAppManager::isRtlEnabled())
        setLayoutDirection(Qt::RightToLeft);
    if (isCustomWindowStyle()) {
        if (QX11Info::isCompositingManagerRunning())
            setAttribute(Qt::WA_TranslucentBackground);
        CX11Decoration::turnOff();
    }
    setIsCustomWindowStyle(!CX11Decoration::isDecorated());
    setFocusPolicy(Qt::StrongFocus);
    setProperty("stabilized", true);
    m_propertyTimer = new QTimer(this);
    m_propertyTimer->setSingleShot(true);
    m_propertyTimer->setInterval(100);
    connect(m_propertyTimer, &QTimer::timeout, this, [=]() {
        setProperty("stabilized", true);
    });
}

CWindowPlatform::~CWindowPlatform()
{

}

/** Public **/

void CWindowPlatform::bringToTop()
{
    if (isMinimized()) {
        windowState() == (Qt::WindowMinimized | Qt::WindowMaximized) ?
                    showMaximized() : showNormal();
    }
    CX11Decoration::raiseWindow();
}

void CWindowPlatform::show(bool maximized)
{
    QMainWindow::show();
    if (maximized) {
        QMainWindow::setWindowState(Qt::WindowMaximized);
    }
}

void CWindowPlatform::setWindowColors(const QColor& background, const QColor& border, bool isActive)
{
    Q_UNUSED(border)
    if (!CX11Decoration::isDecorated()) {
        m_brdColor = border;
        setStyleSheet(QString("QMainWindow{border:1px solid %1; background-color: %2;}").arg(border.name(), background.name()));
    }
}

void CWindowPlatform::adjustGeometry()
{
    int border = (CX11Decoration::isDecorated() || isMaximized()) ? 0 : qRound(CX11Decoration::customWindowBorderWith() * m_dpiRatio);
    setContentsMargins(border, border, border, border);
}

/** Protected **/

void CWindowPlatform::onWindowActivate(bool is_active)
{
    for (auto *btn : m_pTopButtons) {
        if (btn)
            btn->setFaded(!is_active);
    }
}

void CWindowPlatform::onMinimizeEvent()
{
    CX11Decoration::setMinimized();
}

bool CWindowPlatform::event(QEvent * event)
{
    if (event->type() == QEvent::WindowStateChange) {
        CX11Decoration::setMaximized(isMaximized());
        applyWindowState();
        adjustGeometry();
    } else
    if (event->type() == QEvent::HoverLeave) {
        if (m_boxTitleBtns)
            m_boxTitleBtns->setCursor(QCursor(Qt::ArrowCursor));
    } else
    if (event->type() == QEvent::LayoutDirectionChange) {
        if (m_pMainPanel) {
            m_pMainPanel->setProperty("rtl", AscAppManager::isRtlEnabled());
            onLayoutDirectionChanged();
        }
    } else
    if (event->type() == QEvent::WindowActivate) {
        onWindowActivate(true);
    }
    else
    if (event->type() == QEvent::WindowDeactivate) {
        onWindowActivate(false);
    }
    return CWindowBase::event(event);
}

bool CWindowPlatform::nativeEvent(const QByteArray &ev_type, void *msg, long *res)
{
    if (ev_type == "xcb_generic_event_t") {
        xcb_generic_event_t *ev = static_cast<xcb_generic_event_t*>(msg);
        switch (ev->response_type & ~0x80) {
        case XCB_FOCUS_IN:
            if (isNativeFocus()) {
                focus();
                m_propertyTimer->stop();
                if (property("stabilized").toBool())
                    setProperty("stabilized", false);
                m_propertyTimer->start();
            }
            break;
        default:
            break;
        }
    }
    return CWindowBase::nativeEvent(ev_type, msg, res);
}

void CWindowPlatform::setScreenScalingFactor(double factor, bool resize)
{
    CX11Decoration::onDpiChanged(factor);
    CWindowBase::setScreenScalingFactor(factor, resize);
}

void CWindowPlatform::paintEvent(QPaintEvent *event)
{
    if (!QX11Info::isCompositingManagerRunning()) {
        CWindowBase::paintEvent(event);
        return;
    }

    QPainter pnt(this);
    pnt.setRenderHint(QPainter::Antialiasing);
    int d = 2 * WINDOW_CORNER_RADIUS * m_dpiRatio;
    QPainterPath path;
    path.moveTo(width(), d/2);
    path.arcTo(width() - d, 0, d, d, 0, 90);
    path.lineTo(d/2, 0);
    path.arcTo(0, 0, d, d, 90, 90);
    path.lineTo(0, height());
    path.lineTo(width(), height());
    path.lineTo(width(), d/2);
    path.closeSubpath();
    pnt.fillPath(path, palette().window().color());
    pnt.strokePath(path, QPen(m_brdColor, 1));
    pnt.end();
}

/** Private **/

void CWindowPlatform::mouseMoveEvent(QMouseEvent *e)
{
    if (!property("blocked").toBool())
        CX11Decoration::dispatchMouseMove(e);
}

void CWindowPlatform::mousePressEvent(QMouseEvent *e)
{
    CX11Decoration::dispatchMouseDown(e);
}

void CWindowPlatform::mouseReleaseEvent(QMouseEvent *e)
{
    CX11Decoration::dispatchMouseUp(e);
}

void CWindowPlatform::mouseDoubleClickEvent(QMouseEvent *me)
{
    if (m_boxTitleBtns) {
        if (m_boxTitleBtns->geometry().contains(me->pos()))
            onMaximizeEvent();
    }
}
