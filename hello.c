#import <Cocoa/Cocoa.h>
#include <iostream>

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    NSWindow *window_;
}
@end

@implementation AppDelegate
- (void)applicationDidFinishLaunching:(NSNotification *)notification {
    std::cout << "Hello, World!" << std::endl;

    NSRect frame = NSMakeRect(0, 0, 480, 300);
    NSUInteger styleMask = NSWindowStyleMaskTitled |
                           NSWindowStyleMaskClosable |
                           NSWindowStyleMaskMiniaturizable |
                           NSWindowStyleMaskResizable;

    window_ = [[NSWindow alloc] initWithContentRect:frame
                                          styleMask:styleMask
                                            backing:NSBackingStoreBuffered
                                              defer:NO];
    [window_ setTitle:@"Hello World"];

    NSMutableString *message = [NSMutableString string];
    for (int i = 0; i < 10; ++i) {
        [message appendString:@"Hello World!"];
        if (i < 9) {
            [message appendString:@"\n"];
        }
    }

    NSTextField *label = [[NSTextField alloc] initWithFrame:NSMakeRect(20, 20, 440, 260)];
    [label setBezeled:NO];
    [label setEditable:NO];
    [label setSelectable:NO];
    [label setDrawsBackground:NO];
    [label setFont:[NSFont systemFontOfSize:24]];
    [label setLineBreakMode:NSLineBreakByWordWrapping];
    [label setUsesSingleLineMode:NO];
    [label setStringValue:message];

    [[window_ contentView] addSubview:label];
    [window_ center];
    [window_ makeKeyAndOrderFront:nil];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}
@end

int main(int argc, const char *argv[]) {
    @autoreleasepool {
        NSApplication *app = [NSApplication sharedApplication];
        AppDelegate *delegate = [[AppDelegate alloc] init];

        [app setActivationPolicy:NSApplicationActivationPolicyRegular];
        [app setDelegate:delegate];
        [app activateIgnoringOtherApps:YES];
        [app run];
    }

    return 0;
}
