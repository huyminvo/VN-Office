/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include <QApplication>
#include <QProcess>
#include <QFileInfo>
#include <Windows.h>
#ifndef __OS_WIN_XP
# include "jumplist.h"
# include "shellassoc.h"
# include <shlobj_core.h>
#endif


void SetAppUserModelId()
{
    if (HMODULE lib = LoadLibrary(L"shell32")) {
        HRESULT (WINAPI *SetAppUserModelID)(PCWSTR AppID);
        *(FARPROC*)&SetAppUserModelID = GetProcAddress(lib, "SetCurrentProcessExplicitAppUserModelID");
        if (SetAppUserModelID)
            SetAppUserModelID(TEXT(APP_USER_MODEL_ID));
        FreeLibrary(lib);
    }
}


int main(int argc, char *argv[])
{
    SetAppUserModelId();

    QApplication a(argc, argv);
//    return a.exec();

    QStringList _cmdArgs(QCoreApplication::arguments().mid(1));
#ifndef __OS_WIN_XP
    if (_cmdArgs.contains("--create-jump-list")) {
        CreateJumpList();
        return 0;
    } else
    if (_cmdArgs.contains("--remove-jump-list")) {
        ClearHistory();
        DeleteJumpList();
        return 0;
    } else
    if (_cmdArgs.contains("--assoc")) {
        if (_cmdArgs.size() > 1) {
            std::wstring assocLine = _cmdArgs.at(1).toStdWString();
            size_t len = assocLine.length();
            if (len == 0)
                return 0;

            std::vector<AssocPair> assocList;
            wchar_t *buf = &assocLine[0];
            if (buf[len - 1] == ';')
                buf[len - 1] = '\0';

            size_t last_sep_pos = 0;
            wchar_t *it = buf;
            while (1) {
                while (*it != '\0' && *it != ';')
                    it++;
                wchar_t tmp = *it;
                *it = '\0';
                wchar_t *pair = buf + last_sep_pos;
                if (wchar_t *colon = wcschr(pair, L':')) {
                    *colon = L'\0';
                    assocList.push_back({pair, colon + 1});
                }
                if (tmp == '\0')
                    break;
                last_sep_pos = it - buf + 1;
                it++;
            }
            if (!assocList.empty())
                SetUserFileAssoc(assocList);
        }
        return 0;
    }
#endif

    QFileInfo _fi(QString::fromLocal8Bit(argv[0]));

    qputenv("Path", "./converter;" + qgetenv("Path"));

#define APP_LAUNCH_NAME "./DesktopEditors.exe"

//    QProcess::startDetached(fi.absolutePath() + APP_LAUNCH_NAME, _cmdArgs, fi.absolutePath());
    QProcess::startDetached(_fi.absolutePath() + "./editors.exe", _cmdArgs, _fi.absolutePath());

    return 0;
}
