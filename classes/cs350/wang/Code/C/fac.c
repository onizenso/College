/* filename: fac.c
   purpose: demonstrate runtime stack and recursion  
   
  for GNU C under Linux:
  $ gcc -g fac.c
  $ gdb a.out
  (gdb) break fac
  (gdb) run 
  (gdb) where full
  (gdb) cont
  (gdb) where full
  (gdb) list 20,30    # list lines 20-30 in source
  (gdb) p &test       # print address of static variable
  (gdb) p &local      # print address of local variable
      $2 = (int *) 0x7fff9e05378c
  (gdb) x/d 0x7fff9e05378c
      0x7fff9e05378c: 0
  (gdb) info frame    # info on current frame

    Stack level 1, frame at 0x7fff9e0537c8:
    rip = 0x4004d8 in fac (fac.c:43); saved rip 0x4004d8
    called by frame at 0x7fff9e0537f0, caller of frame at 0x7fff9e0537a0
    source language c.
    Arglist at 0x7fff9e0537b8, args: n=4
    Locals at 0x7fff9e0537b8, Previous frame's sp is 0x7fff9e0537c8
    Saved registers:
    rbp at 0x7fff9e0537b8, rip at 0x7fff9e0537c0

  (gdb) x/i 0x4004d8  # print instruction at rip (return instruction pointer)
     0x4004d8 <fac+43>:      imul   0xffffffffffffffec(%rbp),%eax

  (gdb) frame 0       # select frame 0  (0 is the currently executing frame)
  (gdb) frame         # info on current frame
  (gdb) up            # select and print stack frame that called current one
  (gdb) down          # select and print stack frame subsequent to current one
  (gdb) info args      
  (gdb) info locals
*/

#include <stdio.h>

int fac( int );

static int test = 100;

int main(void)
{       
  int result = 0;
  result  = fac(5);  
  printf("Result: %d\n", result);     
  return 0;
}


int fac( int n ){
   int local = 0;      // create a local variable for the run-time stack  
   if ( n <= 1 ) {
       local = 1;
   }  
   else {
       local = n * fac (n-1);  // the return value from the recursive call
   }
   return local;
}
