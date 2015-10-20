//
//  KiwiMotionChannelMaster.h
//  KiwiSDK
//
//  Created by Dave Kim on 2015-04-02.
//  Copyright (c) 2015 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KiwiMotionChannelMaster : NSObject

// Set any kind of data that should be submitted for analytic purpose
@property (strong) NSMutableDictionary *extraData;
@property (strong) NSMutableArray *tags;
@property (strong, atomic) NSNumber *ACCELEROMETER_LAMBDA;
@property (strong, atomic) NSNumber *GRYOSCOPE_LAMBDA;


+(instancetype)sharedInstance;

//Configs

-(void) setRobusta:(BOOL) flag;

-(void)completionManagerWithMotionResult:(NSDictionary*)results;



-(void)pushData: (NSDictionary *)data;



-(void)addTarget:(NSMutableDictionary*) target;

-(void)addTargetWithPadding:(NSMutableDictionary*) target;

-(NSMutableArray*)getTargets;

-(void)removeAllTargets;

-(void)reset;


+(void)setGyroscopeLambda:(int)lambda;

+(int)getGyroscopeLambda;

+(void)setAccelerometerLambda:(int)lambda;

+(int)getAccelerometerLambda;

@end
