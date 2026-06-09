/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <list>
#include <vector>

using std::string;
using std::wstring;
using std::to_wstring;
using std::list;

#define FUNCTION_INFO wstring(TEXT(__FUNCTION__)) + L" Line: " + to_wstring(__LINE__)
#define DEFAULT_ERROR_MESSAGE _TR(MESSAGE_TEXT_ERR1) + L" " + FUNCTION_INFO
#define ADVANCED_ERROR_MESSAGE DEFAULT_ERROR_MESSAGE + \
    L" " + NS_Utils::GetLastErrorAsString()

namespace NS_Utils
{
void setRunAsApp();
bool isRunAsApp();
void parseCmdArgs(int argc, wchar_t *argv[]);
bool cmdArgContains(const wstring &param);
wstring cmdArgValue(const wstring &param);
wstring cmdArgsAsString();
wstring GetLastErrorAsString();
int ShowMessage(wstring str, bool showError = false);
wstring GetAppLanguage();
}

namespace NS_File
{
bool GetFilesList(const wstring &path, list<wstring> *lst, wstring &error, bool ignore_locked = false, bool folders_only = false);
std::vector<wstring> findFilesByPattern(const wstring &path, const wstring &pattern);
bool readFile(const wstring &filePath, list<wstring> &linesList);
bool readBinFile(const wstring &filePath, list<wstring> &linesList);
bool writeToFile(const wstring &filePath, list<wstring> &linesList);
bool writeToBinFile(const wstring &filePath, list<wstring> &linesList);
bool runProcess(const wstring &fileName, const wstring &args);
bool isProcessRunning(const wstring &filePath);
bool fileExists(const wstring &filePath);
bool dirExists(const wstring &dirName);
bool dirIsEmpty(const wstring &dirName);
bool makePath(const wstring &path, size_t root_offset = 3);
bool replaceFile(const wstring &oldFilePath, const wstring &newFilePath);
bool replaceFolder(const wstring &from, const wstring &to, bool remove_existing = false);
bool removeFile(const wstring &filePath, bool safeMode = false);
bool removeDirRecursively(const wstring &dir);
wstring fromNativeSeparators(const wstring &path);
wstring toNativeSeparators(const wstring &path);
wstring parentPath(const wstring &path);
wstring tempPath();
wstring appPath();
wstring getFileHash(const wstring &fileName);
bool verifyEmbeddedSignature(const wstring &fileName);
}

namespace NS_Logger
{
void AllowWriteLog();
void WriteLog(const wstring &log, bool showMessage = false);
}

#endif // UTILS_H
