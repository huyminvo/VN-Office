/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  ASCTabTouchBarItem.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 02/01/2019.
//  Copyright (c) 2019 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ASCTabTouchBar;

NS_ASSUME_NONNULL_BEGIN

@interface ASCTabTouchBarItem : NSScrubberItemView
@property (nonatomic) ASCTabTouchBar *tabInfo;
@end

NS_ASSUME_NONNULL_END
