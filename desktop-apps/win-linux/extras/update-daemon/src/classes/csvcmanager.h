/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CSVCMANAGER_H
#define CSVCMANAGER_H

#include "classes/csocket.h"
#include <future>
#ifdef _WIN32
# include "classes/platform_win/cdownloader.h"
# include "classes/platform_win/cunzip.h"
#else
# include "classes/platform_linux/cdownloader.h"
# include "classes/platform_linux/cunzip.h"
#endif

typedef std::function<void(void)> FnVoidVoid;
using std::future;


class CSvcManager
{
public:
    explicit CSvcManager();
    ~CSvcManager();

    /* callback */
    void aboutToQuit(FnVoidVoid callback);

private:
    void init();
    void onQueryResponse(const int error, const int lenght);
    void onCompleteUnzip(const int error);
    void onCompleteSlot(const int error, const tstring &filePath);
    void onProgressSlot(const int percent);
    void unzipIfNeeded(const tstring &filePath, const tstring &newVersion);
    void clearTempFiles(const tstring &prefix, const tstring &except = tstring());
    void startReplacingFiles(const tstring &packageType, const bool restartAfterUpdate);
    void startReplacingService(const bool restartAfterUpdate);
#ifdef _WIN32
    void startInstallPackage();
#endif

    struct PackageData;
    struct SavedPackageData;
    PackageData      *m_packageData;
    SavedPackageData *m_savedPackageData;

    FnVoidVoid   m_quit_callback = nullptr;
    tstring      m_checkUrl,
                 m_currVersion,
                 m_ignVersion,
                 m_newVersion;
    bool         m_lock = false;
    int          m_downloadMode,
                 m_packageType;
    future<void> m_future_clear;
    CSocket     *m_socket = nullptr;
    CDownloader *m_pDownloader = nullptr;
    CUnzip      *m_pUnzip = nullptr;

    enum Mode {
        CHECK_UPDATES=0, DOWNLOAD_CHANGELOG=1, DOWNLOAD_UPDATES=2
    };
    enum Package {
        ISS = 0, MSI, Portable, Other
    };
};

#endif // CSVCMANAGER_H
