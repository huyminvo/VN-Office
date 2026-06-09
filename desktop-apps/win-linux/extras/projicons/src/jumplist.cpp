/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#define NTDDI_VERSION NTDDI_WIN7
#define WIN32_LEAN_AND_MEAN
#define STRICT_TYPED_ITEMIDS
#define MAX_TASK_NUM 4
#define ICON_OFFSET 14

#include "jumplist.h"
#include "resource.h"
#include <QtGlobal>
#include <Windows.h>
#include <psapi.h>
#include <shlwapi.h>
#include <strsafe.h>

#include <objectarray.h>
#include <shobjidl.h>
#include <propkey.h>
#include <propvarutil.h>
#include <shlobj.h>


HRESULT _CreateShellLink(PCWSTR pszArguments, PCWSTR pszTitle, IShellLink **ppsl, int index)
{
    WCHAR szAppPath[MAX_PATH];
    if (GetModuleFileName(NULL, szAppPath, ARRAYSIZE(szAppPath)) == 0)
        return HRESULT_FROM_WIN32(GetLastError());

    IShellLink *psl;
    HRESULT hr = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&psl));
    if (SUCCEEDED(hr))
    {
            hr = psl->SetPath(szAppPath);
            if (SUCCEEDED(hr))
            {
                hr = psl->SetArguments(pszArguments);
                if (SUCCEEDED(hr))
                {
                    hr = psl->SetIconLocation(szAppPath, index + ICON_OFFSET);
                    Q_UNUSED(hr);
                    IPropertyStore *pps;
                    hr = psl->QueryInterface(IID_PPV_ARGS(&pps));
                    if (SUCCEEDED(hr))
                    {
                        PROPVARIANT propvar;
                        hr = InitPropVariantFromString(pszTitle, &propvar);
                        if (SUCCEEDED(hr))
                        {
                            hr = pps->SetValue(PKEY_Title, propvar);
                            if (SUCCEEDED(hr))
                            {
                                hr = pps->Commit();
                                if (SUCCEEDED(hr))
                                {
                                    hr = psl->QueryInterface(IID_PPV_ARGS(ppsl));
                                }
                            }
                            PropVariantClear(&propvar);
                        }
                        pps->Release();
                    }
                }
            }
        psl->Release();
    }
    return hr;
}

HRESULT _AddTasksToList(ICustomDestinationList *pcdl)
{
    WCHAR szAppPath[MAX_PATH];
    if (GetModuleFileName(NULL, szAppPath, ARRAYSIZE(szAppPath)) == 0)
        return HRESULT_FROM_WIN32(GetLastError());

    IObjectCollection *poc;
    HRESULT hr = CoCreateInstance(CLSID_EnumerableObjectCollection, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&poc));
    if (SUCCEEDED(hr))
    {
        struct {
            PCWSTR arg;
            int stringId;
        }
        tasks[MAX_TASK_NUM] = {
            {L"--new:word",  IDS_JUMP_DOCX},
            {L"--new:cell",  IDS_JUMP_XLSX},
            {L"--new:slide", IDS_JUMP_PPTX},
            {L"--new:form",  IDS_NEW_PDF},
        };

        IShellLink * psl;
        for (int i = 0; i < MAX_TASK_NUM; i++) {
            WCHAR szResPath[MAX_PATH];
            swprintf_s(szResPath, ARRAYSIZE(szResPath), L"@%s,-%d", szAppPath, tasks[i].stringId);

            hr = _CreateShellLink(tasks[i].arg, szResPath, &psl, i);
            if (SUCCEEDED(hr))
            {
                hr = poc->AddObject(psl);
                psl->Release();
            }
        }

        if (SUCCEEDED(hr))
        {
            IObjectArray * poa;
            hr = poc->QueryInterface(IID_PPV_ARGS(&poa));
            if (SUCCEEDED(hr))
            {
                hr = pcdl->AddUserTasks(poa);
                poa->Release();
            }
        }
        poc->Release();
    }
    return hr;
}

void CreateJumpList()
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr))
    {
        ICustomDestinationList *pcdl;
        hr = CoCreateInstance(CLSID_DestinationList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pcdl));
        if (SUCCEEDED(hr)) {
            pcdl->SetAppID(TEXT(APP_USER_MODEL_ID));
            UINT cMinSlots;
            IObjectArray *poaRemoved;
            hr = pcdl->BeginList(&cMinSlots, IID_PPV_ARGS(&poaRemoved));
            if (SUCCEEDED(hr)) {
                hr = _AddTasksToList(pcdl);
                if (SUCCEEDED(hr))
                    hr = pcdl->CommitList();
                poaRemoved->Release();
            }
            pcdl->Release();
        }
        CoUninitialize();
    }
    Q_UNUSED(hr);
}

void DeleteJumpList()
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr))
    {
        ICustomDestinationList *pcdl;
        hr = CoCreateInstance(CLSID_DestinationList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pcdl));
        if (SUCCEEDED(hr)) {
            hr = pcdl->DeleteList(NULL);
            pcdl->Release();
        }
        CoUninitialize();
    }
    Q_UNUSED(hr);
}

void ClearHistory()
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr))
    {
        IApplicationDestinations *pad;
        hr = CoCreateInstance(CLSID_ApplicationDestinations, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pad));
        if (SUCCEEDED(hr)) {
            hr = pad->RemoveAllDestinations();
            pad->Release();
        }
        CoUninitialize();
    }
    Q_UNUSED(hr);
}
