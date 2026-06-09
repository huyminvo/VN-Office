/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCEditorJSVariables.h
//  ONLYOFFICE
//
//  Created by Maxim.Kadushkin on 28/07/2022.
//  Copyright © 2022 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ASCEditorJSVariables : NSObject
+ (instancetype)instance;

- (id)init;
- (void)apply;
- (void)setVariable:(NSString*)name withString:(NSString *)value;
- (void)setVariable:(NSString*)name withObject:(NSDictionary *)value;
- (void)setVariable:(NSString*)name withBool:(BOOL)value;
- (void)setParameter:(NSString*)name withString:(NSString *)value;
- (void)removeParameter:(NSString*)name;
- (void)applyParameters;

@end
