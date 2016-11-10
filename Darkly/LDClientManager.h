//
//  Copyright © 2015 Catamorphic Co. All rights reserved.
//


#import "LDRequestManager.h"
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_OSX
#import <Foundation/Foundation.h>
#endif
#import <DarklyEventSource/EventSource.h>

extern NSString *const kLDUserUpdatedNotification;
extern NSString *const kLDBackgroundFetchInitiated;

#if TARGET_OS_IOS || TARGET_OS_TV
@interface LDClientManager : NSObject  <RequestManagerDelegate, UIApplicationDelegate> {
}
#elif TARGET_OS_OSX
@interface LDClientManager : NSObject  <RequestManagerDelegate, NSApplicationDelegate> {
}
#endif


@property (nonatomic) BOOL offlineEnabled;
@property(nonatomic, strong, readonly) EventSource *eventSource;

+(LDClientManager *)sharedInstance;

- (void)syncWithServerForEvents;
- (void)syncWithServerForConfig;
- (void)processedEvents:(BOOL)success jsonEventArray:(NSArray *)jsonEventArray eventIntervalMillis:(int)eventIntervalMillis;
- (void)processedConfig:(BOOL)success jsonConfigDictionary:(NSDictionary *)jsonConfigDictionary configIntervalMillis:(int)configIntervalMillis;
- (void)startPolling;
- (void)stopPolling;
- (void)willEnterBackground;
- (void)willEnterForeground;
- (void)flushEvents;

@end
