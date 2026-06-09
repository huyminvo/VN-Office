/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef ICONFACTORY_H
#define ICONFACTORY_H

#include <QIcon>

#define SMALL_ICON 20

class IconFactory
{
public:
    enum IconIndex {
        CreateNew = 0,
        Browse = 65,
        Pin,
        Unpin
    };

    static QIcon icon(IconIndex icon, int pixelSize);
};

#endif // ICONFACTORY_H
