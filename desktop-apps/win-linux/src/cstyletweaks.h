/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CSTYLETWEAKS_H
#define CSTYLETWEAKS_H

#include <QProxyStyle>

class CStyleTweaks : public QProxyStyle
{
public:
    CStyleTweaks();

public:
    void drawPrimitive(PrimitiveElement, const QStyleOption *, QPainter *, const QWidget *widget = 0) const;
};

#endif // CSTYLETWEAKS_H
