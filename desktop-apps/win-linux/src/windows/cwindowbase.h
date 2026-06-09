/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CWINDOWBASE_H
#define CWINDOWBASE_H

#define WINDOW_MIN_WIDTH    520
#define WINDOW_MIN_HEIGHT   480

#define MAIN_WINDOW_MIN_WIDTH    960
#define MAIN_WINDOW_MIN_HEIGHT   661
#define MAIN_WINDOW_DEFAULT_SIZE QSize(1200,740)
#define EDITOR_WINDOW_MIN_WIDTH  920
#define SCREEN_THRESHOLD_SIZE    QSize(1366,768)

#define BUTTON_MAIN_WIDTH   112
#define MAIN_WINDOW_BORDER_WIDTH 3
#define WINDOW_TITLE_MIN_WIDTH 200
#define TOOLBTN_HEIGHT_WIN10 35
#define TOOLBTN_HEIGHT      28
#define TOOLBTN_WIDTH       40
#ifdef _WIN32
# define TITLEBTN_WIDTH     40
#else
# define TITLEBTN_WIDTH     (WindowHelper::getEnvInfo() == WindowHelper::KDE ? 24 : 28)
#endif
#define TITLE_HEIGHT        28

#include <QMainWindow>
#include <QPushButton>
#include <memory>
#include "components/celipsislabel.h"


class CPushButton;
class CWindowBase : public QMainWindow
{
public:
    explicit CWindowBase(const QRect&);
    virtual ~CWindowBase();   

    static QRect startRect(const QRect &rc, double &dpi);
    static QSize expectedContentSize(const QRect &rc, bool extended = false);
    QWidget * handle() const;
    QWidget * mainPanel() const;
    bool isCustomWindowStyle();
    void updateScaling(bool resize = true);
    virtual void adjustGeometry() = 0;
    virtual void setWindowColors(const QColor&, const QColor& border = QColor(), bool isActive = false) = 0;
    virtual void applyTheme(const std::wstring&);

protected:
    enum BtnType {
        Btn_Minimize, Btn_Maximize, Btn_Close
    };

    CPushButton* createToolButton(QWidget * parent, const QString& name);
    QWidget* createTopPanel(QWidget *parent);
    void saveWindowState(const QString &baseKey = "");
    void moveToPrimaryScreen();
    void setIsCustomWindowStyle(bool);
    virtual bool event(QEvent*);
    virtual void setScreenScalingFactor(double, bool resize = true);
    virtual void applyWindowState();
    virtual void setWindowTitle(const QString&);
    virtual void onMinimizeEvent();
    virtual void onMaximizeEvent();
    virtual void onCloseEvent();
    virtual void focus();

    QVector<CPushButton*> m_pTopButtons;
    CElipsisLabel *m_labelTitle = nullptr;
    QWidget       *m_pMainPanel = nullptr,
                  *m_boxTitleBtns = nullptr,
                  *m_pMainView = nullptr;
    double         m_dpiRatio;
    QColor         m_brdColor,
                   m_bkgColor;
    QRect          m_window_rect;
    int            m_toolbtn_height = TOOLBTN_HEIGHT;

    virtual void showEvent(QShowEvent *);

private:
    class CWindowBasePrivate;
    std::unique_ptr<CWindowBasePrivate> pimpl;
    bool  m_windowActivated;
};

#endif // CWINDOWBASE_H
