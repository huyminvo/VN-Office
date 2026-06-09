/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCUserInfoViewController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/11/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SFBPopover.h"

@class ASCUserInfoViewController;

@protocol ASCUserInfoViewControllerDelegate  <NSObject>
@optional
- (void)onLogoutButton:(ASCUserInfoViewController *)controller;
@end

@interface ASCUserInfoViewController : NSViewController
@property (weak) IBOutlet NSTextField *userNameText;
@property (weak) IBOutlet NSTextField *portalText;
@property (weak) IBOutlet NSTextField *emailText;
@property (weak) SFBPopover * popover;
@property (nonatomic, assign) id <ASCUserInfoViewControllerDelegate> delegate;
@end
