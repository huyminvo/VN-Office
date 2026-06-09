/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CEDITORTOOLS_H
#define CEDITORTOOLS_H

#include "qascprinter.h"
#include "cascapplicationmanagerwrapper.h"
#include "components/cprintdialog.h"

namespace CEditorTools
{
    struct sPrintConf
    {
        sPrintConf(CCefView * v, QAscPrinterContext * c, QVector<PageRanges> *ranges, ParentHandle p)
            : view(v)
            , context(c)
            , page_ranges(ranges)
            , parent(p)
        {}

        CCefView * view;
        QAscPrinterContext * context;
        QVector<PageRanges> *page_ranges;
        ParentHandle parent;
    };

    void print(const sPrintConf&);
    void onDocumentPrint(QWidget *parent, CCefView *pView, const QString &documentName, int currentPage, int pagesCount);
    void getlocalfile(void * data);
    QString getlocalfile(const std::wstring& path, int parentid = -1);
    QString getlocaltemplate(const std::wstring& editor, int parentid);
    QString getlocaltheme(int parentid);
    std::wstring getFolder(const std::wstring&, int parentid = -1);

    auto createEditorPanel(const COpenOptions& opts, QWidget *parent = nullptr) -> CTabPanel *;
    auto editorTypeFromFormat(int format) -> AscEditorType;
    auto processLocalFileSaveAs(const NSEditorApi::CAscCefMenuEvent * event) -> void;
}

#endif // CEDITORTOOLS_H
