/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCSavePanelWithFormat.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 12/11/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ASCSavePanelWithFormatController : NSObject
@property (nonatomic) NSSavePanel *savePanel;
@property (nonatomic) NSArray * filters;
@property (nonatomic) NSInteger filterType;
@property (nonatomic) NSDictionary * original;
@end
