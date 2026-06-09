/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef XCBUTILS_H
#define XCBUTILS_H

#include <xcb/xcb.h>
#include <vector>


namespace XcbUtils
{
void moveWindow(xcb_window_t window, int x, int y);
void setNativeFocusTo(xcb_window_t window);
bool isNativeFocus(xcb_window_t window);
void findWindowAsync(const char *window_name, void *user_data,
                     uint timeout_ms,
                     void(*callback)(xcb_window_t, void*));
void getWindowStack(std::vector<xcb_window_t> &winStack);
void setInputEnabled(xcb_window_t window, bool enabled);
}

#endif // XCBUTILS_H
