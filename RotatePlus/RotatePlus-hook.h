//
//  RotatePlus-hook.h
//  TestHook2
//
//  Created by KIGG on 11/2/14.
//
//

#ifndef TestHook2_RotatePlus_hook_h
#define TestHook2_RotatePlus_hook_h

#include "OverrideTraitRootViewController.h"

@class SpringBoard;
CHDeclareClass(SpringBoard);

CHOptimizedMethod(0, self, BOOL, SpringBoard, homeScreenSupportsRotation)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus.sb"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.springboard"]){
			return YES;
		}
	}
	return CHSuper(0, SpringBoard, homeScreenSupportsRotation);
}
CHOptimizedMethod(0, self, BOOL, SpringBoard, homeScreenRotationStyleWantsUIKitRotation)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus.sb"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.springboard"]){
			return YES;
		}
	}
	return CHSuper(0, SpringBoard, homeScreenRotationStyleWantsUIKitRotation);
}
CHOptimizedMethod(0, self, int, SpringBoard, homeScreenRotationStyle)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus.sb"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.springboard"]){
			return 2;
		}
	}
	return CHSuper(0, SpringBoard, homeScreenRotationStyle);
}

@class SBLockScreenViewController;
CHDeclareClass(SBLockScreenViewController);

CHOptimizedMethod(1, self, BOOL, SBLockScreenViewController, shouldAutorotateToInterfaceOrientation, int, orientation)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus.ls"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.springboard"]){
			return YES;
		}
	}
	return CHSuper(1, SBLockScreenViewController, shouldAutorotateToInterfaceOrientation, orientation);
}

CHOptimizedMethod(0, self, unsigned int, SBLockScreenViewController, supportedInterfaceOrientations)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus.ls"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.springboard"]){
			return UIInterfaceOrientationMaskAllButUpsideDown;
		}
	}
	return CHSuper(0, SBLockScreenViewController, supportedInterfaceOrientations);
}

@class SKUITabBarController;
CHDeclareClass(SKUITabBarController);

CHOptimizedMethod(0, self, unsigned int, SKUITabBarController, supportedInterfaceOrientations)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.AppStore"]){
			[[UIApplication sharedApplication] setStatusBarHidden:NO withAnimation:UIStatusBarAnimationNone];
			[self setNeedsStatusBarAppearanceUpdate];
			return UIInterfaceOrientationMaskAllButUpsideDown;
		}
	}
	return CHSuper(0, SKUITabBarController, supportedInterfaceOrientations);
}

@class UINavigationController;
CHDeclareClass(UINavigationController);

CHOptimizedMethod(0, self, unsigned int, UINavigationController, supportedInterfaceOrientations)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.AppStore"]){
			return UIInterfaceOrientationMaskAllButUpsideDown;
		}
	}
	return CHSuper(0, UINavigationController, supportedInterfaceOrientations);
}
@class SKUIDocumentContainerViewController;
CHDeclareClass(SKUIDocumentContainerViewController);

CHOptimizedMethod(0, self, unsigned int, SKUIDocumentContainerViewController, supportedInterfaceOrientations)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.AppStore"]){
			return UIInterfaceOrientationMaskAllButUpsideDown;
		}
	}
	return CHSuper(0, SKUIDocumentContainerViewController, supportedInterfaceOrientations);
}

@class PSSplitViewController;
CHDeclareClass(PSSplitViewController);

CHOptimizedMethod(0, self, unsigned int, PSSplitViewController, supportedInterfaceOrientations)
{
	//	NSLog(@">>> supportedInterfaceOrientations");
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.Preferences"]){
			return UIInterfaceOrientationMaskAllButUpsideDown;
		}
	}
	return CHSuper(0, PSSplitViewController, supportedInterfaceOrientations);
}


@class PreferencesAppController;
CHDeclareClass(PreferencesAppController);

CHOptimizedMethod(2, self, BOOL, PreferencesAppController, application, UIApplication*, application, didFinishLaunchingWithOptions, NSDictionary*, launchOptions)
{
	//	NSLog(@">>> didFinishLaunchingWithOptions");
	
	
	BOOL r = CHSuper(2, PreferencesAppController, application, application, didFinishLaunchingWithOptions, launchOptions);
	
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.Preferences"]){
			UIWindow *window = [application keyWindow];
			
			//		NSLog(@">>> %@", window);
			
			UIViewController *origViewController = [window rootViewController];
			OverrideTraitRootViewController *viewController = [[OverrideTraitRootViewController alloc] init];
			window.rootViewController = viewController;
			
			
			[viewController addChildViewController:origViewController];
			[origViewController didMoveToParentViewController:viewController];
			[viewController.view addSubview:origViewController.view];
		}
	}
	
	return r;
}

//CHOptimizedMethod(0, self, UITraitCollection *, PreferencesAppController, traitCollection)
//{
//	NSLog(@">>> traitCollection");
//	return [UITraitCollection traitCollectionWithUserInterfaceIdiom:UIUserInterfaceIdiomPad];
//}

@class NotesApp;
CHDeclareClass(NotesApp);

CHOptimizedMethod(2, self, BOOL, NotesApp, application, UIApplication*, application, didFinishLaunchingWithOptions, NSDictionary*, launchOptions)
{
	//	NSLog(@">>> didFinishLaunchingWithOptions");
	
	
	BOOL r = CHSuper(2, NotesApp, application, application, didFinishLaunchingWithOptions, launchOptions);
	
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.mobilenotes"]){
			UIWindow *window = [application keyWindow];
			
			//		NSLog(@">>> %@", window);
			
			UIViewController *origViewController = [window rootViewController];
			OverrideTraitRootViewController *viewController = [[OverrideTraitRootViewController alloc] init];
			window.rootViewController = viewController;
			
			
			
			[viewController addChildViewController:origViewController];
			[origViewController didMoveToParentViewController:viewController];
			[viewController.view addSubview:origViewController.view];
		}
	}
	
	
	
	return r;
}

@class AppDelegate;
CHDeclareClass(AppDelegate);

CHOptimizedMethod(2, self, BOOL, AppDelegate, application, UIApplication*, application, didFinishLaunchingWithOptions, NSDictionary*, launchOptions)
{
	//	NSLog(@">>> didFinishLaunchingWithOptions");
	
	
	BOOL r = CHSuper(2, AppDelegate, application, application, didFinishLaunchingWithOptions, launchOptions);
	
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.MobileAddressBook"]){
			UIWindow *window = [application keyWindow];
			
			//		NSLog(@">>> %@", window);
			
			UIViewController *origViewController = [window rootViewController];
			OverrideTraitRootViewController *viewController = [[OverrideTraitRootViewController alloc] init];
			window.rootViewController = viewController;
			
			
			
			[viewController addChildViewController:origViewController];
			[origViewController didMoveToParentViewController:viewController];
			[viewController.view addSubview:origViewController.view];
		}
	}
	
	return r;
}

@class SMSApplication;
CHDeclareClass(SMSApplication);

CHOptimizedMethod(2, self, BOOL, SMSApplication, application, UIApplication*, application, didFinishLaunchingWithOptions, NSDictionary*, launchOptions)
{
	//	NSLog(@">>> didFinishLaunchingWithOptions");
	
	
	BOOL r = CHSuper(2, SMSApplication, application, application, didFinishLaunchingWithOptions, launchOptions);
	
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.MobileSMS"]){
			UIWindow *window = [application keyWindow];
			
			//		NSLog(@">>> %@", window);
			
			UIViewController *origViewController = [window rootViewController];
			OverrideTraitRootViewController *viewController = [[OverrideTraitRootViewController alloc] init];
			window.rootViewController = viewController;
			
			
			
			[viewController addChildViewController:origViewController];
			[origViewController didMoveToParentViewController:viewController];
			[viewController.view addSubview:origViewController.view];
		}
	}
	
	return r;
}
@class UITableView;
CHDeclareClass(UITableView);
//_contentOffsetForScrollingToRowAtIndexPath:atScrollPosition
CHOptimizedMethod(2, self, CGPoint, UITableView, _contentOffsetForScrollingToRowAtIndexPath, NSIndexPath*, indexPath, atScrollPosition, int, position)
{
	//	NSLog(@"app = %@", [[UIApplication sharedApplication] displayIdentifier]);
	//	NSLog(@">>> _contentOffsetForScrollingToRowAtIndexPath");
	
	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.MobileSMS"]){
			@try {
				return CHSuper(2, UITableView, _contentOffsetForScrollingToRowAtIndexPath, indexPath, atScrollPosition, position);
			}
			@catch (NSException *exception) {
				
			}
			@finally {
				
			}
			return CGPointMake(0, 0);
		}
	}
	
	return CHSuper(2, UITableView, _contentOffsetForScrollingToRowAtIndexPath, indexPath, atScrollPosition, position);
}







@class MailAppController;
CHDeclareClass(MailAppController);

CHOptimizedMethod(2, self, BOOL, MailAppController, application, UIApplication*, application, didFinishLaunchingWithOptions, NSDictionary*, launchOptions)
{
//		NSLog(@">>> didFinishLaunchingWithOptions %@ %@", [[UIApplication sharedApplication] displayIdentifier], settings);
	
	
	BOOL r = CHSuper(2, MailAppController, application, application, didFinishLaunchingWithOptions, launchOptions);
	
//	if([[settings objectForKey:@"rotateplus"] boolValue]){
		if([[[UIApplication sharedApplication] displayIdentifier] isEqualToString:@"com.apple.mobilemail"]){
			UIWindow *window = [application keyWindow];
			
//					NSLog(@">>> window %@", window);
			
			UIViewController *origViewController = [window rootViewController];
			OverrideTraitRootViewController *viewController = [[OverrideTraitRootViewController alloc] init];
			window.rootViewController = viewController;
			
			
			[viewController addChildViewController:origViewController];
			[origViewController didMoveToParentViewController:viewController];
			[viewController.view addSubview:origViewController.view];
		}
//	}
	
	return r;
}
#endif
