/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCApplicationManager.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 10/2/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#ifndef ASCApplicationManager_h
#define ASCApplicationManager_h

#include <stdio.h>
#import "mac_application.h"

class ASCApplicationManager : public CAscApplicationManager {
public:
    ASCApplicationManager();
    
    virtual void StartSaveDialog(const std::wstring& sName, unsigned int nId);
    virtual void EndSaveDialog(const std::wstring& sPath, unsigned int nId);
};

#endif /* ASCApplicationManager_h */
