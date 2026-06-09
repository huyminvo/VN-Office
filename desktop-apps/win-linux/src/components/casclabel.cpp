/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "casclabel.h"
#include <QGraphicsOpacityEffect>
#include <QResizeEvent>

#include <QDebug>

CAscLabel::CAscLabel(QWidget * parent) :
    QLabel(parent)
{

}

CAscLabel::CAscLabel(const QString& caption, QWidget * parent) :
    QLabel(caption, parent)
{
    QLinearGradient alphaGradient(rect().topLeft(), rect().topRight());

    alphaGradient.setColorAt(0.8, Qt::black);
    alphaGradient.setColorAt(1.0, Qt::transparent);

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
    effect->setOpacityMask(alphaGradient);

    setGraphicsEffect(effect);
}

CAscLabel::~CAscLabel()
{

}

void CAscLabel::paintEvent(QPaintEvent * e)
{
//    QPainter p(this);
//    QFontMetrics fm(font());

//    if (fm.width(text()) > contentsRect().width()) {
//        QString elided_txt;

//        if(ELIDE_MIDDLE) // ELIDE_MIDDLE is part of a class enum
//            elided_txt = this->fontMetrics().elidedText(text(), Qt::ElideMiddle, rect().width(), Qt::TextShowMnemonic);
//        else { //Handle all other elide modes you want to support.
//        }

//        p.drawText(rect(), elided_txt);
//    } else
        QLabel::paintEvent(e);
}

void CAscLabel::resizeEvent(QResizeEvent * e) {
    QLabel::resizeEvent(e);

    QLinearGradient alphaGradient(QPointF(0,0), QPointF(e->size().width(),0));

    alphaGradient.setColorAt(0.8, Qt::black);
    alphaGradient.setColorAt(1.0, Qt::transparent);

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect;
    effect->setOpacityMask(alphaGradient);

    setGraphicsEffect(effect);
}
