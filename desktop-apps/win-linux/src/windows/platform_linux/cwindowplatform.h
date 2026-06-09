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
#include "cx11decoration.h"


class CWindowPlatform : public CWindowBase, public CX11Decoration
{
public:
    explicit CWindowPlatform(const QRect&);
    virtual ~CWindowPlatform();

    void bringToTop();
    void show(bool);
    virtual void setWindowColors(const QColor&, const QColor& border = QColor(), bool isActive = false) final;
    virtual void adjustGeometry() final;

protected:
    void onWindowActivate(bool is_active);
    virtual void onMinimizeEvent() override;
    virtual bool event(QEvent *event) override;
    virtual bool nativeEvent(const QByteArray&, void*, long*) final;
    virtual void setScreenScalingFactor(double, bool resize = true) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void onLayoutDirectionChanged() = 0;

private:
    virtual void mouseMoveEvent(QMouseEvent *) final;
    virtual void mousePressEvent(QMouseEvent *) final;
    virtual void mouseReleaseEvent(QMouseEvent *) final;
    virtual void mouseDoubleClickEvent(QMouseEvent *) final;
    QTimer *m_propertyTimer;
};

#endif // CWINDOWPLATFORM_H
