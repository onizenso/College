/* fib.c
 * demonstrate gcc compiler's AT&T x86
 *
 * $ gcc -S fib.c
 * $ gcc fib.s -o fib
 * $ ./fib
 *
*/
 
#include <stdlib.h>
#include <stdio.h>

int fib(int n)
{
  if (n == 0) return 1;
  if (n == 1) return 1;
  else return fib(n-1) + fib(n-2);
}

int main(int argc, char **argv)
{
  int n = atoi(argv[1]);
  int result = fib(n);
  printf("fib %d is %d \n", n, result);
  return 0;
}
