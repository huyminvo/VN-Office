/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCButtonCell.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/10/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ASCButtonCell : NSButtonCell
@property (nonatomic, readonly) BOOL isHover;
@property (nonatomic, readonly) BOOL isPressed;
@property (nonatomic, copy) void (^updateState)(void);


- (void)mouseEntered:(NSEvent *)theEvent;
- (void)mouseExited:(NSEvent *)theEvent;
- (void)mouseMoved:(NSEvent *)theEvent;
- (void)mouseDown:(NSEvent *)theEvent;
- (void)mouseUp:(NSEvent *)theEvent;
@end
