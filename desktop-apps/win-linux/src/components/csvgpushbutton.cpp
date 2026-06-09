/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "components/csvgpushbutton.h"
#include <QStyle>
#include <QFile>
#include <QSvgRenderer>
#include <QPainter>
#include <QTextStream>


CSVGPushButton::CSVGPushButton(QWidget * parent)
    : QPushButton(parent)
    , m_opacitynormal(QColor(255,255,255,255))
    , m_opacitydisabled(QColor(255,255,255,100))
{

}

void CSVGPushButton::setIcon(const QByteArray& svgstr)
{
    m_svglayout = svgstr;
    updateIcon();
}

void CSVGPushButton::setIcon(const QString& path, const QString& node)
{
    m_svgnode = node;

    QFile _f(path);
    if( _f.open(QIODevice::ReadOnly)) {
        QTextStream in(&_f);

        m_svglayout = in.readAll().toLocal8Bit();

        _f.close();

        updateIcon();
    }
}

void CSVGPushButton::setIconSize(const QSize& size)
{
    QPushButton::setIconSize(size);
    updateIcon();
}

void CSVGPushButton::setIconOpacity(const QColor& c)
{
    m_opacitynormal = c;
    m_usestateopacity = true;
    updateIcon();
}

void CSVGPushButton::setDisabled(bool status)
{
    QPushButton::setDisabled(status);
    updateIcon();
}

void CSVGPushButton::setUseStateOpacity(bool value)
{
    m_usestateopacity = value;
}

void CSVGPushButton::setFillDark(bool dark)
{
    if ( dark )
        m_opacitynormal = QColor(0,0,0,200),
        m_opacitydisabled = QColor(0,0,0,100);
    else
        m_opacitynormal = QColor(255,255,255,255),
        m_opacitydisabled = QColor(255,255,255,100);

    updateIcon();
}

void CSVGPushButton::updateIcon()
{
    if ( !m_svglayout.isEmpty() ) {
        QImage img(iconSize(), QImage::Format_ARGB32);
        img.fill(Qt::transparent);
        QPixmap pixmap = QPixmap::fromImage(img, Qt::NoFormatConversion);

        QPainter painter(&pixmap);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        QSvgRenderer r(m_svglayout);
        if ( m_svgnode.isEmpty() ) r.render(&painter);
        else {
            QRectF bounds = r.boundsOnElement(m_svgnode);
            double kx = pixmap.width() / r.viewBoxF().width();
            double ky = pixmap.height() / r.viewBoxF().height();
            r.render(&painter, m_svgnode, QRectF(bounds.x() * kx, bounds.y() * ky, bounds.width() * kx, bounds.height() * ky));
        }

        if ( m_usestateopacity ) {
            painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
            if ( !isEnabled() ) {
                painter.fillRect(pixmap.rect(), m_opacitydisabled);
            } else {
                painter.fillRect(pixmap.rect(), m_opacitynormal);
            }
        }
        painter.end();

        QPushButton::setIcon(QIcon(pixmap));
    }
}

bool CSVGPushButton::setProperty(const char *name, const QVariant &value)
{
    auto retval = QPushButton::setProperty(name, value);
    style()->polish(this);
    return retval;
}
