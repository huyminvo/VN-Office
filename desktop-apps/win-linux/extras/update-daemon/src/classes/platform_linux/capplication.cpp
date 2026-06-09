/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#include "capplication.h"
#include "platform_linux/utils.h"
#include "classes/translator.h"
#include <iostream>
#include <SDL2/SDL.h>


CApplication::CApplication()
{
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0)
        NS_Logger::WriteLog(_TR(MESSAGE_TEXT_ERR16) + _T(" ") + SDL_GetError(), true);
}

CApplication::~CApplication()
{
    SDL_Quit();
}

int CApplication::exec()
{
    int exit_code = 1;
    SDL_Event event;
    while (m_run && SDL_WaitEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit_code = event.user.code;
                break;
            default:
                break;
        }
    }
    return exit_code;
}

void CApplication::exit(int code)
{
    m_run = false;
    SDL_Event event;
    event.type = SDL_QUIT;
    event.user.code = code;
    SDL_PushEvent(&event);
}
