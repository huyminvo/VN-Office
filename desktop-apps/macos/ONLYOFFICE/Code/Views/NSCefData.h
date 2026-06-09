/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  NSCefData.h
//
//  Copyright (c) 2025 Ascensio System. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "cefview.h"

@interface NSCefData : NSObject
-(instancetype)initWith:(NSString *)title viewType:(CefViewWrapperType)type;
-(instancetype)initWith:(NSString *)title contentType:(AscEditorType)type;

-(NSString *)title:(BOOL)orig;
-(NSString *)features;
-(CefViewWrapperType)viewType;
-(BOOL)isViewType:(CefViewWrapperType)viewType;
-(BOOL)hasFeature:(NSString *)feature;
-(BOOL)hasFrame;
-(BOOL)modified;
-(BOOL)hasChanges;
-(BOOL)closed;
-(void)setFeatures:(NSString *)features;
-(void)setChanged:(BOOL)changed;
-(void)close;
-(void)reuse;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *cloudName;
@property (nonatomic, assign) AscEditorType contentType;
@property (nonatomic, assign) BOOL isLocal;
@property (nonatomic, assign) BOOL hasError;
@property (nonatomic, assign) BOOL eventLoadSupported;

@end
