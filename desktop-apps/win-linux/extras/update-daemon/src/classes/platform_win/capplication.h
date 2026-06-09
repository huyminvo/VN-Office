/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <Windows.h>


class CApplication
{
public:
    CApplication();
    ~CApplication();

    int exec();
    void exit(int);

private:
    DWORD  mainThreadId = 0;
};

#endif // CAPPLICATION_H
