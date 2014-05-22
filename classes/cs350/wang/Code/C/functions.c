/* demonstrate how C passes pointers and functions as parameters */

#include <stdio.h>
#include <stdlib.h>

int test ( int * iptr ) { int i = 7; return i;}

int stuff ( int *, int (*func)(int *));  // a function passing a function

int main()
{
  int i = 6;
  int* iptr = &i;
  stuff(iptr,test);
  printf("value of i:%d\n",*iptr);
  return 0;
}


int stuff ( int *iptr, int (*func)( int* iptr))
{
   (*func) (iptr);

   return 0;  

}

