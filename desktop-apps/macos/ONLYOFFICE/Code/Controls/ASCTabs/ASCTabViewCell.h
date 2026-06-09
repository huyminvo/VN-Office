/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCTabViewCell.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/10/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import "ASCButtonCell.h"

@interface ASCTabViewCell : ASCButtonCell

@property (nonatomic) NSColor * inactiveColor;
@property (nonatomic) NSColor * activeColor;
@property (nonatomic) NSColor * hoverInactiveColor;
@property (nonatomic) NSColor * hoverActiveColor;
@property (nonatomic) NSColor * clickColor;
@property (nonatomic) NSColor * activeTextColor;
@property (nonatomic) NSColor * inactiveTextColor;
@property (nonatomic) NSColor * inactiveBorderColor;
@property (nonatomic, weak) NSButton * closeButton;
@property (nonatomic) BOOL isProcessing;
@property (nonatomic) BOOL isLight;

@end
