/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include <QPixmap>
#include <QSvgRenderer>
#include <QPainter>

auto getSplashImage(double ratio) -> QPixmap {
    QSvgRenderer _svg(QString(":/res/icons/splash-eo.svg"));

    QPixmap _image(_svg.defaultSize() * ratio);
    QPainter _painter(&_image);

    _svg.render(&_painter);

    return _image;
}
