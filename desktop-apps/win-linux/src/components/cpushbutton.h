/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CPUSHBUTTON_H
#define CPUSHBUTTON_H

#include <QPushButton>


class QSvgRenderer;
class QVariantAnimation;
class CPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CPushButton(QWidget *parent = nullptr);
    ~CPushButton();
    void setAnimatedIcon(const QString &path);
    void setStaticIcon(const QString &path);
    void setFaded(bool);
    bool isStarted();

protected:
    bool event(QEvent*);

private:
    void releaseSvg();
    void onSvgRepaint(double);
    void setOpacity(double);
    QVariantAnimation * m_animation = nullptr;
    QSvgRenderer *m_renderer = nullptr;
    bool m_faded = false;
};

#endif // CPUSHBUTTON_H
