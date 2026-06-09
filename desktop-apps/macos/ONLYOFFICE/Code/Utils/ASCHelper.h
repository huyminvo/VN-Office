/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCHelper.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/8/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef DEBUG
#   define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#   define DLog(...)
#endif

@interface ASCHelper : NSObject
+ (NSMutableDictionary *)localSettings;
+ (NSString *)applicationDataPath;
+ (NSString *)recoveryDataPath;
+ (NSString *)licensePath;
+ (void)createCloudPath;
+ (NSString *)appName;
+ (NSString *)appNameShort;
@end
