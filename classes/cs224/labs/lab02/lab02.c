/*filename: lab02.c
  purpose: demonstrate layout of an ELF-64 bit x86 executable in RAM including 
  the runtime stack, text and data segments 

  compile with -g to include the best form of debugger flags:

    $ gcc -g lab02.c
    $ gdb a.out

  break main        # set break point in function main
  break foobar      # set break point in function foobar 
  run               # execute program - break in main
  cont              # continue to next break point
  s                 # execute one line (may be multiple assembly instructions) 
  p &x              # print the address of variable x 
  cont              # continue to next break point
  info frame        # print information about current stack frame
  info frame 1      # print information about stack frame 1
  info stack        # print information about the call stack 
  info arg          # print information about parameters
  info scope foobar # print variables available to foobar 
  info local        # print information about variables in current stack frame 
  info variables    # print information about static and global variables 
  bt                # print backtrace of stack
  f 1               # select frame 1
  disassemble       # dump assembly code of current procedure to the screen 
  stepi             # step through a single assembler instruction  
  p $rbp            # print the address of the 8086 stack base pointer

  examining memory:
  x/d 0xffbefa48    # print value at hex address in decimal format 
  x/i 0xffbefa48    # print value at hex address as instruction
  x/i *$rip         # print instruction pointed at by return instruction pointer
  x/i *$pc          # print instruction pointed at by program counter 

  help x            # display formating options for 'x' (examine)
  quit              # exit the debugger

 debugger variables from registers:
 $pc - program counter
 $sp - pointer to top of stack 
 $fp - pointer to bottom of current frame (previous function's stack pointer)
  
 Sample stack frames (stack addresses increase as move "up" stack):
 #0 foobar  0xffbef940 
 #2 main    0xffbefa48 - 0x88 bytes 

 &x in main is          0xffbef30

 An analysis of the stack on Solaris Sparc (8086 machines will look different):

 Higher addresses
 ===============
 %fp---->(previous top of stack)
         locals, temp space and padding for byte alignment
 %sp+92->extra arguments
 %sp+68->arguments (6 4-byte words)
 %sp+64->pointer to return value of the next function
 %sp+32->%i0-%i7 registers
 %sp---->%l0-%l7 registers
 %sp---->(top of stack)
 =============== 
 Lower addresses

 %sp+16->%o0-%o7 registers  
*/

#include <stdlib.h>
void foobar ( int w, double x )
{
   int y;
   double z;
   y = w;
   z = x / y;
} 

int MAX=1;    // MAX is stored in the data section of the executable

int main(void) {
   int *x = (int *) malloc(sizeof(int));  /* the pointer x is stored in the 
                                             stack frame for main and the int 
                                             itself is stored in the heap */
   *x = MAX;
   double b = 2.5;
   foobar(*x, b);
   MAX = 5;
   return 0;
}
