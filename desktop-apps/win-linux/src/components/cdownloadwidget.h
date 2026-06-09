/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CDOWNLOADWIDGET_H
#define CDOWNLOADWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include "cpushbutton.h"


class CDownloadWidget : public QWidget
{
    Q_OBJECT
    struct CDownloadItem;
    typedef std::map<int, CDownloadItem *>::const_iterator MapItem;

public:
    explicit CDownloadWidget(QWidget *parent = 0);
    ~CDownloadWidget();

    void downloadProcess(void *);
    QPushButton * toolButton();
    void updateScalingFactor(double);
    void applyTheme();
    void onLayoutDirectionChanged();

protected:
    virtual void closeEvent(QCloseEvent *) final;
    virtual bool eventFilter(QObject*, QEvent*) final;

private:
    QWidget * addFile(const QString&, int);
    QString getFileName(const QString&) const;
    void removeFile(MapItem);
    void onStart();
    void onFinish(int);
    void clearlAll();
    void polish();

    CPushButton * m_pToolButton = nullptr;
    QScrollArea * m_pArea = nullptr;
    QWidget *m_pContentArea = nullptr;
    QFrame *m_mainFrame = nullptr,
           *m_titleFrame = nullptr;
    std::map<int, CDownloadItem *> m_mapDownloads;
    double m_dpiRatio = 1;
};

#endif // CDOWNLOADWIDGET_H
