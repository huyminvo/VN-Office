/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  NSView+Extensions.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 11/04/2018.
//  Copyright © 2018 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSView (Extensions)

@property (nonatomic) IBInspectable NSColor * backgroundColor;
@property (nonatomic) IBInspectable NSColor * borderColor;
@property (nonatomic) IBInspectable NSColor * shadowColor;
@property (nonatomic) IBInspectable CGFloat borderWidth;
@property (nonatomic) IBInspectable CGFloat cornerRadius;
@property (nonatomic) IBInspectable CGFloat width;
@property (nonatomic) IBInspectable CGFloat height;
@property (nonatomic) IBInspectable CGSize shadowOffset;
@property (nonatomic) IBInspectable CGFloat shadowOpacity;
@property (nonatomic) IBInspectable CGFloat shadowRadius;
@property (nonatomic) IBInspectable CGSize size;
@property (nonatomic) IBInspectable NSInteger uuidTag;

- (void)removeAllConstraints;
- (instancetype)duplicate;
- (void)shake;
- (NSImage *)imageRepresentation;
- (NSImage *)windowScreenshot;
- (nullable NSView *)subviewOfClassName:(NSString * _Nonnull)className;

@end
