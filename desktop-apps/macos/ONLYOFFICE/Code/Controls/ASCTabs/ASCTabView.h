/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCTabView.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/7/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ASCButton.h"
#import "ASCTabViewType.h"

@class ASCTabView;

@protocol ASCTabViewDelegate  <NSObject>
@optional
- (void)tabDidClose:(ASCTabView *)tab;
- (void)tabDidUpdate:(ASCTabView *)tab;
@end

@interface ASCTabView : ASCButton {
    NSString * originalTitle;
}
@property (nonatomic) ASCTabViewType type;
@property (nonatomic) NSString *uuid;
@property (nonatomic) NSMutableDictionary *params;
//@property (nonatomic) BOOL changed;
@property (nonatomic) BOOL isProcessing;
@property (nonatomic) BOOL isDragging;
@property (nonatomic, weak) NSView *webView;

@property (nonatomic, assign) id <ASCTabViewDelegate> delegate;
@end
