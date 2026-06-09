/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "components/cpushbutton.h"
#include <QPainter>
#include <QSvgRenderer>
#include <QVariantAnimation>
#include <QGraphicsOpacityEffect>
#include <QEvent>

#define ANIMATION_MS 2500


CPushButton::CPushButton(QWidget *parent)
    : QPushButton(parent)
{}

CPushButton::~CPushButton()
{
    releaseSvg();
}

void CPushButton::setAnimatedIcon(const QString &path)
{
    releaseSvg();
    if (path.isEmpty())
        return;
    m_renderer = new QSvgRenderer(path, this);

    m_animation = new QVariantAnimation(this);
    m_animation->setStartValue(0);
    m_animation->setEndValue(360);
    m_animation->setDuration(ANIMATION_MS);
    m_animation->setLoopCount(-1);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    connect(m_animation, &QVariantAnimation::valueChanged, this, [=](const QVariant &val) {
        onSvgRepaint(val.toDouble());
    });
    m_animation->start(QAbstractAnimation::KeepWhenStopped);
}

void CPushButton::setStaticIcon(const QString &path)
{
    releaseSvg();
    if (path.isEmpty())
        return;
//    m_renderer = new QSvgRenderer(path, this);
//    onSvgRepaint(0);
    setIcon(QIcon(path));
}

void CPushButton::setFaded(bool faded)
{
    m_faded = faded;
    setOpacity(m_faded ? 0.5 : 1.0);
}

bool CPushButton::isStarted()
{
    return m_animation && m_animation->state() == QAbstractAnimation::Running;
}

bool CPushButton::event(QEvent *ev)
{
    switch (ev->type()) {
    case QEvent::Enter:
        if (m_faded)
            setOpacity(1.0);
        break;
    case QEvent::Leave:
        if (m_faded)
            setOpacity(0.5);
        break;
    default:
        break;
    }
    return QPushButton::event(ev);
}

void CPushButton::releaseSvg()
{
    if (m_animation) {
        if (m_animation->state() != QAbstractAnimation::Stopped)
            m_animation->stop();
        m_animation->disconnect();
        delete m_animation, m_animation = nullptr;
    }
    if (m_renderer)
        delete m_renderer, m_renderer = nullptr;
}

void CPushButton::onSvgRepaint(double angle)
{
    if (m_renderer && m_renderer->isValid()) {
        QSize icon_size = iconSize();
        double offset = (double)icon_size.height()/2;
        QPixmap pixmap(icon_size);
        pixmap.fill(Qt::transparent);

        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(offset, offset);
        painter.rotate(angle);
        painter.translate(-offset, -offset);
        m_renderer->render(&painter);
        painter.end();
        setIcon(QIcon(pixmap));
    }
}

void CPushButton::setOpacity(double opacity)
{
    QGraphicsOpacityEffect *efct = qobject_cast<QGraphicsOpacityEffect*>(graphicsEffect());
    if (!efct) {
        efct = new QGraphicsOpacityEffect(this);
        setGraphicsEffect(efct);
    }
    efct->setOpacity(opacity);
}
