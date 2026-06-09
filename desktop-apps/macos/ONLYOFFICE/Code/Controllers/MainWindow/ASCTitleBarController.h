/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCTitleBarController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/8/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ASCTabsControl.h"

@protocol ASCTitleBarControllerDelegate <NSObject>
@optional
- (void)onOnlyofficeButton:(id)sender;
- (void)onShowUserInfoController:(NSViewController *)controller;
@end

@interface ASCTitleBarController : NSViewController
- (void)attachEditor:(NSView *)cefView atScreenPoint:(NSPoint)screenPoint;
- (BOOL)canPinTabAtPoint:(NSPoint)screenPoint;
@property (weak) IBOutlet ASCTabsControl *tabsControl;

@property (nonatomic, assign) id <ASCTitleBarControllerDelegate> delegate;
@end
