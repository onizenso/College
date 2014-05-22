/**
 * Name: Huaqing Wang
 * Description: Simple Objective-C program.
 *
 * Define an alias in .bash_profile called "objcc"
 * Compile:  objcc filename.m -o executableFileName  // executable code will be generated.
 * Run    :  executableFileName
 *
 * Date:
 * */

#import <Foundation/Foundation.h>

int main( int argc, const char * argv[] ) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSLog(@"Hello, Welcome to Objective C!");

    [pool drain];

    return 0;
}

