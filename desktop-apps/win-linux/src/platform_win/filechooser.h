/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef WINFILECHOOSER_H
#define WINFILECHOOSER_H

#include <QWidget>
#include <QString>


namespace Win
{
typedef enum {
    OPEN = 0, SAVE = 1, FOLDER = 2
} Mode;

QStringList openWinFileChooser(QWidget *parent,
                               Mode mode,
                               const QString &title,
                               const QString &file,
                               const QString &path,
                               const QString &filter,
                               QString *sel_filter,
                               bool sel_multiple = false);
}

#endif // WINFILECHOOSER_H
