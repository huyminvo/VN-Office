/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CPRINTPROGRESS_H
#define CPRINTPROGRESS_H

#include <QWidget>


class CPrintProgress : public QObject
{
    Q_OBJECT
public:
    explicit CPrintProgress(QWidget *parent = nullptr);
    ~CPrintProgress();

    void startProgress();
    void setProgress(int, int);
    bool isRejected();

private:
    class CPrintProgressPrivate;
    CPrintProgressPrivate *pimpl;
};

#endif // CPRINTPROGRESS_H
