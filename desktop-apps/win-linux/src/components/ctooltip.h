/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CTOOLTIP_H
#define CTOOLTIP_H

#include <QLabel>
#include <QPoint>
#include <QEvent>


class CToolTip: public QWidget
{
    Q_OBJECT
public:
    CToolTip(QWidget * parent = nullptr,
             const QString &text = QString(),
             const QPoint &pos = QPoint());
    ~CToolTip();

private:
    enum class EffectType {
        Arise, Fade
    };
    virtual bool eventFilter(QObject*, QEvent*) final;
    virtual void showEvent(QShowEvent*) final;
    void showEffect(const EffectType efType);
    QLabel *m_label;
    bool m_activated;
};

#endif // CTOOLTIP_H
