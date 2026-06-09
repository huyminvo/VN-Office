/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCSharedSettings.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 12/15/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString * const kSettingsCurrentTab         = @"asc.onlyoffice.currentTab";
static NSString * const kSettingsLastOpenDirectory  = @"asc.onlyoffice.lastOpenDirectory";
static NSString * const kSettingsHasExtraFeatures   = @"asc.onlyoffice.hasExtraFeatures";
static NSString * const kSettingsOpenAppLinks       = @"asc.onlyoffice.openAppLinks";
static NSString * const kSettingsColorScheme        = @"asc.onlyoffice.colorScheme";

@interface ASCSharedSettings : NSObject
+ (instancetype)sharedInstance;

- (void)setSetting:(id)setting forKey:(id <NSCopying>)aKey;
- (id)settingByKey:(id)key;
@end
