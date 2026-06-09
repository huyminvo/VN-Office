/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CPRINTDATA_H
#define CPRINTDATA_H

#include "applicationmanager_events.h"
#include "components/cprintdialog.h"
#include <QPrinterInfo>
#include <QPrintDialog>
#include <functional>

typedef std::function<void(const QString&)> FnVoidStr;


class CPrintData
{
public:
    explicit CPrintData();
    ~CPrintData();

    auto init(NSEditorApi::CAscPrintEnd *) -> void;
    auto init(int, NSEditorApi::CAscPrintEnd *) -> void;
    auto printerInfo() const -> QPrinterInfo;
    auto setAppDataPath(const std::wstring&) -> void;
    auto setPrinterInfo(const QPrinterInfo&) -> void;
    auto setPrinterInfo(const QPrinter&) -> void;
    auto pageSize() const -> QPageSize;
    auto pageOrientation() const -> QPageLayout::Orientation;
    auto pagesCount() const -> int;
    auto pageCurrent() const -> int;
    auto pageFrom() const -> int;
    auto pageTo() const -> int;
    auto pageRanges() const -> QVector<PageRanges>;
    auto printRange() const -> QPrintDialog::PrintRange;
    auto isQuickPrint() const -> bool;
    auto useSystemDialog() const -> bool;
    auto colorMode() const -> bool;
    auto viewId() const -> int;
    auto copiesCount() const -> int;
    auto duplexMode() const -> QPrinter::DuplexMode;
    auto printerCapabilitiesReady() const -> bool;
    auto getPrinterCapabilitiesJson() const -> QString;
    auto queryPrinterCapabilitiesAsync(const FnVoidStr &callback) const -> void;

private:
    class CPrintDataPrivate;
    CPrintDataPrivate * m_priv;
};

#endif // CPRINTDATA_H
