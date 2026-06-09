/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CFULLSCRWIDGET_H
#define CFULLSCRWIDGET_H

#include <QWidget>
#include <QCloseEvent>


class CFullScrWidget: public QWidget
{
    Q_OBJECT
public:
    explicit CFullScrWidget(QWidget *parent = nullptr);
    virtual ~CFullScrWidget();

signals:
    void closeRequest();

private:
    virtual bool event(QEvent *event) final;
    virtual void closeEvent(QCloseEvent*) final;
};

#endif // CFULLSCRWIDGET_H
