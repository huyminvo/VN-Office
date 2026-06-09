/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#include "cjson.h"
#include "cjson_p.h"
#include <codecvt>


static std::string TStrToUtf8(const tstring &str)
{
#ifdef _WIN32
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> utf8_conv;
    return utf8_conv.to_bytes(str);
#else
    return str;
#endif
}

class JsonObjectPrivate
{
public:
    json_object_s *obj = nullptr;
};

class JsonValuePrivate
{
public:
    json_value_s *val = nullptr;
};

class JsonDocumentPrivate
{
public:
    json_value_s *root = nullptr;
};


JsonValue::JsonValue() : pimpl(new JsonValuePrivate)
{}

JsonValue::JsonValue(const JsonValue &jval) : JsonValue()
{
    pimpl->val = jval.pimpl->val;
}

JsonValue::~JsonValue()
{
    delete pimpl, pimpl = nullptr;
}

JsonValue& JsonValue::operator=(const JsonValue &jval)
{
    if (this == &jval)
        return *this;
    pimpl->val = jval.pimpl->val;
    return *this;
}

JsonObject JsonValue::toObject()
{
    JsonObject jobj;
    if (pimpl->val && pimpl->val->type == json_type_object)
        jobj.pimpl->obj = (json_object_s*)pimpl->val->payload;
    return jobj;
}

tstring JsonValue::toTString()
{
    tstring str;
    if (pimpl->val && pimpl->val->type == json_type_string) {
        json_string_s *jstr = (json_string_s*)pimpl->val->payload;
#ifdef _WIN32
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        str = converter.from_bytes(std::string(jstr->string, jstr->string_size));
#else
        str = std::string(jstr->string, jstr->string_size);
#endif
    }
    return str;
}


JsonObject::JsonObject() : pimpl(new JsonObjectPrivate)
{}

JsonObject::JsonObject(const JsonObject &jobj) : JsonObject()
{
    pimpl->obj = jobj.pimpl->obj;
}

JsonObject::~JsonObject()
{
    delete pimpl, pimpl = nullptr;
}

JsonObject& JsonObject::operator=(const JsonObject &jobj)
{
    if (this == &jobj)
        return *this;
    pimpl->obj = jobj.pimpl->obj;
    return *this;
}

JsonValue JsonObject::value(const tstring &key)
{
    std::string utf8_key = TStrToUtf8(key);
    JsonValue jval;
    json_object_element_s *element;
    if (pimpl->obj && (element = pimpl->obj->start) != NULL) {
        do {
            if (strcmp(element->name->string, utf8_key.c_str()) == 0) {
                jval.pimpl->val = element->value;
                break;
            }
        } while ((element = element->next) != NULL);
    }
    return jval;
}

bool JsonObject::contains(const tstring &key)
{
    std::string utf8_key = TStrToUtf8(key);
    json_object_element_s *element;
    if (pimpl->obj && (element = pimpl->obj->start) != NULL) {
        do {
            if (strcmp(element->name->string, utf8_key.c_str()) == 0)
                return true;
        } while ((element = element->next) != NULL);
    }
    return false;
}


JsonDocument::JsonDocument() : pimpl(new JsonDocumentPrivate)
{}

JsonDocument::JsonDocument(const tstring &json) : JsonDocument()
{
    std::string utf8_json = TStrToUtf8(json);
    pimpl->root = json_parse(utf8_json.c_str(), utf8_json.length());
}

JsonDocument::~JsonDocument()
{
    if (pimpl->root)
        free(pimpl->root);
    delete pimpl, pimpl = nullptr;
}

JsonObject JsonDocument::object()
{
    JsonObject obj;
    if (pimpl->root && pimpl->root->type == json_type_object && pimpl->root->payload)
        obj.pimpl->obj = (json_object_s*)pimpl->root->payload;
    return obj;
}
