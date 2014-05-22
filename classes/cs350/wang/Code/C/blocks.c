/*filename: blocks.c
  purpose: demonstrate how GNU C handles blocks on the runtime stack

  compile with -g to include the best form of debugger flags:

  gcc -gstabs+ blocks.c
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
  info var [regex]  # show names, types of global variables matching regex
  info line         # show source line number of next to be executed
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

int b=100;   // this has external linkage and compilation unit scope 

int main(void) {
   b = 99;   // bound to external b
   printf("Where is external b?: %p\n", &b); 

   int b = 4; 
   printf("Where is outer b?: %p\n", &b); 
   {
     int b = 5;  
     printf("Where is inner b?: %p\n", &b); 
     {
        int b = 6;  
        printf("Where is innermost b?: %p\n", &b); 
        /* gdb trace below shows the stack of local variables at this point */
     } 
   } 
  
   return 0;
}
/*
(gdb) info local
b = 6
b = 5
b = 4
*/
