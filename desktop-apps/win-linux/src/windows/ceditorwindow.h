/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CEDITORWINDOW_H
#define CEDITORWINDOW_H

#ifdef __linux__
# include "windows/platform_linux/cwindowplatform.h"
#else
# include "windows/platform_win/cwindowplatform.h"
#endif

#include "components/ctabpanel.h"
#include "components/asctabwidget.h"
#include <memory>
#include <QCoreApplication>

class QSpacerItem;
class CEditorWindowPrivate;
class CEditorWindow : public CWindowPlatform, public CScalingWrapper
{
    Q_OBJECT

public:
    CEditorWindow(const QRect& rect, CTabPanel* view);
    ~CEditorWindow();

    static CEditorWindow* create(const QRect& rect, const COpenOptions& opts);
    const QObject * receiver();
    CTabPanel * releaseEditorView() const;
    CTabPanel * mainView() const;
    AscEditorType editorType() const;
    QString documentName() const;
    double scaling() const;
    int closeWindow();
    bool closed() const;
    bool modified() const;
    bool holdView(const std::wstring& portal) const;
    bool isSlideshowMode() const;
    void undock(bool maximized = false);
    virtual bool holdView(int id) const final;
    virtual void applyTheme(const std::wstring&) final;

protected:
    void closeEvent(QCloseEvent *) override;
    virtual void onLayoutDirectionChanged() final;

private:
    CEditorWindow(const QRect& rect, const COpenOptions& opts);

    QWidget * createMainPanel(QWidget *, const QString&);
    CMenu* menu();
    void init(CTabPanel *panel);
    void setMenu();
    void recalculatePlaces();
    void updateTitleCaption();
    void onSizeEvent(int);
    void onMoveEvent(const QRect&);
//    void onExitSizeMove();
    void captureMouse();
//    virtual int calcTitleCaptionWidth() final;
    virtual void focus() final;
    virtual void onCloseEvent() final;
    virtual void onMinimizeEvent() final;
    virtual void onMaximizeEvent() final;
    virtual bool event(QEvent *) final;
    virtual void setScreenScalingFactor(double, bool resize = true) final;

    QMetaObject::Connection m_modalSlotConnection;
    QString m_css;
    bool m_restoreMaximized = false;
    QSpacerItem *m_pSpacer = nullptr;
    CMenu *m_pMenu = nullptr;

    friend class CEditorWindowPrivate;
    std::unique_ptr<CEditorWindowPrivate> d_ptr;

private slots:
    void onClickButtonHome();
};

#endif // CEDITORWINDOW_H
