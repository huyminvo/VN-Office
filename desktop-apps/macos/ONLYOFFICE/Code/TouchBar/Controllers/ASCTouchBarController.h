/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  ASCTouchBarController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 02/01/2019.
//  Copyright (c) 2019 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ASCTabTouchBar.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ASCTouchBarTapBlock)(id sender, NSString *senderId);

static NSString * const kCreationButtonIdentifier  = @"com.onlyoffice.touchbar.button.new.%@";
static NSString * const kStartPageButtonIdentifier = @"com.onlyoffice.touchbar.button.startpage";

@interface ASCTouchBarController : NSObject

@property (nonatomic) NSMutableArray<ASCTabTouchBar *> *tabs;
@property (nonatomic) NSInteger selectedIndex;
@property (nonatomic, copy) ASCTouchBarTapBlock onItemTap;

- (instancetype)init:(NSViewController *)viewController;
- (void)invalidateTouchBar;
- (NSTouchBar *)makeTouchBar;

@end

NS_ASSUME_NONNULL_END
