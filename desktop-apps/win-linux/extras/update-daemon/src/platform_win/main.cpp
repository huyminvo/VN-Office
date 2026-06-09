/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include <locale>
#include "utils.h"
#include "platform_win/resource.h"
#include "platform_win/svccontrol.h"
#include "classes/platform_win/capplication.h"
#include "classes/platform_win/ctimer.h"
#include "classes/csvcmanager.h"
#include "classes/translator.h"
#include "../../src/defines.h"
#include "../../src/prop/defines_p.h"

SERVICE_STATUS          gSvcStatus;
SERVICE_STATUS_HANDLE   gSvcStatusHandle;
HANDLE                  gSvcStopEvent = NULL;
static const WCHAR      gSvcVersion[] = _T("Service version: " VER_FILEVERSION_STR);


VOID WINAPI SvcMain(DWORD argc, LPTSTR *argv);
VOID WINAPI SvcCtrlHandler(DWORD dwCtrl);
VOID ReportSvcStatus(DWORD, DWORD, DWORD);
BOOL EnableRedirectionTrustPolicy();

int __cdecl _tmain (int argc, TCHAR *argv[])
{
    if (argc > 1) {
        if (lstrcmpi(argv[1], _T("--install")) == 0) {
            SvcControl::SvcInstall();
            if (argc > 2)
                SvcControl::DoUpdateSvcDesc(argv[2]);
            SvcControl::DoStartSvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--delete")) == 0) {
            SvcControl::DoStopSvc();
            SvcControl::DoDeleteSvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--start")) == 0) {
            SvcControl::DoStartSvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--stop")) == 0) {
            SvcControl::DoStopSvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--enable")) == 0) {
            SvcControl::DoEnableSvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--disable")) == 0) {
            SvcControl::DoDisableSvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--description")) == 0) {
            if (argc > 2)
                SvcControl::DoUpdateSvcDesc(argv[2]);
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--info")) == 0) {
            NS_Utils::setRunAsApp();
            SvcControl::DoQuerySvc();
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--update_dacl")) == 0) {
            //SvcControl::DoUpdateSvcDacl(pTrusteeName);
            return 0;
        } else
        if (lstrcmpi(argv[1], _T("--run-as-app")) == 0) {
            NS_Utils::setRunAsApp();
            NS_Utils::parseCmdArgs(argc, argv);
            if (NS_Utils::cmdArgContains(_T("--log"))) {
                NS_Logger::AllowWriteLog();
                NS_Logger::WriteLog(gSvcVersion);
            }
            std::locale::global(std::locale(""));
            Translator::instance().init(NS_Utils::GetAppLanguage().c_str(), IDT_TRANSLATIONS);
            CSocket socket(0, INSTANCE_SVC_PORT);
            if (!socket.isPrimaryInstance())
                return 0;

            int pid = -1;
            if (argc > 2) {
                wchar_t *err = NULL;
                int _pid = wcstol(argv[2], &err, 10);
                if (!err || *err == L'\0')
                    pid = _pid;
            }

            CApplication app;
            CSvcManager upd;
            socket.onMessageReceived([&app, &pid](void *buff, size_t) {
                if (strcmp((const char*)buff, "stop") == 0)
                    app.exit(0);
                else {
                    char *err = NULL;
                    int _pid = strtol((const char*)buff, &err, 10);
                    if (!err || *err == '\0')
                        pid = _pid;
                }
            });

            // Termination on crash of the main application
            CTimer tmr;
            tmr.start(30000, [&app, &pid]() {
                if (pid > 0) {
                    HANDLE procHandle = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);
                    if (procHandle)
                        CloseHandle(procHandle);
                    else
                        app.exit(0);
                }
            });
            return app.exec();
        }
    }

    std::locale::global(std::locale(""));
    Translator::instance().init(NS_Utils::GetAppLanguage().c_str(), IDT_TRANSLATIONS);
    SERVICE_TABLE_ENTRY DispatchTable[] =
    {
        {(LPTSTR)SERVICE_NAME, (LPSERVICE_MAIN_FUNCTION)SvcMain},
        {NULL, NULL}
    };

    if (StartServiceCtrlDispatcher(DispatchTable) == 0) {
       NS_Utils::ShowMessage(_TR(MESSAGE_TEXT_ERR17) + _T(" ") + NS_Utils::GetLastErrorAsString(), true);
       return GetLastError();
    }

    return 0;
}

VOID WINAPI SvcMain(DWORD argc, LPTSTR *argv)
{
    NS_Utils::parseCmdArgs(argc, argv);
    if (NS_Utils::cmdArgContains(_T("--log"))) {
        NS_Logger::AllowWriteLog();
        NS_Logger::WriteLog(gSvcVersion);
    }

    gSvcStatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, SvcCtrlHandler);
    if (gSvcStatusHandle == NULL) {
        wstring err(ADVANCED_ERROR_MESSAGE);
        SvcControl::SvcReportEvent(err.c_str());
        return;
    }

    // Tell the service controller we are starting
    ZeroMemory(&gSvcStatus, sizeof(gSvcStatus));
    gSvcStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
    gSvcStatus.dwServiceSpecificExitCode = 0;
    ReportSvcStatus(SERVICE_START_PENDING, NO_ERROR, 3000);

    // TO_DO: Declare and set any required variables.
    //   Be sure to periodically call ReportSvcStatus() with
    //   SERVICE_START_PENDING. If initialization fails, call
    //   ReportSvcStatus with SERVICE_STOPPED.
    //   Create an event. The control handler function, SvcCtrlHandler,
    //   signals this event when it receives the stop control code.
    gSvcStopEvent = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (gSvcStopEvent == NULL) {
        ReportSvcStatus(SERVICE_STOPPED, GetLastError(), 0);
        wstring err(ADVANCED_ERROR_MESSAGE);
        SvcControl::SvcReportEvent(err.c_str());
        return;
    }

    // Report running status when initialization is complete.
    ReportSvcStatus(SERVICE_RUNNING, NO_ERROR, 0);

    // Prevent the process from following filesystem junctions
    // created by non-admin users.
    if (!EnableRedirectionTrustPolicy())
        NS_Logger::WriteLog(_T("Failed to set redirection trust policy: ") + NS_Utils::GetLastErrorAsString());

    CSvcManager upd;
    upd.aboutToQuit([]() {
        ReportSvcStatus(SERVICE_STOPPED, NO_ERROR, 0);
    });
    WaitForSingleObject(gSvcStopEvent, INFINITE);
    CloseHandle(gSvcStopEvent);
}

VOID WINAPI SvcCtrlHandler(DWORD dwCtrl)
{
    switch (dwCtrl) {
    case SERVICE_CONTROL_STOP:
        ReportSvcStatus(SERVICE_STOP_PENDING, NO_ERROR, 0);
        // Signal the service to stop.
        SetEvent(gSvcStopEvent);
        ReportSvcStatus(gSvcStatus.dwCurrentState, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_INTERROGATE:
        break;

    default:
        break;
    }
}

VOID ReportSvcStatus(DWORD currState, DWORD exitCode, DWORD waitHint)
{
    static DWORD dwCheckPoint = 1;

    gSvcStatus.dwCurrentState = currState;
    gSvcStatus.dwWin32ExitCode = exitCode;
    gSvcStatus.dwWaitHint = waitHint;

    if (currState == SERVICE_START_PENDING)
        gSvcStatus.dwControlsAccepted = 0;
    else
        gSvcStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;

    if ((currState == SERVICE_RUNNING) ||
            (currState == SERVICE_STOPPED))
        gSvcStatus.dwCheckPoint = 0;
    else
        gSvcStatus.dwCheckPoint = dwCheckPoint++;

    // Report the status of the service to the SCM.
    if (SetServiceStatus(gSvcStatusHandle, &gSvcStatus) == FALSE) {
        wstring err(ADVANCED_ERROR_MESSAGE);
        SvcControl::SvcReportEvent(err.c_str());
    }
}

BOOL EnableRedirectionTrustPolicy()
{
    BOOL(WINAPI *_SetProcessMitigationPolicy)(PROCESS_MITIGATION_POLICY, PVOID, SIZE_T) = NULL;
    if (HMODULE module = GetModuleHandleA("kernel32"))
        *(FARPROC*)&_SetProcessMitigationPolicy = GetProcAddress(module, "SetProcessMitigationPolicy");

    PROCESS_MITIGATION_REDIRECTION_TRUST_POLICY policy = {0};
    policy.EnforceRedirectionTrust = 1;
    return _SetProcessMitigationPolicy ? _SetProcessMitigationPolicy(ProcessRedirectionTrustPolicy, &policy, sizeof(policy)) : FALSE;
}
