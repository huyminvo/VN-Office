/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCDownloadController.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/28/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import "ASCMulticastDelegate.h"

@class ASCDownloadController;

@protocol ASCDownloadControllerDelegate <NSObject>
@optional
- (void)downloadController:(ASCDownloadController *)controler didAddDownload:(id)download;
- (void)downloadController:(ASCDownloadController *)controler didRemovedDownload:(id)download;
- (void)downloadController:(ASCDownloadController *)controler didUpdatedDownload:(id)download;
@end

@interface ASCDownloadController : NSObject
@property (nonatomic, readonly) NSMutableArray * downloads;
@property (nonatomic, readonly) ASCMulticastDelegate *multicastDelegate;

+ (instancetype)sharedInstance;
- (id)downloadWithId:(NSString *)idx;
- (void)addDownload:(NSString *)idx fileName:(NSString *)fileName;
- (void)removeDownload:(NSString *)idx;
- (void)updateDownload:(NSString *)idx data:(NSValue *)data;

@end
