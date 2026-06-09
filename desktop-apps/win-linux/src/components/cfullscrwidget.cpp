/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "cfullscrwidget.h"
#include "windows/cpresenterwindow.h"
#include <QApplication>
#include <QTimer>


CFullScrWidget::CFullScrWidget(QWidget *parent) :
    QWidget(parent)
{

}

CFullScrWidget::~CFullScrWidget()
{

}

bool CFullScrWidget::event(QEvent *ev)
{
    switch (ev->type()) {
    case QEvent::WindowActivate: {
        QTimer::singleShot(60, this, []() {
            const auto widgets = qApp->topLevelWidgets();
            for (QWidget* w : widgets) {
                if (CPresenterWindow* p = dynamic_cast<CPresenterWindow*>(w)) {
                    if (!p->windowState().testFlag(Qt::WindowMinimized)) {
                        p->raise();
                        p->activateWindow();
                    }
                    break;
                }
            }
        });
        break;
    }
    default:
        break;
    }
    return QWidget::event(ev);
}

void CFullScrWidget::closeEvent(QCloseEvent *e)
{
    emit closeRequest();
    e->ignore();
}
