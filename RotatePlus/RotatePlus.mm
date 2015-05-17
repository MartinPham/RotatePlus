//
//  RotatePlus.mm
//  RotatePlus
//
//  Created by KIGG on 11/5/14.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

// CaptainHook by Ryan Petrich
// see https://github.com/rpetrich/CaptainHook/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CaptainHook/CaptainHook.h"
#include <notify.h> // not required; for examples only


#include "shared.h"

// Objective-C runtime hooking using CaptainHook:
//   1. declare class using CHDeclareClass()
//   2. load class using CHLoadClass() or CHLoadLateClass() in CHConstructor
//   3. hook method using CHOptimizedMethod()
//   4. register hook using CHHook() in CHConstructor
//   5. (optionally) call old method using CHSuper()

#include "RotatePlus-hook.h"
static void ExternallyPostedNotification(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo)
{
	//	NSLog(@"wow");
	//	system("killall backboardd");
	
	if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.springboard"]){
		
		system("killall backboardd");
		
		//		[[UIApplication sharedApplication] launchApplicationWithIdentifier:@"gg.ki.testRootApp" suspended:NO];
	}
	
}
CHConstructor // code block that runs immediately upon load
{
	@autoreleasepool
	{
		//		NSLog(@">>> loaded!");
		CFNotificationCenterRef darwin = CFNotificationCenterGetDarwinNotifyCenter();
		CFNotificationCenterAddObserver(darwin, NULL, ExternallyPostedNotification, CFSTR("gg.ki.rotateplus/preferences.changed"), NULL, CFNotificationSuspensionBehaviorCoalesce);

		#include "RotatePlus-load.h"
	}
}
