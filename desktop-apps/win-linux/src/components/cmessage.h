/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QString>


enum class MsgBtns {
    mbOk = 0,
    mbYesNo,
    mbYesDefNo,
    mbYesNoCancel,
    mbYesDefNoCancel,
    mbOkCancel,
    mbOkDefCancel,
    mbYesDefSkipNo,
    mbBuy,
    mbActivateDefContinue,
    mbContinue,
    mbSkipRemindInstall,
    mbSkipRemindSaveandinstall,
    mbSkipRemindDownload,
    mbInslaterRestart
};
enum class MsgType {
    MSG_INFO = 0,
    MSG_WARN,
    MSG_CONFIRM,
    MSG_ERROR,
    MSG_BRAND
};
enum MsgRes {
    MODAL_RESULT_CANCEL = 0,
    MODAL_RESULT_YES,
    MODAL_RESULT_NO,
    MODAL_RESULT_OK,
    MODAL_RESULT_SKIP,
    MODAL_RESULT_BUY,
    MODAL_RESULT_ACTIVATE,
    MODAL_RESULT_CONTINUE,
    MODAL_RESULT_SKIPVER,
    MODAL_RESULT_REMIND,
    MODAL_RESULT_DOWNLOAD,
    MODAL_RESULT_INSTALL,
    MODAL_RESULT_INSLATER,
    MODAL_RESULT_RESTART
};

struct CMessageOpts {
    bool *checkBoxState = nullptr;
    QString chekBoxText;
    QString contentText;
    QString linkText;
};

class QWidget;
namespace CMessage
{
int showMessage(QWidget *parent,
                const QString &msg,
                MsgType msgType,
                MsgBtns msgBtns = MsgBtns::mbOk,
                const CMessageOpts &opts = {});

void confirm(QWidget *parent, const QString &msg);
void info(QWidget *parent, const QString &msg);
void warning(QWidget *parent, const QString &msg);
void error(QWidget *parent, const QString &msg);
}

#endif // CMESSAGE_H
