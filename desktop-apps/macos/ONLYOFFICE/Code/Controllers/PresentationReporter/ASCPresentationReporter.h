/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */
//
//  ASCPresentationReporter.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 10/16/17.
//  Copyright © 2017 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ASCPresentationReporter : NSObject
+ (instancetype)sharedInstance;

- (void)create:(void *)data from:(int)senderId;
- (void)destroy;
- (void)apply:(void *)event;
- (BOOL)isVisible;
@end
