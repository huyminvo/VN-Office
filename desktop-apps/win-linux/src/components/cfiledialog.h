/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CFILEDIALOG_H
#define CFILEDIALOG_H

#include <QObject>
#include <QMap>


class CFileDialogWrapper : public QObject
{
    Q_OBJECT

public:
    explicit CFileDialogWrapper(QWidget * p = 0);
    ~CFileDialogWrapper();

    bool    modalSaveAs(QString&, int selected = -1);

//    QString modalOpen(const QString&, const QString& filter = QString(), QString * selectedFilter = Q_NULLPTR);
    QStringList modalOpen(const QString&, const QString& filter = QString(), QString * selectedFilter = Q_NULLPTR, bool multi = false);
    QString     modalOpenSingle(const QString&, const QString& filter = QString(), QString * selectedFilter = Q_NULLPTR);

    QStringList modalOpenImage(const QString&);
    QStringList modalOpenImages(const QString&);
    QStringList modalOpenPlugin(const QString&);
    QStringList modalOpenPlugins(const QString&);
    QStringList modalOpenAny(const QString&, bool multi = false);
    QStringList modalOpenDocuments(const QString&, bool multi = false);
    QStringList modalOpenSpreadsheets(const QString&, bool multi = false);
    QStringList modalOpenPresentations(const QString&, bool multi = false);
    QStringList modalOpenMedia(const QString& type, const QString& path, bool multi = false);
    QStringList modalOpenForEncrypt(const QString& path, bool multi = false);

    QString selectFolder(const QString& folder);
    void    setTitle(const QString&);
    void    setFormats(std::vector<int>&);
    int     getFormat();

private:
    QString getFilter(const QString&) const;
    int getKey(const QString &value);
//    QString joinFilters() const;
    void checkForMimeTypes(QStringList &files, const QString &type);
    QString joinExtentions(const QString&) const;
    QString m_title;
    QString m_filters;
    QMap<int, QString> m_mapFilters;
    int m_format;
};

#endif // CFILEDIALOG_H
