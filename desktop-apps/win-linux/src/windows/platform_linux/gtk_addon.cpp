/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

/*#include "./gtk_addon.h"
#include <gtk/gtk.h>

namespace gtk_addon
{
    int devicePixelRatio()
    {
        GdkScreen* screen = gdk_screen_get_default();

        if (screen)
        {
            double dScale = gdk_screen_get_resolution(screen);
            if (dScale < 1)
                return 1;

            int wPx = gdk_screen_get_width(screen);
            int hPx = gdk_screen_get_height(screen);
            int wMm = gdk_screen_get_width_mm(screen);
            int hMm = gdk_screen_get_height_mm(screen);

            if (wMm < 1)
                wMm = 1;
            if (hMm < 1)
                hMm = 1;

            int nDpiX = (int)(0.5 + wPx * 25.4 / wMm);
            int nDpiY = (int)(0.5 + hPx * 25.4 / hMm);
            int nDpi = (nDpiX + nDpiY) >> 1;

            if (nDpi < 10)
                return 1;

            dScale /= nDpi;
            if (dScale < 1)
                return 1;
            else if (dScale > 2)
                return 2;
            else
                return (int)(dScale + 0.49);
        }
        return 1;
    }
}*/
