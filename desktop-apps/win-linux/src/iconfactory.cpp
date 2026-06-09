/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "iconfactory.h"
#include "cascapplicationmanagerwrapper.h"
#include <QSvgRenderer>
#include <QPainter>

#define IMAGES 6
#define DEFAULT_SIZE 20
#define ADVANCED_OPACITY 0.8


QIcon IconFactory::icon(IconIndex icon, int pixelSize)
{
    const char* iconPath[IMAGES] = {
        ":/menu/icons/iconssmall_1x.png",
        ":/menu/icons/iconssmall_1.25x.png",
        ":/menu/icons/iconssmall_1.5x.png",
        ":/menu/icons/iconssmall_1.75x.png",
        ":/menu/icons/iconssmall_2x.png",
        ":/menu/icons/iconssmall_2.5x.svg"
    };

    int index = pixelSize == DEFAULT_SIZE ? 0 :
                pixelSize == 1.25 * DEFAULT_SIZE ? 1 :
                pixelSize == 1.5 * DEFAULT_SIZE ? 2 :
                pixelSize == 1.75 * DEFAULT_SIZE ? 3 :
                pixelSize == 2 * DEFAULT_SIZE ? 4 : IMAGES - 1;

    QPixmap pix(pixelSize, pixelSize);
    pix.fill(Qt::transparent);
    if (index < IMAGES - 1) {
        QPixmap image(iconPath[index]);
        // int iconsPerRow = pixmap.width() / pixelSize;
        // int iconsPerColumn = pixmap.height() / pixelSize;
        int x = AscAppManager::themes().current().isDark() ? pixelSize : 0;
        int y = static_cast<int>(icon) * pixelSize;
        QPainter p(&pix);
        p.setOpacity(ADVANCED_OPACITY);
        p.drawPixmap(0, 0, image.copy(x, y, pixelSize, pixelSize));
        p.end();

    } else {
        const QString node = icon == CreateNew ? "btn-add-text" :
                             icon == Browse ?    "btn-browse" :
                             icon == Pin ?       "btn-pin" :
                             icon == Unpin ?     "btn-unpin" : "";

        QString path(iconPath[index]);
        QSvgRenderer svg(path);
        QPainter p(&pix);
        p.setCompositionMode(QPainter::CompositionMode_SourceOver);
        QRectF bounds = svg.boundsOnElement(node);
        double kx = pixelSize / svg.viewBoxF().width();
        double ky = pixelSize / svg.viewBoxF().height();
        bounds = QRectF(bounds.x() * kx, bounds.y() * ky, bounds.width() * kx, bounds.height() * ky);
        svg.render(&p, node, bounds);
        p.setCompositionMode(QPainter::CompositionMode_SourceIn);
        p.fillRect(pix.rect(), AscAppManager::themes().current().isDark() ? QColor(255, 255, 255, 200) : QColor(0, 0, 0, 200));
        p.end();
    }
    return QIcon(pix);
}
