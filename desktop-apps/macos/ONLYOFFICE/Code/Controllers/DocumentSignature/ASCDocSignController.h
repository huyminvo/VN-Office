/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  ASCDocSignController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 17/04/2018.
//  Copyright © 2018 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "applicationmanager.h"

@interface ASCDocSignController : NSObject

@property (nonatomic) NSString * signFilePath;
@property (nonatomic) NSString * signPassword;
@property (nonatomic) NSString * privateKeyFilePath;
@property (nonatomic) NSString * privateKeyPassword;
@property (nonatomic, readonly) NSInteger cefId;

+ (instancetype)shared;
- (void)startWizardWithCefId:(NSString *)cefId;

@end
