/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CTABSTYLE_H
#define CTABSTYLE_H

#include <QProxyStyle>
#include <QStyleOption>

//class CTabStylePrivate;

class CTabStyle : public QProxyStyle
{
    Q_OBJECT

public:
    explicit CTabStyle();
    virtual ~CTabStyle();

    void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *widget) const;
    QRect subElementRect(SubElement element, const QStyleOption *option, const QWidget *widget) const;

private:
    void tabLayout(const QStyleOptionTabV3 *opt, const QWidget *widget, QRect *textRect, QRect *iconRect) const;
};

#endif // CTABSTYLE_H
