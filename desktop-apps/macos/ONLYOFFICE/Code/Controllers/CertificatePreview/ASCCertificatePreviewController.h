/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
 */

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASCCertificatePreviewController : NSObject

- (instancetype)init:(NSViewController *)viewController;

- (void)presentTextInfo:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
