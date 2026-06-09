/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef QASCAPPLICATIONMANAGER
#define QASCAPPLICATIONMANAGER

#include "../../lib/include/cefapplication.h"
#include "../../lib/include/applicationmanager.h"

#include <QFileDialog>
#include "qmainpanel.h"

class CMyApplicationManager : public CAscApplicationManager
{
private:
    QMainPanel * m_pPanel;

public:
    CMyApplicationManager()
    {
        m_pPanel = NULL;
        qRegisterMetaType<std::wstring>("std::wstring");
    }

public:
    void setMainPanel(QMainPanel * panel)
    {
        m_pPanel = panel;
    }

    virtual void StartSaveDialog(const std::wstring& sName)
    {
        // сделал через QMainPanel - чтобы использовать сигналы-слоты.
        // если сделать QAscApplicationManager : public QObject, то он будет прокидывать
        // слоты родителю. Т.е. классу CAscApplicationManager.
        // А в либе я не буду затачиваться на QT

//        ((QMainPanel*)m_pPanel)->sendDialogSave(sName);
        QMetaObject::invokeMethod(m_pPanel, "onDialogSave", Qt::QueuedConnection, Q_ARG(std::wstring, sName));
    }
};

#endif // QASCAPPLICATIONMANAGER

