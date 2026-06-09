/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CPRINTDIALOG_H
#define CPRINTDIALOG_H

#include <QPrinter>
#include <QPrintDialog>
#include <QWidget>


struct PageRanges
{
    PageRanges(int _fromPage = -1, int _toPage = -1);
    int fromPage;
    int toPage;
};

class CPrintDialog: public QPrintDialog
{
public:
    CPrintDialog(QPrinter *printer, QWidget *parent);
    ~CPrintDialog();
    QVector<PageRanges> getPageRanges();

private:
    QVector<PageRanges> m_page_ranges;
};

#endif // CPRINTDIALOG_H
