/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

//
//  ASCTabTouchBar.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 02/01/2019.
//  Copyright (c) 2019 Ascensio System SIA. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ASCTabTouchBarType)
{
    ASCTabTouchBarTypeRoot          = 0,
    ASCTabTouchBarTypeDocument      = 1,
    ASCTabTouchBarTypeSpreadsheet   = 2,
    ASCTabTouchBarTypePresentation  = 3,
    ASCTabTouchBarTypePortal        = 4,
    ASCTabTouchBarTypePage          = 5,
    ASCTabTouchBarTypePdf           = 6
};

NS_ASSUME_NONNULL_BEGIN

@interface ASCTabTouchBar : NSObject

@property (nonatomic) ASCTabTouchBarType type;
@property (nonatomic) NSString * uuid;
@property (nonatomic) NSString * title;

@end

NS_ASSUME_NONNULL_END
