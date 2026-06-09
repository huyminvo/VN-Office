/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CTIMER_H
#define CTIMER_H

#include <SDL2/SDL.h>
#include <functional>

typedef std::function<void(void)> FnVoidVoid;


class CTimer
{
public:
    CTimer();
    ~CTimer();

    void stop();

    /* callback */
    void start(unsigned int timeout, FnVoidVoid callback);

private:
    SDL_TimerID timerID = 0;
};

#endif // CTIMER_H
