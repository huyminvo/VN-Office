; -- VN Office Desktop Editors Defines --

#define sCompanyName                    "VN Office"
#define sIntCompanyName                 sCompanyName
#define sProductName                    "Desktop Editors"
#define sIntProductName                 "DesktopEditors"
#define sAppName                        str(sCompanyName)
#define sPackageName                    str(sIntCompanyName + "-" + sIntProductName)
#define sAppPublisher                   "HuyMin"
#define sAppPublisherURL                "https://www.facebook.com/huymin222/"
#define sAppSupportURL                  "https://github.com/huyminvo/VN-Office"
#define sAppCopyright                   str("(C) HuyMin " + GetDateTimeString("yyyy",,) + ". All rights reserved.")
#define sAppIconName                    "VN Office"
#define sOldAppIconName                 "VN Office Editors"
#define sAppProtocol                    'vn-office'

#define APP_PATH                        str(sIntCompanyName + "\" + sIntProductName)
#define UPD_PATH                        str(sIntProductName + "Updates")
#define APP_REG_PATH                    str("Software\" + APP_PATH)
#define APP_REG_UNINST_KEY              str(sCompanyName + " " + sProductName)
#define APP_USER_MODEL_ID               "HuyMin.VNOffice.1"
#define APP_MUTEX_NAME                  "VNOFFICE"
#define APPWND_CLASS_NAME               "DocEditorsWindowClass"

#define iconsExe                        "DesktopEditors.exe"
#define NAME_EXE_OUT                    "editors.exe"

#define ASSC_APP_NAME                   "VN Office"
#define ASCC_REG_PREFIX                 "VNOFFICE"
#define ASCC_REG_REGISTERED_APP_NAME    "VN Office Editors"
#define ASSOC_PROG_ID                   "VNOffice.Editors"
#define ASSOC_APP_FRIENDLY_NAME         "VN Office Editors"
