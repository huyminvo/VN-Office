/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the MIT License.
 *
*/

#ifndef DEFINES_H
#define DEFINES_H

#define rePortalName        "^https?:\\/\\/(.+)"
#define reFileExtension     "\\.(\\w{1,10})$"
#define reUserName          "([^\\.]+)\\.?([^\\.]+)?"
#define reCmdLang           "--(keep)?lang[:|=](\\w{2,5})"

#define APP_NAME "DesktopEditors"
#define APP_TITLE "VN Office"
#ifdef __linux
# define APP_DATA_PATH "/vn-office/desktopeditors"
# define REG_GROUP_KEY "vn-office"
# define APP_MUTEX_NAME "vnoffice:editors"
# define DESKTOP_FILE_NAME "vnoffice-desktopeditors"
#else
# define APP_DATA_PATH "/VN Office/DesktopEditors"
# define APP_REG_NAME  "VN Office"
# define REG_GROUP_KEY "VN Office"
# define REG_UNINST_KEY "VN Office Desktop Editors"
# define APP_MUTEX_NAME "VNOFFICE"
#endif

#define WINDOW_NAME "VN Office"
#define WINDOW_TITLE WINDOW_NAME
#define WINDOW_CLASS_NAME L"DocEditorsWindowClass"
#define WINDOW_EDITOR_CLASS_NAME L"SingleWindowClass"
#define REG_APP_NAME "DesktopEditors"
#define APP_DEFAULT_LOCALE "en-US"
#define APP_DEFAULT_SYSTEM_LOCALE 1
#define APP_USER_MODEL_ID "HuyMin.VNOffice.1"
#define APP_SIMPLE_WINDOW_TITLE "VN Office Editor"
#define APP_PROTOCOL "vn-office"
#define FILE_PREFIX "vnoffice_"

#define URL_SITE                "https://github.com/huyminvo/VN-Office"
#define URL_SIGNUP              "https://github.com/huyminvo/VN-Office"

#define GET_REGISTRY_USER(variable) \
    QSettings variable(QSettings::NativeFormat, QSettings::UserScope, REG_GROUP_KEY, REG_APP_NAME);
#define GET_REGISTRY_SYSTEM(variable) \
    QSettings variable(QSettings::SystemScope, REG_GROUP_KEY, REG_APP_NAME);

#define LOCAL_PATH_OPEN         1
#define LOCAL_PATH_SAVE         2

#define ACTIONPANEL_CONNECT     255
#define ACTIONPANEL_ACTIVATE    ACTIONPANEL_CONNECT + 1

#define URL_LICENSE "https://opensource.org/license/mit"
#define DOWNLOAD_PAGE "https://github.com/huyminvo/VN-Office"
#define RELEASE_NOTES "https://github.com/huyminvo/VN-Office"

#ifdef __linux
typedef unsigned char BYTE;
#else
# define UM_INSTALL_UPDATE      WM_USER+254
#endif

#define UM_ENDMOVE (QEvent::User + 2)

#define TO_WSTR(str)            L ## str
#define WSTR(str)               TO_WSTR(str)

#ifdef __linux
# define VK_F1 0x70
# define VK_F4 0x73
# define VK_TAB 0x09
#endif

#define APP_PORT   12010
#define SVC_PORT   12011
#define INSTANCE_SVC_PORT 12012
#define INSTANCE_APP_PORT 13012

#define WARNING_LAUNCH_WITH_ADMIN_RIGHTS "App can't working correctly under admin rights."

#include "defines_p.h"

#endif // DEFINES_H

