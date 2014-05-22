/* filename: gdb-demo.c
   purpose: demonstrate use of gdb debugger
   $ gcc -o demo -g gdb-demo.c  # use -g switch to compile with debugging flags
   $ gdb demo */

#include <stdlib.h>

int x = 3;
 
int fac ( int n ) 
{
   int * iptr = (int *) malloc(sizeof(int));
   *iptr = n;
   if ( n <= 1 ) return 1;
   else return n * fac ( n - 1 );
}

int main ()
{
   int stuff = 77;  /* put something in main's stack frame */
   fac(x);
   return 0;
}

