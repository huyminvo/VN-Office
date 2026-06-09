/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CASCTABDATA_H
#define CASCTABDATA_H


#include <QString>
#include "qcefview.h"

typedef CefViewWrapperType CefType;

struct CAscTabData
{
public:
    CAscTabData(const QString &, CefType wt = cvwtEditor);
    CAscTabData(const QString &, AscEditorType ct);
    ~CAscTabData() {}

    void    setTitle(const QString&);
    void    setChanged(bool);
    void    setIsLocal(bool);
    void    setUrl(const std::wstring&);
    void    setUrl(const QString&);
    void    setCloudName(const QString&);
    void    close();
    void    reuse();
    QString title(bool orig = false) const;
    bool    modified() const;
    bool    hasChanges() const;
    bool    closed() const;
    bool    isLocal() const;
    CefType viewType() const;
    std::wstring url() const;
    bool    isViewType(CefType) const;
    bool    eventLoadSupported() const;
    void    setHasError();
    void    setEventLoadSupported(bool);
    void    setFeatures(const std::wstring&);
    std::wstring features() const;
    bool    hasFeature(const std::wstring&) const;
    bool    hasFrame() const;
    bool    hasError() const;

    AscEditorType   contentType() const;
    void            setContentType(AscEditorType);
private:
    QString _title;
    bool    _is_changed = false,
            _is_readonly = false,
            _has_changes = false;
    bool    _is_closed = false;
    bool    _is_local;
    bool    _has_error = false;
    CefType _vtype;
    std::wstring _url;
    bool    _event_load_supported = false;
    std::wstring _features;
    QString _str_readonly;
    QString _cloud;

    AscEditorType _typeContent;
};

#endif // CASCTABDATA_H
