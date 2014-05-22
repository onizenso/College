/*filename: myhack.c */
#include <stdio.h>

void good_code() {
   int c = 10;
   printf("From good code: %d", c);
}
void bad_code() {
  asm("nop"); 
}

int main(void) {
   int c = 5;
   bad_code();
   good_code();
   printf("From main: %d", c);
   return 0;
}

/* OUTPUT FROM  gcc -S myhack.c 

*/
