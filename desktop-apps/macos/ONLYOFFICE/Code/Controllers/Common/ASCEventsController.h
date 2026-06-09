/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCEventsController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/23/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ASCEventsController : NSObject
+ (instancetype)sharedInstance;
+ (void)resetFullscreenState;
@end
