/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  NSCefView.h
//  CefViewTest
//
//  Created by Oleg Korshul on 14.09.15.
//  Copyright (c) 2015 Ascensio System. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "applicationmanager.h"
#import "NSCefData.h"


@interface NSCefView : NSView
@property (nonatomic, strong) NSCefData *data;
@property (nonatomic, readonly) NSInteger uuid;

- (void)create:(CAscApplicationManager *)manager withType:(CefViewWrapperType)type;
- (void)apply:(NSEditorApi::CAscMenuEvent *)event;
- (void)setExternalCloud:(NSString *)provider;
- (void)setBackgroundColor:(NSColor *)color;
- (void)internalClean;
- (void)focus;
- (void)reload;
- (BOOL)checkCloudCryptoNeedBuild;
- (BOOL)checkBuilding;
- (NSString *)originalUrl;
- (BOOL)isSaveLocked;

- (void)loadWithUrl:(NSString *)url;
- (void)createFileWithName:(NSString *)name type:(AscEditorType)type;
- (void)createFileWithNameFromTemplate:(NSString *)name tplpath:(NSString *)path;
- (void)openFileWithName:(NSString *)name type:(NSInteger)type;
- (void)openRecentFileWithId:(NSInteger)index;
- (void)openRecoverFileWithId:(NSInteger)index;

- (void)createReporter:(CAscApplicationManager *)manager data:(void *)pData;

- (void)setParentWidgetInfoWithJson:(NSString *)jsonString;
- (void)sendCommand:(NSString *)command withParam:(NSString *)param;
@end
