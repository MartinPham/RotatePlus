//
//  RotatePlus-load.h
//  TestHook2
//
//  Created by KIGG on 11/2/14.
//
//

#ifndef TestHook2_RotatePlus_load_h
#define TestHook2_RotatePlus_load_h

CHLoadLateClass(SpringBoard);
CHHook(0, SpringBoard, homeScreenRotationStyleWantsUIKitRotation);
CHHook(0, SpringBoard, homeScreenRotationStyle);

CHLoadLateClass(SBLockScreenViewController);
CHHook(1, SBLockScreenViewController, shouldAutorotateToInterfaceOrientation);
CHHook(0, SBLockScreenViewController, supportedInterfaceOrientations);


CHLoadLateClass(SKUITabBarController);
CHHook(0, SKUITabBarController, supportedInterfaceOrientations);
CHLoadLateClass(UINavigationController);
CHHook(0, UINavigationController, supportedInterfaceOrientations);
CHLoadLateClass(SKUIDocumentContainerViewController);
CHHook(0, SKUIDocumentContainerViewController, supportedInterfaceOrientations);



CHLoadLateClass(PSSplitViewController);
CHHook(0, PSSplitViewController, supportedInterfaceOrientations);

CHLoadLateClass(PreferencesAppController);
CHHook(2, PreferencesAppController, application, didFinishLaunchingWithOptions);
//CHHook(0, PreferencesAppController, traitCollection);

CHLoadLateClass(NotesApp);
CHHook(2, NotesApp, application, didFinishLaunchingWithOptions);

CHLoadLateClass(AppDelegate);
CHHook(2, AppDelegate, application, didFinishLaunchingWithOptions);

CHLoadLateClass(SMSApplication);
CHHook(2, SMSApplication, application, didFinishLaunchingWithOptions);
CHLoadLateClass(UITableView);
CHHook(2, UITableView, _contentOffsetForScrollingToRowAtIndexPath, atScrollPosition);


CHLoadLateClass(MailAppController);
CHHook(2, MailAppController, application, didFinishLaunchingWithOptions);


#endif
