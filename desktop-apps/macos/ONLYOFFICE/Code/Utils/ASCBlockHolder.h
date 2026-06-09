/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  ASCBlockHolder.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 4/28/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ASCBlockHolder : NSObject
@property (nonatomic, copy) void (^blockAction)(void);

- (instancetype)initWithBlock:(void (^)(void))block;
- (void)invoke:(id)sender;
@end
