/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/


#include "../utils.cpp"

QString Utils::getUserPath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
}

QString Utils::getAppCommonPath()
{
    return getUserPath() + APP_DATA_PATH;
}

QIcon Utils::appIcon()
{
    return QIcon(":/app.ico");
}

