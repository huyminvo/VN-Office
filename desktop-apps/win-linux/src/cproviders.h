/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CPROVIDERS_H
#define CPROVIDERS_H

#include <QString>


class CProviders
{
public:
    CProviders(const CProviders&) = delete;
    CProviders& operator=(const CProviders&) = delete;
    static CProviders& instance();

    void init(const QString &prvds_json);
    bool editorsHasFrame(const QString &url, const QString &cloud);

private:
    CProviders();
    ~CProviders();

    class CProvidersPrivate;
    CProvidersPrivate *pimpl = nullptr;
};

#endif // CPROVIDERS_H
