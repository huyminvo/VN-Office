/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "chelp.h"
#include <stdio.h>
#ifdef _WIN32
# include <Windows.h>
#endif


CHelp::CHelp()
{

}

void CHelp::out()
{
    const char help[] =
        "\n\n"
        "Desktop editors for cloud portal.\n"
        "\n"
        "keys:\n"
        "    --custom-title-bar turns off system title bar\n"
        "    --system-title-bar turns on system title bar\n"
        "    --keeplang=en keeps the language\n"
        "    --lang=en applies the language for the current session\n"
        "    --new=[doc|cell|slide] creates new document/spreadsheet/presentation\n"
        "    --review=path/to/file to open document in review mode in separate window\n"
        "    --view=path/to/file to open document in view mode in separate window\n"
        "    --force-use-tab document will be opend in new tab instead of new separate window\n"
        "    --geometry=default reset window geometry\n"
        "    --xdg-desktop-portal use portals instead of gtk file chooser (the flag is saved for subsequent sessions)\n"
        "    --xdg-desktop-portal=default use portals instead of gtk file chooser for current session\n"
        "    --native-file-dialog use non Qt dialog\n"
        "    --lock-portals force hide the Connect to the cloud button on the start page"
        "    --unlock-portals disable forced hiding of the Connect to the cloud button on the start page"
        "    --updates-appcast-channel=dev set development URL for updates\n"
        "    --updates-interval=<time> set update check interval in seconds (minimum 30 sec)\n"
        "    --updates-reset reset all update options\n";

#ifdef _WIN32
    FILE *pFile = NULL;
    if (AttachConsole(ATTACH_PARENT_PROCESS))
        freopen_s(&pFile, "CONOUT$", "w", stdout);
#endif
    fprintf(stdout, help);
    fflush(stdout);
#ifdef _WIN32
    if (pFile)
        fclose(pFile);
#endif
}
