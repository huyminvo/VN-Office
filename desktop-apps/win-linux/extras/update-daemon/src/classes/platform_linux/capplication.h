/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <atomic>


class CApplication
{
public:
    CApplication();
    ~CApplication();

    int exec();
    void exit(int);

private:
    std::atomic_bool m_run{true};
};

#endif // CAPPLICATION_H
