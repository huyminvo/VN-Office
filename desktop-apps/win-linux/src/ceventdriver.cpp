/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#include "ceventdriver.h"
#include "cascapplicationmanagerwrapper.h"


CEventDriver::CEventDriver(QObject *parent)
    : QObject(parent)
{

}

//void CEventDriver::signal(edEventType t)
//{
//    switch (t) {
//    case edEventType::etModalOpen:
//    case edEventType::etModalClose:
////        emit onModalDialog(t == edEventType::etModalOpen);
//        break;
//    default: break;
//    }
//}

void CEventDriver::signal(CInAppEventBase * e)
{
    switch (e->type()) {
    case CInAppEventBase::CEventType::etModal: {
        const CInAppEventModal & _e = static_cast<const CInAppEventModal &>(*e);
        emit onModalDialog(!_e.finished(), _e.handle());
        break; }
    case CInAppEventBase::CEventType::etEditorClosed:
        emit onEditorClosed();
        break;
    default: break;
    }
}

CRunningEventHelper::CRunningEventHelper(CInAppRunnigEvent * e)
    : m_event(e)
{
    AscAppManager::getInstance().commonEvents().signal(m_event);
}

CRunningEventHelper::~CRunningEventHelper()
{
    m_event->setFinished(true);
    AscAppManager::getInstance().commonEvents().signal(m_event);
}
