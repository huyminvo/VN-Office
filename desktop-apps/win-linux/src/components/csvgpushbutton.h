/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CSVGPUSHBUTTON_H
#define CSVGPUSHBUTTON_H

#include <QPushButton>

class CSVGPushButton : public QPushButton
{
public:
    CSVGPushButton(QWidget * parent = nullptr);

    void setIcon(const QByteArray&);
    void setIcon(const QString& file, const QString& node = QString());
    void setIconSize(const QSize&);
    void setIconOpacity(const QColor& normal);
    void setDisabled(bool);
    void setUseStateOpacity(bool);
    void setFillDark(bool dark);

    bool setProperty(const char *name, const QVariant &value);

private:
    QByteArray m_svglayout;
    QString m_svgnode;
    QColor m_opacitynormal,
            m_opacitydisabled;
    bool m_usestateopacity = false;

    void updateIcon();
    using QPushButton::setDisabled;
};

#endif // CSVGPUSHBUTTON_H
