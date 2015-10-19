//
//  KiwiUserModel.h
//  KiwiSDK
//
//  Created by Dave Kim on 2014-10-29.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking/AFNetworking.h"

@interface KiwiUserModel : NSObject

@property NSString *kiwiToken;
@property NSString *kiwiUserId;
// Since the specs always change. Let's keep it this way for now.
@property NSMutableDictionary *data;

+ (id)sharedInstance;

- (void)createNewUserWithEmail:(NSString*)email
                   AndPassword:(NSString*)password
                       success:(void (^)(id))success_cb  //(id sender)
                          fail:(void (^)(id))fail_cb;    //(id sender)

- (void)getUserWithEmail:(NSString*)email
             AndPassword:(NSString*)password
                 success:(void (^)(id))success_cb  //(id sender)
                    fail:(void (^)(id))fail_cb;    //(id sender)

@end
