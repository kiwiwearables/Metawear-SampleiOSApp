//
//  ViewController.m
//  kiwi-metawear
//
//  Created by Dave Kim on 2015-10-16.
//  Copyright © 2015 kiwi. All rights reserved.
//

#import "ViewController.h"
#import <MetaWear/MetaWear.h>

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *metaWearStatusLabel;
@property (weak, nonatomic) IBOutlet UIButton *disconnectButton;

@property (nonatomic, strong) NSArray *devices;
@property (nonatomic, strong) MBLMetaWear *connectedDevice;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

# pragma mark - MetaWear
-(void) startScanning {
    // Only scan for nearby devices
    static const int MAX_ALLOWED_RSSI = -15; // The RSSI calculation sometimes produces erroneous values, we know anything above this value is invalid
    static const int MIN_ALLOWED_RSSI = -50; // Depending on your specific application this value will change!
    
    [[MBLMetaWearManager sharedManager] startScanForMetaWearsAllowDuplicates:YES handler:^(NSArray *array) {
        
        for (MBLMetaWear *device in array) {
            // Reject any value above a reasonable range
            if (device.discoveryTimeRSSI.integerValue > MAX_ALLOWED_RSSI) {
                continue;
            }
            // Reject if the signal strength is too low to be close enough (find through experiment)
            if (device.discoveryTimeRSSI.integerValue < MIN_ALLOWED_RSSI) {
                continue;
            }
            NSLog(@"%@", device.identifier.UUIDString);
            [[MBLMetaWearManager sharedManager] stopScanForMetaWears];
            [self connectDevice:device];
        }
    }];
}

-(void) connectDevice:(MBLMetaWear*)device {
    [device connectWithHandler:^(NSError *error) {
        NSLog(@"Connected");
        [self updateMetawearStatusLabel:@"Connected"];
        _connectedDevice = device;
        
        device.accelerometer.sampleFrequency = 50; // Default: 100 Hz
        [device.accelerometer.dataReadyEvent startNotificationsWithHandler:^(MBLAccelerometerData *obj, NSError *error) {
            NSLog(@"X = %f, Y = %f, Z = %f", obj.x, obj.y, obj.z);
        }];
        device.gyro.sampleFrequency = 50; // Default: 100 Hz
        [device.gyro.dataReadyEvent startNotificationsWithHandler:^(MBLGyroData *obj, NSError *error) {
            NSLog(@"X = %f, Y = %f, Z = %f", obj.x, obj.y, obj.z);
        }];
        
    }];
}

-(void) disconnectDevice:(MBLMetaWear*)device {
    [device disconnectWithHandler:^(NSError *error) {
        NSLog(@"Disconnected");
        [self updateMetawearStatusLabel:@"Disconnected"];
    }];
}

#pragma mark - UI

-(void)updateMetawearStatusLabel:(NSString*)status {
    _metaWearStatusLabel.text = status;
}

- (IBAction)scanAndConnectButtonTouched:(id)sender {
    [self updateMetawearStatusLabel:@"scanning..."];
    // Start scanning and automatically pair
    [self startScanning];
}


-(IBAction)disconnectButtonTouched:(UIButton *)sender {
    if (_connectedDevice){
        [self disconnectDevice:_connectedDevice];
    }
}



@end
