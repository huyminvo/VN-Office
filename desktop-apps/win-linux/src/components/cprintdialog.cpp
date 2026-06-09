/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "cprintdialog.h"


PageRanges::PageRanges(int _fromPage, int _toPage) :
    fromPage(_fromPage),
    toPage(_toPage)
{}

CPrintDialog::CPrintDialog(QPrinter *printer, QWidget *parent) :
    QPrintDialog(printer, parent),
    m_page_ranges(QVector<PageRanges>())
{

}

CPrintDialog::~CPrintDialog()
{

}

QVector<PageRanges> CPrintDialog::getPageRanges()
{
    if (!m_page_ranges.isEmpty())
        m_page_ranges.clear();
    m_page_ranges.append(PageRanges(fromPage(), toPage()));
    return m_page_ranges;
}
