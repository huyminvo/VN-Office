/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

/*
#include "csplash.h"
#include "csplash_p.h"
#include "defines.h"
#include <QApplication>
#include <QScreen>
#include <QSettings>
#include <QStyle>
#include "utils.h"

CSplash * _splash;

CSplash::CSplash(const QPixmap &p, Qt::WindowFlags f)
    : QSplashScreen(p, f)
{
    _splash = NULL;
}

void CSplash::show(int scrnum)
{
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), QApplication::screens().at(scrnum)->availableGeometry()));
    QSplashScreen::show();
}

void CSplash::showSplash()
{
    if ( !_splash ) {
        GET_REGISTRY_USER(reg_user)

        int _scr_num = 0;
        _splash = new CSplash(QPixmap(), Qt::WindowStaysOnTopHint);

        if (QApplication::screens().count() > 1) {
            QScreen * _screen = Utils::screenAt(reg_user.value("position").toRect().topLeft());

            if ( _screen ) {
                _splash->move(_screen->geometry().center());
                _scr_num = QApplication::screens().indexOf(_screen);
            }
        }

        double _dpi_ratio = Utils::getScreenDpiRatioByHWND(_splash->winId());

//        _splash->setPixmap(_dpi_ratio > 1 ? QPixmap(":/res/icons/splash_2x.png") : QPixmap(":/res/icons/splash.png"));
        _splash->setPixmap(getSplashImage(_dpi_ratio));
        _splash->show(_scr_num);
    }
}

void CSplash::hideSplash()
{
    if (_splash) {
//        g_splash->setParent((QWidget *)parent());
        _splash->close();

        delete _splash, _splash = NULL;
    }
}

double CSplash::startupDpiRatio()
{
    if (_splash) {
        return Utils::getScreenDpiRatioByHWND(_splash->winId());
    } else {
        QSplashScreen splash;

        if (QApplication::screens().count() > 1) {
            GET_REGISTRY_USER(reg_user)

            QScreen * _screen = Utils::screenAt(reg_user.value("position").toRect().topLeft());
            if ( _screen ) {
                splash.move(_screen->geometry().center());
            }
        }

        return Utils::getScreenDpiRatioByHWND(splash.winId());
    }
}
*/
