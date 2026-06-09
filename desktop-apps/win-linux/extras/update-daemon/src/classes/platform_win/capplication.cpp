/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#include "capplication.h"


CApplication::CApplication()
{
    mainThreadId = GetCurrentThreadId();
}

CApplication::~CApplication()
{

}

int CApplication::exec()
{
    MSG msg = {};
    BOOL ret;
    while ((ret = GetMessage(&msg, NULL, 0, 0)) != 0) {
        if (ret == -1)
            break;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

void CApplication::exit(int code)
{
    PostThreadMessage(mainThreadId, WM_QUIT, code, 0);
}
