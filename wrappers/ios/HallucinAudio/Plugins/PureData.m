//
//  LibPD.m
//  HallucinAudio
//
//  Created by Rafael Vega on 5/5/13.
//
//

#import "PureData.h"

@implementation PureData

- (void)initPD:(CDVInvokedUrlCommand*)command {
  CDVPluginResult* pluginResult = nil;
  /* NSString* echo = [command.arguments objectAtIndex:0]; */

  /* if (echo != nil && [echo length] > 0) { */
  NSLog(@"%@", @"Hi!");
  pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
  /* } else { */
    /* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR]; */
  /* } */

  [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
