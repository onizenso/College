/*filename: nested.c
  purpose: demonstrate how GNU C handles nested functions on the runtime stack

  compile with -g to include the best form of debugger flags:

  gcc -gstabs+ nested.c
  gdb a.out

  break main        # set break point in function main
  break foobar      # set break point in function foobar 
  run               # execute program 
  s                 # execute one line  (step)
  p &b              # grab the address of b for later comparison
  cont              # continue to next break point
  info frame        # print information about current stack frame
  info stack        # print information about the call stack 
  info arg          # print information about parameters
  info scope foobar # print variables available to foo 
  info local        # print information about local variables
  bt                # backtrace in stack
  f 1               # select frame 1
  s                 # step until last while loop in main
  p &b              # print the address of variable b in nested block 

  Other useful commands:
  x/d 0xffbefa48    # print value at hex address in decimal format 
  x/i 0xffbefa48    # print value at hex address as instruction
  help x            # display formating options for 'x' (examine)
  quit              # exit the debugger

 debugger variables:
 $pc - program counter
 $sp - stack pointer to previous frame
 $fp - frame pointer to current frame

 Sample stack frames (stack addresses increase as move "up" stack):
 #0 foobar  0xffbef940 
 #1 foo.0   0xffbef9c0 - 80 bytes  (fa48-f9c0 = 80)
 #2 main    0xffbefa48 - 88 bytes 

 &b in main is          0xffbef30
 &b in block in main is 0xffbef28

*/
#include <stdio.h>

void foobar ( int w, int x )
{
   while ( w ) {
      int y, z;
      y = w;
      z = x + w;
      w--; 
   }
}

int MAX=99; 

int main(void) {
   // grab b's address
   int a=1, b=1, c=1;
   {
     int b;
   } 
  

   // carefully look at how 'b' is stored in stack
   while ( c ) {
      int b=4, size;   // b is at 0xffbefa28 
      a=4;
      printf("Enter size for stack dynamic array:");
      scanf ("%d",&size); 
      int A[size];
      c--;
    }
    printf("What is c?: %d", c); 


   // demonstrate nested functions in GNU C
   // foo is nested in main and foobar is nested in foo
   void foo ( int i ) {
         int x = 1, y = 1;
         while ( i );
            i--;
 
         void foobar ( int y, int w) {
           int x = 5;
           y = 5;
           printf("X: %d, Y: %d ",x,y);
        } 
        foobar(5,7);
    }
    foo(a);

    return 0;
}
