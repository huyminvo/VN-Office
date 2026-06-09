/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CTIMER_H
#define CTIMER_H

#include <Windows.h>
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
    UINT_PTR timerId = 0;
};

#endif // CTIMER_H
