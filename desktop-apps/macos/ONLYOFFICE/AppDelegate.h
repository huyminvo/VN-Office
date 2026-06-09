/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  AppDelegate.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/7/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "mac_application.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>
- (BOOL)shouldTerminateApplication;
- (void)safeCloseEditorWindows;
- (void)presentMainWindow;
- (void)dragDetachedTab:(NSView *)cefView atScreenPoint:(NSPoint)screenPoint withEvent:(NSEvent *)event;

@property (nonatomic) BOOL waitingForTerminateApp;
@property (nonatomic) NSWindowController *mainWindowController;
@property (nonatomic) NSMutableArray *editorWindowControllers;
@property (nonatomic) NSUInteger documentNameCounter;
@property (nonatomic) NSUInteger spreadsheetNameCounter;
@property (nonatomic) NSUInteger presentationNameCounter;
@property (nonatomic) NSUInteger pdfNameCounter;
@end

