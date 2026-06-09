/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "cstyletweaks.h"

CStyleTweaks::CStyleTweaks() : QProxyStyle()
{
}

void CStyleTweaks::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    /* do not draw focus rectangles - this permits modern styling */
    if (element == QStyle::PE_FrameFocusRect)
        return;

    QProxyStyle::drawPrimitive(element, option, painter, widget);
}
