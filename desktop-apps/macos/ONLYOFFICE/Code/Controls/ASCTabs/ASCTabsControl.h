/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCTabsControl.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/7/15.
//  Copyright (c) 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ASCTabsControl;
@class ASCTabView;

@interface ASCTabsMulticastDelegate : NSObject
- (void)addDelegate:(id)delegate;
@end

@protocol ASCTabsControlDelegate <NSObject>
@optional
- (void)tabs:(ASCTabsControl *)control didResize:(CGRect)rect;
- (void)tabs:(ASCTabsControl *)control didAddTab:(ASCTabView *)tab;
- (BOOL)tabs:(ASCTabsControl *)control willRemovedTab:(ASCTabView *)tab;
- (void)tabs:(ASCTabsControl *)control didRemovedTab:(ASCTabView *)tab;
- (void)tabs:(ASCTabsControl *)control didSelectTab:(ASCTabView *)tab;
- (void)tabs:(ASCTabsControl *)control didUpdateTab:(ASCTabView *)tab;
- (void)tabs:(ASCTabsControl *)control didReorderTab:(ASCTabView *)tab from:(NSInteger)oldIndex to:(NSInteger)newIndex;
- (void)tabs:(ASCTabsControl *)control didDetachTab:(ASCTabView *)tab atScreenPoint:(NSPoint)screenPoint withEvent:(NSEvent *)event;
@end

@interface ASCTabsControl : NSControl
@property (nonatomic) NSMutableArray *tabs;
@property (nonatomic) CGFloat minTabWidth;
@property (nonatomic) CGFloat maxTabWidth;
@property (nonatomic, assign) id <ASCTabsControlDelegate> delegate;
@property (readonly) ASCTabsMulticastDelegate* multicastDelegate;

- (void)addTab:(ASCTabView *)tab;
- (void)addTab:(ASCTabView *)tab selected:(BOOL)selected;
- (void)insertTab:(ASCTabView *)tab atIndex:(NSUInteger)index;
- (void)insertTab:(ASCTabView *)tab atIndex:(NSUInteger)index selected:(BOOL)selected;

- (void)removeTab:(ASCTabView *)tab animated:(BOOL)animated;
- (void)removeTab:(ASCTabView *)tab selected:(BOOL)selected animated:(BOOL)animated;
- (void)removeAllTabs;
- (void)selectTab:(ASCTabView *)tab;
- (void)updateTab:(ASCTabView *)tab;
- (void)selectNextTab;
- (void)selectPreviouseTab;

- (ASCTabView *)tabWithUUID:(NSString *)uuid;
- (ASCTabView *)selectedTab;
@end
