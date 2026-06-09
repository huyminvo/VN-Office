/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCEditorWindowController.h
//  ONLYOFFICE
//
//  Copyright (c) 2025 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ASCEditorWindowController : NSWindowController <NSWindowDelegate>
+ (instancetype)initWithDefaultFrame;
+ (instancetype)initWithFrame:(NSRect)frame;
- (BOOL)holdView:(NSString *)viewId;

@property (nonatomic) NSMutableDictionary *params;
@end
