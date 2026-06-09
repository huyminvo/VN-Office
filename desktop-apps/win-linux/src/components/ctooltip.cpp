/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "ctooltip.h"
#include "cascapplicationmanagerwrapper.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QLayout>
#include <QTimer>
#include <QCursor>
#include <QLineF>
#ifdef __linux__
# include <QX11Info>
#endif

#define FADE_TIMEOUT_MS 5000
#define ANIMATION_DURATION_MS 150


static bool isCompositingEnabled()
{
#ifdef __linux__
    return QX11Info::isCompositingManagerRunning();
#else
    return true;
#endif
}

CToolTip::CToolTip(QWidget * parent, const QString &text,
                   const QPoint &pos) :
    QWidget(parent, Qt::Tool | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint |
            Qt::BypassWindowManagerHint),
    m_activated(false)
{
    int margins = 0;
    if (isCompositingEnabled()) {
        setAttribute(Qt::WA_TranslucentBackground);
        margins = 10;
    }
//    setAttribute(Qt::WA_ShowWithoutActivating);
    setWindowModality(Qt::NonModal);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("CToolTip");
    QVBoxLayout *lut = new QVBoxLayout(this);
    setLayout(lut);
    layout()->setContentsMargins(margins, margins, margins, margins);
    m_label = new QLabel(this);
    m_label->setTextFormat(Qt::PlainText);
    layout()->addWidget(m_label);
    m_label->setText(text);
    parent->installEventFilter(this);
    QGraphicsOpacityEffect *grEffect = new QGraphicsOpacityEffect(this);
    setGraphicsEffect(grEffect);
    if (isCompositingEnabled()) {
        QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(m_label);
        shadow->setBlurRadius(16.0);
        shadow->setColor(QColor(0, 0, 0, 80));
        shadow->setOffset(1.0);
        m_label->setGraphicsEffect(shadow);
    }
    move(pos + QPoint(6,6));
    show();
    QTimer *tmr = new QTimer(this);
    tmr->setSingleShot(false);
    tmr->setInterval(100);
    connect(tmr, &QTimer::timeout, this, [=]() {
        if (QLineF(pos, QCursor::pos()).length() > 10.0) {
            tmr->stop();
            showEffect(EffectType::Fade);
        }
    });
    tmr->start();
}

CToolTip::~CToolTip()
{

}

bool CToolTip::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type()) {
    case QEvent::Hide:
    case QEvent::WindowDeactivate:
    case QEvent::MouseButtonPress:
        deleteLater();
        break;
    default:
        break;
    }
    return QWidget::eventFilter(obj, event);
}

void CToolTip::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    if (!m_activated) {
        m_activated = true;
        showEffect(EffectType::Arise);
        QTimer::singleShot(FADE_TIMEOUT_MS, this, [=]() {
            showEffect(EffectType::Fade);
        });
        if (AscAppManager::isRtlEnabled())
            move(pos() - QPoint(width(), 0));
    }
}

void CToolTip::showEffect(const EffectType efType)
{
    QPropertyAnimation *anm = new QPropertyAnimation(graphicsEffect(), "opacity");
    anm->setDuration(ANIMATION_DURATION_MS);
    if (efType == EffectType::Arise) {
        anm->setStartValue(0);
        anm->setEndValue(1);
        anm->setEasingCurve(QEasingCurve::InCurve);
    } else
    if (efType == EffectType::Fade) {
        anm->setStartValue(1);
        anm->setEndValue(0);
        connect(anm, &QPropertyAnimation::finished, this, [=](){
            deleteLater();
        });
    }
    anm->start(QPropertyAnimation::DeleteWhenStopped);
}
