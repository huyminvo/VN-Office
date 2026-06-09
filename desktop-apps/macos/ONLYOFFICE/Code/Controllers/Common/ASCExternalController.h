/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  ASCExternalController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 18/09/2018.
//  Copyright © 2018 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ASCExternalDelegate <NSObject>
@optional
- (NSString *)onApplicationName;
- (NSString *)onApplicationNameShort;
- (NSString *)onAppInfo:(NSString *)key;
- (NSString *)onAppPreferredLanguage;
- (NSString *)onCommercialInfo;
- (BOOL)onShouldOpenFile:(NSString *)filePath;
- (void)onMainWindowLoaded:(id)controller;
- (void)onCommonViewDidLoad:(id)controller;
- (void)onCefMenuEvent:(void *)event;
@end

@interface ASCExternalController : NSObject
@property (nonatomic, assign) id <ASCExternalDelegate> delegate;
+ (instancetype)shared;
@end

NS_ASSUME_NONNULL_END
