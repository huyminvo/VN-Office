/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef CJSON_H
#define CJSON_H

#include <string>
#ifdef _WIN32
# include <tchar.h>
# define tstring std::wstring
#else
# define _T(str) str
# define tstring std::string
#endif

class JsonObject;
class JsonObjectPrivate;
class JsonValuePrivate;
class JsonDocumentPrivate;

class JsonValue
{
public:
    JsonValue();
    JsonValue(const JsonValue&);
    ~JsonValue();

    JsonValue& operator=(const JsonValue&);
    JsonObject toObject();
    tstring toTString();

private:
    friend class JsonObject;
    JsonValuePrivate *pimpl;
};

class JsonObject
{
public:
    JsonObject();
    JsonObject(const JsonObject&);
    ~JsonObject();

    JsonObject& operator=(const JsonObject&);
    JsonValue value(const tstring&);
    bool contains(const tstring&);

private:
    friend class JsonDocument;
    friend class JsonValue;
    JsonObjectPrivate *pimpl;
};

class JsonDocument
{
public:
    JsonDocument(const tstring&);
    ~JsonDocument();

    JsonObject object();

private:
    JsonDocument();
    JsonDocumentPrivate *pimpl;
};

#endif // CJSON_H
