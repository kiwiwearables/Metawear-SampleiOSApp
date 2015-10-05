//
//  KiwiThirdpartySensorStream.m
//  KiwiSDK
//
//  Created by Dave Kim on 2014-12-23.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import "KiwiThirdpartySensorStream.h"

@interface KiwiThirdpartySensorStream()

@property (strong) GCDAsyncUdpSocket *kiwiAsyncUdpSocket;

@end


@implementation KiwiThirdpartySensorStream

+ (id)sharedInstance {
    static dispatch_once_t pred;
    static KiwiThirdpartySensorStream *sharedInstance = nil;
    
    dispatch_once(&pred, ^{
        sharedInstance = [[KiwiThirdpartySensorStream alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        // Static declarations here
        self.kiwiAsyncUdpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
        
    }
    return self;
}


-(void) streamForDeviceId:(NSString*)deviceId
                       AX:(NSNumber*)AX
                       AY:(NSNumber*)AY
                       AZ:(NSNumber*)AZ
                       GX:(NSNumber*)GX
                       GY:(NSNumber*)GY
                       GZ:(NSNumber*)GZ {
    NSMutableDictionary *data = [[NSMutableDictionary alloc] init];
    [data setValue:deviceId forKey:@"device_id"];
    [data setValue:AX forKey:@"ax"];
    [data setValue:AY forKey:@"ay"];
    [data setValue:AZ forKey:@"az"];
    [data setValue:GX forKey:@"gx"];
    [data setValue:GY forKey:@"gy"];
    [data setValue:GZ forKey:@"gz"];
    
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:data
                                                       options:0
                                                         error:nil];
    [self.kiwiAsyncUdpSocket sendData:jsonData toHost:@"build.kiwiwearables.com" port:4000 withTimeout:-1 tag:1];
}


-(void) fullyStreamForDeviceId:(NSString*)deviceId WithData:(NSMutableDictionary*)data {
    data[@"device_id"] = deviceId;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:data
                                                       options:0
                                                         error:nil];
    [self.kiwiAsyncUdpSocket sendData:jsonData toHost:@"build.kiwiwearables.com" port:4000 withTimeout:-1 tag:1];
}

@end
