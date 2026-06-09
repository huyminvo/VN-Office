/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

//
//  ASCDownloadCellView.h
//  ONLYOFFICE
//
//  Created by Alexander Yuzhin on 9/29/15.
//  Copyright © 2015 Ascensio System SIA. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ASCDownloadCellView;

@protocol ASCDownloadCellViewDelegate  <NSObject>
@optional
- (void)onCancelButton:(ASCDownloadCellView *)cell;
@end

@interface ASCDownloadCellView : NSTableCellView
@property (weak) IBOutlet NSProgressIndicator *progress;
@property (weak) IBOutlet NSButton *cancelButton;

@property (nonatomic) NSString *uuid;
@property (nonatomic) id <ASCDownloadCellViewDelegate> delegate;
@end
