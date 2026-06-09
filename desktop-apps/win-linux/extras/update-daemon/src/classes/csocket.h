/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CSOCKET_H
#define CSOCKET_H

#include <string>
#include <vector>
#include <functional>
#ifdef _WIN32
# include <tchar.h>
# define tchar wchar_t
# define tstringstream std::wstringstream
# define tstring std::wstring
# define to_tstring to_wstring
#else
# define _T(str) str
# define tchar char
# define tstringstream std::stringstream
# define tstring std::string
# define to_tstring to_string
#endif

using std::size_t;

typedef std::function<void(void*, size_t)> FnVoidData;
typedef std::function<void(const char*)> FnVoidCharPtr;


enum MsgCommands {
    MSG_CheckUpdates = 0,
    MSG_LoadUpdates,
    MSG_LoadCheckFinished,
    MSG_LoadUpdateFinished,
    MSG_UnzipIfNeeded,
    MSG_ShowStartInstallMessage,
    MSG_StartReplacingFiles,
    MSG_ClearTempFiles,
    MSG_Progress,
    MSG_StopDownload,
    MSG_OtherError,
    MSG_RequestContentLenght,
    MSG_UnzipProgress,
    MSG_SetLanguage,
    MSG_StartReplacingService,
    MSG_StartInstallPackage
};

class CSocket
{
public:
    CSocket(int sender_port, int receiver_port, bool retry_connect = true, bool use_unique_addr = false);
    ~CSocket();

    /* callback */
    bool isPrimaryInstance();
    bool sendMessage(void *data, size_t size);
    bool sendMessage(int cmd, const tstring &param1 = _T(""), const tstring &param2 = _T(""));
    void onMessageReceived(FnVoidData callback);
    void onError(FnVoidCharPtr callback);
    int  parseMessage(void *data, std::vector<tstring> &params);

private:
    class CSocketPrv;
    CSocketPrv *pimpl = nullptr;
};

#endif // CSOCKET_H
