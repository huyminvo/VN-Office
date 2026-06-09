/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  NSString+Extensions.h
//  SpreadsheetEditor
//
//  Created by Alexander Yuzhin on 7/7/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <string>
#import <Foundation/Foundation.h>
#import <vector>

@interface NSString (Extensions)

+ (id)stringWithstdwstring:(const std::wstring&)string;
- (std::wstring)stdwstring;
- (std::string)stdstring;
+ (NSMutableArray*)stringsArray:(const std::vector<std::wstring>&)sources;
- (NSString *)stringByAppendingUrlQuery:(NSString *)query;
- (NSString *)md5;
- (NSDictionary *)dictionary;
- (NSString *)removeUrlQuery:(NSArray<NSString *> *)params;
- (NSString *)virtualUrl;

@end
