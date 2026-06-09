/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#ifndef GTKUTILS_H
#define GTKUTILS_H

#include <gtk/gtk.h>


typedef struct DialogTag {
    GtkWidget* dialog;
    ulong parent_xid;
} DialogTag;

gboolean set_focus(GtkWidget *dialog);
gboolean focus_out(gpointer data);
void set_parent(GtkWidget *dialog, gpointer data);
void add_to_recent(const gchar *uri);
GtkWidget *find_widget_by_path(GtkWidget *parent, const gchar *widget_path);

#endif // GTKUTILS_H
