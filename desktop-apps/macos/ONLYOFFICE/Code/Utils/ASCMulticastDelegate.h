/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCMulticastDelegate.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/28/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ASCMulticastDelegate : NSObject
- (void)addDelegate:(id)delegate;
- (void)removeDelegate:(id)delegate;
@end
