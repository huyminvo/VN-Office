/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CELIPSISLABEL_H
#define CELIPSISLABEL_H

#include <QLabel>
#include <QResizeEvent>

class CElipsisLabel : public QLabel
{
    Q_OBJECT
public:
    CElipsisLabel(const QString &text, QWidget *parent = Q_NULLPTR);
    CElipsisLabel(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

    auto setText(const QString&) -> void;
    auto setEllipsisMode(Qt::TextElideMode) -> void;
    auto updateText() -> void;
    auto textWidth() -> int;

signals:
    void onResize(QSize size, int textWidth);

protected:
    virtual void resizeEvent(QResizeEvent *event) final;
    using QLabel::setText;

private:
    QString orig_text;
    Qt::TextElideMode elide_mode = Qt::ElideRight;
};

#endif // CELIPSISLABEL_H
