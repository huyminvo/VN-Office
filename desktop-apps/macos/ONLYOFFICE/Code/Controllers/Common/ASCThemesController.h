/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCThemesController.h
//  ONLYOFFICE
//
//  Created by Maxim.Kadushkin on 23/08/2022.
//  Copyright © 2022 Ascensio System SIA. All rights reserved.
//

#ifndef ASCThemesController_h
#define ASCThemesController_h

#import <Foundation/Foundation.h>
#import <AppKit/NSColor.h>

static NSString * const btnPortalActiveBackgroundColor  = @"portal-button-background-active-color";
static NSString * const tabWordActiveBackgroundColor    = @"tab-word-background-active-color";
static NSString * const tabCellActiveBackgroundColor    = @"tab-cell-background-active-color";
static NSString * const tabSlideActiveBackgroundColor   = @"tab-slide-background-active-color";
static NSString * const tabPdfActiveBackgroundColor     = @"tab-pdf-background-active-color";
static NSString * const tabDrawActiveBackgroundColor    = @"tab-draw-background-active-color";
static NSString * const tabActiveTextColor              = @"tab-editor-text-active-color";
static NSString * const windowBackgroundColor           = @"window-background-color";

@interface ASCThemesController : NSObject

+ (instancetype)sharedInstance;

+ (NSString*)currentThemeId;
+ (BOOL)isCurrentThemeDark;
+ (NSString*)defaultThemeId:(BOOL)isdark;
+ (NSString*)actualThemeId;
+ (NSColor*)color:(NSString*)name forTheme:(NSString*)theme;
+ (NSColor*)currentThemeColor:(NSString*)name;
+ (BOOL)isSystemDarkMode;
+ (BOOL)isDarkWindowAppearance;

@end

#endif /* ASCThemesController_h */
