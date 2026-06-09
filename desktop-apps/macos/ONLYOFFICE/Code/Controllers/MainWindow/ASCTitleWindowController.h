/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCTitleWindowController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/8/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ASCTitleBarController.h"

@interface ASCTitleWindowController : NSWindowController
- (BOOL)shouldPerformClose;
@property (nonatomic) ASCTitleBarController *titlebarController;
@end
