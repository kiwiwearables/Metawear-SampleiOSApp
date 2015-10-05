//
//  KiwiThirdpartySensorStream.h
//  KiwiSDK
//
//  Created by Dave Kim on 2014-12-23.
//  Copyright (c) 2014 Kiwi Wearable Technologies Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GCDAsyncUdpSocket.h"

@interface KiwiThirdpartySensorStream : NSObject

+ (id)sharedInstance;

-(void) streamForDeviceId:(NSString*)deviceId
                       AX:(NSNumber*)AX
                       AY:(NSNumber*)AY
                       AZ:(NSNumber*)AZ
                       GX:(NSNumber*)GX
                       GY:(NSNumber*)GY
                       GZ:(NSNumber*)GZ;

-(void) fullyStreamForDeviceId:(NSString*)deviceId
                      WithData:(NSMutableDictionary*)data;

@end