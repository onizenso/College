/*filename: hw10.c
  purpose: demonstrate the GNU C runtime stack

  compile with -g to include the best form of debugger flags:

  gcc -g hw10.c
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
  info local        # print information about variables in current stack frame 
  info variables    # print information about static and global variables 
  bt                # print backtrace of stack
  f 1               # select frame 1
  s                 # step until last while loop in main
  p &b              # print the address of variable b 

  Other useful commands:
  x/d 0xffbefa48    # print value at hex address in decimal format 
  x/i 0xffbefa48    # print value at hex address as instruction
  help x            # display formating options for 'x' (examine)
  quit              # exit the debugger

 debugger variables:
 $pc - program counter
 $sp - pointer to top of stack 
 $fp - pointer to bottom of current frame (previous function's stack pointer)

 Sample stack frames (stack addresses increase as move "up" stack):
 #0 foobar  0xffbef940 
 #1 foo.0   0xffbef9c0 - 0x80 bytes  (fa48-f9c0 = 80)
 #2 main    0xffbefa48 - 0x88 bytes 

 &b in main is          0xffbef30
 &b in block in main is 0xffbef28

 An analysis of the stack on Solaris:

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

#include <stdio.h>

int fac ( int n );

/* FYI: you can also have a foobar with external linkage and a foobar nested 
   in another function; e.g. this code will compile  
void foobar ( int w, int x )
{
   while ( w ) {
      int y, z;
      y = w;
      z = x + w;
      w--; 
   }
} */

int MAX=1;    // MAX is stored in the data section of the executable

// int numbers[100] = {0};

int main(void) {
   // grab b's address
   int a = MAX, b = 1, c = 1, x = 1;

   // look at how nested blocks are stored in stack
   while ( c ) {
      int b = 4;   // grab this b's address 
      a = 4;   
      c--;
    } 
// look at how stack dynamic arrays are stored on the stack
   printf("Enter size for stack dynamic array:");
   int sizea,i; 
   scanf ("%d",&sizea); 
   int A[sizea];    // the address to A is bound at runtime
   for (i = 0; i < sizea; i++)
      A[i]=i; 

   // a second stack dynamic array
   int sizeb; 
   printf("Enter size for stack dynamic array:");
   scanf ("%d",&sizeb);
   int B[sizeb];

   // demonstrate nested functions in GNU C
   // foo is nested in main and foobar is nested in foo
   void foo ( int i ) {
         int y = 1;
         while ( i )
            i--;
 
         void foobar () {
            x = 5;          // x is in main
            y = 2;          // y is in foo
            while ( y ){
                 y--;
            }
        } 
        foobar();
   }
   foo(a);

   // demonstrate recursion on the runtime stack
   fac(3);

   return 0;
}

int fac ( int n ) {
  int size;
  int numbers[100];
//  numbers[0] = 1; 
  if ( n <= 1 ) return 1;
  else return n * fac ( n - 1 );
}
