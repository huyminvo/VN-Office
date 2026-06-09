/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCCommonViewController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/7/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ASCTabView.h"
#import "ASCTabsControl.h"
#import "NSCefView.h"

#define rootTabId @"1CEF624D-9FF3-432B-9967-61361B5BFE8B"

@interface ASCCommonViewController : NSViewController <NSTabViewDelegate>
- (BOOL)shouldCloseWindow;
- (BOOL)shouldCloseWindowIfNoTabs;

- (NSCefView *)cefViewWithTab:(ASCTabView *)tab;
- (ASCTabView *)tabViewWithId:(int)viewId;
- (ASCTabView *)tabWithParam:(NSString *)param value:(NSString *)value;
- (void)safeCloseTabsWithChanges;

- (void)openAcknowledgments;
- (void)openEULA;
- (void)openPreferences;

@property (weak) ASCTabsControl *tabsControl;
@property (weak) IBOutlet NSTabView *tabView;
@property (nonatomic) NSMutableArray<ASCTabView *> * tabsWithChanges;
@end
