/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#include "ctimer.h"


Uint32 timerCallback(Uint32 interval, void *param) {
    FnVoidVoid *callback = (FnVoidVoid*)param;
    if (callback && *callback)
        (*callback)();
    return interval;
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
    if (timerID != 0) {
        SDL_RemoveTimer(timerID);
        timerID = 0;
    }
}

void CTimer::start(unsigned int timeout, FnVoidVoid callback)
{
    stop();
    timerID = SDL_AddTimer(timeout, timerCallback, (void*)&callback);
}
