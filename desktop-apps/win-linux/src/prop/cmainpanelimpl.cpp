/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the MIT License.
 *
*/

#include "cmainpanelimpl.h"
#include "cascapplicationmanagerwrapper.h"
#include "defines.h"
#include "utils.h"
#include "version.h"
#include "clangater.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

#define QCEF_CAST(Obj) qobject_cast<QCefView *>(Obj)

CMainPanelImpl::CMainPanelImpl(QWidget *parent, bool isCustomWindow, double scale)
    : CMainPanel(parent, isCustomWindow, scale)
{
    QObject::connect(CLangater::getInstance(), &CLangater::onLangChanged, std::bind(&CMainPanelImpl::refreshAboutVersion, this));
}

void CMainPanelImpl::refreshAboutVersion()
{
    QString _license = tr("Licensed under") + " &lt;a class=\"link\" onclick=\"window.open('" URL_LICENSE "')\" draggable=\"false\" href=\"#\"&gt;MIT License&lt;/a&gt;";

    QJsonObject _json_obj;
    _json_obj["version"]    = VER_FILEVERSION_STR;
#ifdef Q_OS_WIN
# ifdef Q_OS_WIN64
    _json_obj["arch"]       = "x64";
# else
    _json_obj["arch"]       = "x86";
# endif
#endif
    _json_obj["edition"]    = _license;
    _json_obj["appname"]    = WINDOW_NAME;
    _json_obj["rights"]     = ABOUT_COPYRIGHT_STR;
    _json_obj["link"]       = URL_SITE;
    _json_obj["changelog"]  = "https://github.com/huyminvo/VN-Office";

    QString _package = QSettings(qApp->applicationDirPath() + "/converter/package.config", QSettings::IniFormat).value("package").toString();
    if ( !_package.isEmpty() )
        _json_obj["pkg"] = _package;

    AscAppManager::sendCommandTo(SEND_TO_ALL_START_PAGE, "app:version", Utils::stringifyJson(_json_obj));

    _json_obj.empty();
    _json_obj.insert("locale",
        QJsonObject({
            {"current", CLangater::getCurrentLangCode()},
            {"langs", CLangater::availableLangsToJson()}
        })
    );

//    if ( AscAppManager::IsUseSystemScaling() ) {
//        _json_obj["uiscaling"] = 0;
//    } else {
        std::wstring _force_value = AscAppManager::userSettings(L"force-scale");
        if ( _force_value == L"1" )
            _json_obj["uiscaling"] = 100;
        else
        if ( _force_value == L"1.25" )
            _json_obj["uiscaling"] = 125;
        else
        if ( _force_value == L"1.5" )
            _json_obj["uiscaling"] = 150;
        else
        if ( _force_value == L"1.75" )
            _json_obj["uiscaling"] = 175;
        else
        if ( _force_value == L"2" )
            _json_obj["uiscaling"] = 200;
        else {
            _json_obj["uiscaling"] = 0;
//            AscAppManager::setUserSettings(L"force-scale", L"1");
//            _json_obj["uiscaling"] = 100;
        }
//    }

#ifndef __OS_WIN_XP
    _json_obj["uitheme"] = QString::fromStdWString(AscAppManager::themes().current().id());
#endif

#ifdef Q_OS_WIN
    _json_obj["spellcheckdetect"] = AscAppManager::userSettings(L"spell-check-input-mode") != L"0" ? "auto" : "off";
#endif

    GET_REGISTRY_USER(reg_user);
    _json_obj["editorwindowmode"] = reg_user.value("editorWindowMode",false).toBool();
#ifdef Q_OS_WIN
    _json_obj["updates"] = QJsonObject({{"mode", reg_user.value("autoUpdateMode","silent").toString()}});
#else
    _json_obj["updates"] = QJsonObject({{"interval", reg_user.value("checkUpdatesInterval","silent").toString()}});
#endif

    AscAppManager::sendCommandTo(SEND_TO_ALL_START_PAGE, "settings:init", Utils::stringifyJson(_json_obj));
    if ( InputArgs::contains(L"--ascdesktop-reveal-app-config") )
            AscAppManager::sendCommandTo( nullptr, "retrive:localoptions", "" );
}

void CMainPanelImpl::updateScaling(double dpiratio)
{
    CMainPanel::updateScaling(dpiratio);

    m_pButtonMain->setIcon(":/logo.svg", AscAppManager::themes().current().isDark() ? "logo-light" : "logo-dark");
    m_pButtonMain->setIconSize(QSize(85,20)*dpiratio);
}

void CMainPanelImpl::applyTheme(const std::wstring& theme)
{
    CMainPanel::applyTheme(theme);

    double dpiratio = scaling();
    m_pButtonMain->setIcon(":/logo.svg", AscAppManager::themes().current().isDark() ? "logo-light" : "logo-dark");
    m_pButtonMain->setIconSize(QSize(85,20)*dpiratio);
}

void CMainPanelImpl::onLocalOptions(const QString& json)
{
    QJsonParseError jerror;
    QJsonDocument jdoc = QJsonDocument::fromJson(json.toLatin1(), &jerror);

    if( jerror.error == QJsonParseError::NoError ) {
        QFile file(Utils::getAppCommonPath() + "/app.conf");
        file.open(QFile::WriteOnly);
        file.write(jdoc.toJson());
        file.close();
    }
}
