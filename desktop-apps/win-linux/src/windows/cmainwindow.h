/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#ifdef _WIN32
# include "windows/platform_win/cwindowplatform.h"
#else
# include "windows/platform_linux/cwindowplatform.h"
#endif
#include "cscalingwrapper.h"
#include "components/asctabwidget.h"
#include "components/cdownloadwidget.h"
#include "components/csvgpushbutton.h"
#include <QSettings>
#include <math.h>


class CMainWindow : public CWindowPlatform, public CScalingWrapper
{
    Q_OBJECT
public:
    explicit CMainWindow(const QRect&);
    virtual ~CMainWindow();

    QWidget * editor(int index);
    QRect windowRect() const;
    QString documentName(int vid);
    void selectView(int id);
    void selectView(const QString& url);
    int attachEditor(QWidget *, int index = -1);
    int attachEditor(QWidget *, const QPoint&);
    int editorsCount();
    int editorsCount(const std::wstring& portal);
    bool canPinTabAtPoint(const QPoint& pt);
    bool holdView(int id) const;
    bool slideshowHoldView(int id) const;
    bool isSlideshowMode() const;
    virtual void applyTheme(const std::wstring&) final;
    virtual void focus() final;
    void close();
    bool isAboutToClose() const;
    void cancelClose();
    QSize contentSize();

signals:
    void aboutToClose();

private:
//    void captureMouse(int);
#ifdef __linux__
    virtual void dragEnterEvent(QDragEnterEvent *event) final;
    virtual void dropEvent(QDropEvent *event) final;
#endif


/** MainPanel **/

public:
    CAscTabWidget * tabWidget();
    void goStart();
    void doOpenLocalFiles(const std::vector<std::wstring> *);
    void doOpenLocalFiles(const QStringList&);
    void createLocalFile(const QString& name, int format);
    void attachStartPanel(QCefView * const);
    void toggleButtonMain(bool, bool delay = false);
    bool holdUid(int) const;
    bool holdUrl(const QString&, AscEditorType) const;
    bool slideshowHoldUrl(const QString&, AscEditorType) const;
    int  startPanelId();
    int  tabCloseRequest(int index = -1);
#ifdef __linux
    void setMouseTracking(bool);
#endif
    void doOpenLocalFile(COpenOptions&);
    void handleWindowAction(const std::wstring& action);
    virtual void setScreenScalingFactor(double, bool resize = true) final;
    virtual void updateScalingFactor(double) final;

protected:
    virtual QString getSaveMessage() const;
    virtual void refreshAboutVersion() {};
    virtual void onLayoutDirectionChanged() final;
#ifdef _WIN32
    virtual void applyWindowState() final;
#endif
    void closeEvent(QCloseEvent *) override;
    void showEvent(QShowEvent *) override;

public slots:
    void pushButtonMainClicked();
    void onTabClicked(int);
    void onTabChanged(int);
    void onTabCloseRequest(int);
    void onEditorActionRequest(int, const QString&);
    void onTabsCountChanged(int, int, int);
    void onWebAppsFeatures(int id, std::wstring);
    void onDocumentType(int id, int type);
    void onDocumentName(void *);
    void onEditorConfig(int, std::wstring cfg);
    void onDocumentChanged(int id, bool changed);
    void onDocumentSave(int id, bool cancel = false);
    void onDocumentSaveInnerRequest(int id);
    void onDocumentDownload(void * info);
    void onDocumentLoadFinished(int);
    void onDocumentFragmented(int, bool);
    void onDocumentFragmentedBuild(int, int);
    void onFullScreen(int id, bool apply);
    void onKeyDown(void *);
    void onLocalFilesOpen(void *);
    void onLocalFileRecent(void *);
    void onLocalFileRecent(const COpenOptions&);
    void onLocalFileLocation(QString);
    void onFileLocation(int, QString);
    void onPortalOpen(QString);
    void onPortalLogout(std::wstring portal);
    void onPortalLogin(int viewid, const std::wstring& json);
    void onPortalUITheme(int viewid, const std::wstring& json);
    void onPortalNew(QString);
    void onPortalCreate();
    void onOutsideAuth(QString);
    void onEditorAllowedClose(int);
    void onWebTitleChanged(int, std::wstring json) {}
    void onDocumentPrint(void *);
    void onReporterMode(int, bool);
    void onErrorPage(int, const std::wstring&);
    virtual void onDocumentReady(int);

private:
    QWidget * createMainPanel(QWidget *parent);
    int  trySaveDocument(int);
    void setTabMenu(int index, const QPoint &pos);

    CAscTabWidget *  m_pTabs = nullptr;
    CSVGPushButton*  m_pButtonMain = nullptr;
    QWidget*         m_pMainWidget = nullptr;
    QPushButton*     m_pButtonProfile = nullptr;
    CDownloadWidget* m_pWidgetDownload = nullptr;
    QString          m_savePortal;
    bool             m_isMaximized = false;
    int              m_saveAction = 0;

    bool m_isCloseAll = false;
    bool m_isStartPageReady = false;
    std::wstring m_keepedAction;

private slots:
    virtual void onCloseEvent() final;
};

#endif // CMAINWINDOW_H
