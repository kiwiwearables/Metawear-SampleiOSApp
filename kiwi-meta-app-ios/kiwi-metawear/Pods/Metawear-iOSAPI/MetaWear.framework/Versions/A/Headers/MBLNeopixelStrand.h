/**
 * MBLNeopixelStrand.h
 * MetaWear
 *
 * Created by Stephen Schiffli on 3/2/15.
 * Copyright 2014-2015 MbientLab Inc. All rights reserved.
 *
 * IMPORTANT: Your use of this Software is limited to those specific rights
 * granted under the terms of a software license agreement between the user who
 * downloaded the software, his/her employer (which must be your employer) and
 * MbientLab Inc, (the "License").  You may not use this Software unless you
 * agree to abide by the terms of the License which can be found at
 * www.mbientlab.com/terms.  The License limits your use, and you acknowledge,
 * that the Software may be modified, copied, and distributed when used in
 * conjunction with an MbientLab Inc, product.  Other than for the foregoing
 * purpose, you may not use, reproduce, copy, prepare derivative works of,
 * modify, distribute, perform, display or sell this Software and/or its
 * documentation for any purpose.
 *
 * YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 * PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 * NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 * MBIENTLAB OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE,
 * STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE
 * THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED
 * TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST
 * PROFITS OR LOST DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY,
 * SERVICES, OR ANY CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY
 * DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *
 * Should you have any questions regarding your right to use this Software,
 * contact MbientLab via email: hello@mbientlab.com
 */

#import <MetaWear/MBLNeopixel.h>
#import <UIKit/UIKit.h>

/**
 Interface to a strand of NeoPixels
 */
@interface MBLNeopixelStrand : NSObject <NSCoding>

/**
 Set Pixel at strand index.
 @param pixel Pixel index to be set
 @param color Color the LED will be set to
 */
- (void)setPixel:(uint8_t)pixel color:(nonnull UIColor *)color;

/**
 This sets each pixel in the strand so that it looks like a rainbow.
 Very cool for a quick demo!
 @param hold If YES, then we hold the strand duing update so that
 it instantly takes the rainbow colors, if NO then you will see each
 pixel update individually
 */
- (void)setRainbowWithHold:(BOOL)hold;

/**
 Clear Neopixel strand.
 @param start Pixel index to start clearing from
 @param end Pixel index to clear to, inclusive
 */
- (void)clearFromStartPixel:(uint8_t)startPixel endPixel:(uint8_t)endPixel;

/**
 Hold Neopixel strand.
 @param enable Hold enable
 */
- (void)holdStrandWithEnable:(BOOL)enable;

/**
 Rotate strand at index.
 @param index Strand number, can be in the range [0, 2]
 @param direction Rotation direction
 @param repetitions Number of times to repeat the rotation. Use 0xFF to rotate indefinitely, 0 to terminate
 @param period Amount of time, in milliseconds, between rotations
 */
- (void)rotateStrandWithDirection:(MBLRotationDirection)direction repetitions:(uint8_t)repetitions period:(uint16_t)period;

/**
 Clears all pixels and puts strand into low power state
 */
- (void)turnStrandOff;

@end
