/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CUNZIP_H
#define CUNZIP_H

#include <future>
#include <functional>
#include <string>

#define UNZIP_OK 0
#define UNZIP_ERROR 1
#define UNZIP_ABORT 2

typedef std::function<void(int)> FnVoidInt;

using std::string;


class CUnzip
{
public:
    CUnzip();
    ~CUnzip();

    void extractArchive(const string &zipFilePath, const string &folderPath);
    void stop();

    /* callback */
    void onComplete(FnVoidInt callback);
    void onProgress(FnVoidInt callback);

private:
    class CUnzipPrivate;
    CUnzipPrivate *pimpl = nullptr;
};

#endif // CUNZIP_H
