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
#include "classes/translator.h"

using std::string;
using std::to_string;
using std::list;

#define FUNCTION_INFO string(__FUNCTION__) + " Line: " + to_string(__LINE__)
#define DEFAULT_ERROR_MESSAGE _TR(MESSAGE_TEXT_ERR1) + " " + FUNCTION_INFO
#define ADVANCED_ERROR_MESSAGE DEFAULT_ERROR_MESSAGE + \
    " " + NS_Utils::GetLastErrorAsString()

namespace NS_Utils
{
void parseCmdArgs(int argc, char *argv[]);
bool cmdArgContains(const string &param);
string cmdArgValue(const string &param);
string GetLastErrorAsString();
int ShowMessage(string str, bool showError = false);
//string GetSysLanguage();
string GetAppLanguage();
}

namespace NS_File
{
bool GetFilesList(const string &path, list<string> *lst, string &error, bool ignore_locked = false, bool folders_only = false);
bool readFile(const string &filePath, list<string> &linesList);
bool writeToFile(const string &filePath, list<string> &linesList);
bool runProcess(const string &fileName, const string &args);
bool isProcessRunning(const string &fileName);
bool fileExists(const string &filePath);
bool dirExists(const string &dirName);
bool dirIsEmpty(const string &dirName);
bool makePath(const string &path, size_t root_offset = 1);
bool replaceFile(const string &oldFilePath, const string &newFilePath);
bool replaceFolder(const string &from, const string &to, bool remove_existing = false);
bool removeFile(const string &filePath);
bool removeDirRecursively(const string &dir);
string parentPath(const string &path);
string tempPath();
string appPath();
string getFileHash(const string &fileName);
//bool verifyEmbeddedSignature(const string &fileName);
}

namespace NS_Logger
{
void AllowWriteLog();
void WriteLog(const string &log, bool showMessage = false);
}

#endif // UTILS_H
