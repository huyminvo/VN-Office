/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "platform_linux/utils.h"
#include "classes/platform_linux/capplication.h"
#include "classes/platform_linux/ctimer.h"
#include "classes/csvcmanager.h"
#include "classes/translator.h"
#include "version.h"
#include "../../src/defines.h"
#include "../../src/prop/defines_p.h"
#include <csignal>
#include <cstring>
#include <locale>

#define DECL_VERSION __attribute__((section(".version_info"), unused))

volatile static const char DECL_VERSION version[] = VER_FILEVERSION_STR;
static const char gSvcVersion[] = "Service version: " VER_FILEVERSION_STR;

void strToNum(const char *str, int &num)
{
    char *err = NULL;
    int _num = strtol(str, &err, 10);
    if (!err || *err == '\0')
        num = _num;
}

int main(int argc, char *argv[])
{
    if (argc > 1) {
        if (strcmp(argv[1], "--run-as-app") == 0) {
            NS_Utils::parseCmdArgs(argc, argv);
            if (NS_Utils::cmdArgContains("--log")) {
                NS_Logger::AllowWriteLog();
                NS_Logger::WriteLog(gSvcVersion);
            }
            std::locale::global(std::locale(""));
            Translator::instance().init(NS_Utils::GetAppLanguage(), "/langs/langs.bin");
            CSocket socket(0, INSTANCE_SVC_PORT);
            if (!socket.isPrimaryInstance())
                return 0;

            int pid = -1;
            if (argc > 2)
                strToNum(argv[2], pid);

            CApplication app;
            CSvcManager upd;
            socket.onMessageReceived([&app, &pid](void *buff, size_t) {
                if (strcmp((const char*)buff, "stop") == 0)
                    app.exit(0);
                else
                    strToNum((const char*)buff, pid);
            });

            // Termination on crash of the main application
            CTimer tmr;
            tmr.start(30000, [&app, &pid]() {
                if (pid != -1 && kill(pid, 0) != 0)
                    app.exit(0);
            });
            return app.exec();
        }
    }

    return 0;
}
