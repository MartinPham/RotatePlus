//
//  shared.h
//  TestHook2
//
//  Created by MartinPham on 11/2/14.
//
//

//#define DEBUG 1

#ifdef DEBUG
#   define L(fmt, ...) NSLog((@"<MP> %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#   define QL(v) L("%@", v)
#   define RL L("OK")
#   define QLR(r) L(@"%f, %f, %f, %f", r.origin.x, r.origin.y, r.size.width, r.size.height)
#   define QLS(s) L(@"%f, %f", s.width, s.height)
#else
#   define L(...)
#   define QL(...)
#   define RL
#   define QLR(...)
#   define QLS(...)
#endif

#define settings [[NSMutableDictionary alloc] initWithContentsOfFile:[NSHomeDirectory() stringByAppendingPathComponent:@"/Library/Preferences/gg.ki.rotateplus.plist"]]