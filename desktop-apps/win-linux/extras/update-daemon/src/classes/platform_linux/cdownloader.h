/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CDOWNLOADER_H
#define CDOWNLOADER_H

#include <string>
#include <functional>

typedef std::function<void(int)> FnVoidInt;
typedef std::function<void(int,int)> FnVoidIntInt;

using std::string;


class CDownloaderPrivate;

class CDownloader
{
public:
    CDownloader();
    ~CDownloader();

    bool isUrlAccessible(const string &url);
    void queryContentLenght(const string &url);
    void downloadFile(const string &url, const string &filePath);
    void start();
    void pause();
    void stop();
    string GetFilePath();

    /* callback */
    void onQueryResponse(FnVoidIntInt callback);
    void onComplete(FnVoidInt callback);
    void onProgress(FnVoidInt callback);

private:
    CDownloaderPrivate *pimpl = nullptr;
};

#endif // CDOWNLOADER_H
