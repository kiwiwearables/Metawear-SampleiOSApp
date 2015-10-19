//
//  KiwiMotionModel.h
//  KiwiSDK
//
//  Created by Dave Kim on 2014-10-30.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KiwiMotionModel : NSObject

// Since the specs always change. Let's keep it this way for now.
@property (strong, nonatomic) NSMutableArray *data;

+(id)sharedInstance;

-(NSDictionary*) getMotionByMotionId:(NSString*)motionId;

-(void) getAllUserMotions:(void (^)(id))success_cb  //(id sender)
                      fail:(void (^)(id))fail_cb;    //(id sender);

-(void) saveMotion:(NSDictionary*) motion_obj
           success:(void (^)(id))  success_cb
              fail:(void (^)(id))  fail_cb;

-(void) updateMotion:(NSMutableDictionary*) motion_obj
             success:(void (^)(id))  success_cb  //(id sender)
                fail:(void (^)(id))  fail_cb;

-(void) removeMotionByMotionId:(NSString*)motionId
                       success:(void (^)(id))  success_cb
                          fail:(void (^)(id))  fail_cb;

-(void) cacheMotion:(NSDictionary*) motion_obj;

@end
