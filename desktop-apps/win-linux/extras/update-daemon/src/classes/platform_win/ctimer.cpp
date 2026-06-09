/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#include "ctimer.h"


FnVoidVoid _callback = nullptr;


VOID CALLBACK Timerproc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    if (_callback)
        _callback();
}

CTimer::CTimer()
{

}

CTimer::~CTimer()
{
    stop();
}

void CTimer::stop()
{
    if (timerId != 0) {
        KillTimer(NULL, timerId);
        timerId = 0;
    }
}

void CTimer::start(unsigned int timeout, FnVoidVoid callback)
{
    stop();
    _callback = callback;
    timerId = SetTimer(NULL, 0, timeout, Timerproc);
}
