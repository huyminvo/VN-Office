/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "cproviders.h"
#include <QVector>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>


struct ProviderData {
    QString provider, editorPage;
    bool hasFrame = false,
         useRegex = false;
};

class CProviders::CProvidersPrivate
{
public:
    QVector<ProviderData> m_provid_vec;
};

CProviders::CProviders() :
    pimpl(new CProvidersPrivate)
{}

CProviders::~CProviders()
{
    delete pimpl, pimpl = nullptr;
}

CProviders& CProviders::instance()
{
    static CProviders inst;
    return inst;
}

void CProviders::init(const QString &prvds_json)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(prvds_json.toUtf8(), &err);
    if (err.error == QJsonParseError::NoError) {
        const QJsonArray arr = doc.array();
        for (const auto &val : arr) {
            QJsonObject obj = val.toObject();
            ProviderData pd;
            pd.provider = obj["provider"].toString().toLower();
            pd.hasFrame = obj["editorFrameSize"].toString() == "finite";
            pd.editorPage = obj["editorPage"].toString();
            QString reg("regex:");
            int ind = pd.editorPage.indexOf(reg);
            if (ind != -1) {
                pd.useRegex = true;
                pd.editorPage = pd.editorPage.mid(ind + reg.length());
            }
            pimpl->m_provid_vec.push_back(std::move(pd));
        }
    }
}

bool CProviders::editorsHasFrame(const QString &url, const QString &cloud)
{
    foreach (const auto &pd, pimpl->m_provid_vec) {
        if (!pd.provider.isEmpty() && pd.provider == cloud)
            return pd.hasFrame;
        if (!pd.editorPage.isEmpty()) {
            if (pd.useRegex) {
                QRegularExpression rgx(pd.editorPage, QRegularExpression::CaseInsensitiveOption);
                if (rgx.match(url).hasMatch())
                    return pd.hasFrame;
            } else
            if (url.indexOf(pd.editorPage) != -1)
                return pd.hasFrame;
        }
    }
    return false;
}
