/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "components/celipsislabel.h"


auto ellipsis_text_(const QWidget * widget, const QString& str, Qt::TextElideMode mode = Qt::ElideRight) -> QString
{
    QMargins _margins = widget->contentsMargins();
    int _padding = _margins.left() + _margins.right();
    int _width = widget->maximumWidth() != QWIDGETSIZE_MAX ? widget->maximumWidth() : widget->width();
    QFontMetrics _metrics(widget->font());

    return _metrics.elidedText(str, mode, _width - _padding - 1);
}

CElipsisLabel::CElipsisLabel(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent, f)
{
    setTextFormat(Qt::PlainText);
}

CElipsisLabel::CElipsisLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
    , orig_text(text)
{
    setTextFormat(Qt::PlainText);
//    QString elt = elipsis_text(this, text, Qt::ElideMiddle);
//    setText(elt);
}

void CElipsisLabel::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);

    if ( event->size().width() != event->oldSize().width() ) {
        QString elt = ellipsis_text_(this, orig_text, elide_mode);
        QLabel::setText(elt);
        QFontMetrics fm(font());
#if (QT_VERSION < QT_VERSION_CHECK(5,11,0))
        int textWidth = fm.width(elt);
#else
        int textWidth = fm.horizontalAdvance(elt);
#endif
        emit onResize(event->size(), textWidth);
    }
}

auto CElipsisLabel::setText(const QString& text) -> void
{
    orig_text = text;

    QString elt = ellipsis_text_(this, text, elide_mode);
    QLabel::setText(elt);
}

auto CElipsisLabel::setEllipsisMode(Qt::TextElideMode mode) -> void
{
    elide_mode = mode;
}

auto CElipsisLabel::textWidth() -> int
{
    QString elt = ellipsis_text_(this, orig_text, elide_mode);
    QFontMetrics fm(font());
#if (QT_VERSION < QT_VERSION_CHECK(5,11,0))
    int textWidth = fm.width(elt);
#else
    int textWidth = fm.horizontalAdvance(elt);
#endif
    return textWidth;
}

auto CElipsisLabel::updateText() -> void
{
    QString elt = ellipsis_text_(this, orig_text, elide_mode);
    if ( elt != text() ) {
        QLabel::setText(elt);
    }
}
