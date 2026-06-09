/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CASCLABEL_H
#define CASCLABEL_H

#include <QLabel>

class CAscLabel: public QLabel
{
public:
    CAscLabel(QWidget * parent = 0);
    CAscLabel(const QString& caption, QWidget * parent = 0);

    virtual ~CAscLabel();

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // CASCLABEL_H
