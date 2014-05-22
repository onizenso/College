#include "stdio.h"

 void junk (int n) {
        printf("%i ", n);
        if ( n > 0)
           junk (n-1);
    }
    // code B
    void junk2 (int n) {
        if ( n > 0)
           junk2 (n-1);
        printf("%i ", n);
    }
int main() {

   int i,j;
   int num = -1;
   while (num){
      printf("WHILE: %i ", num);
      num++;
   }

   for ( i = 0; i <= 3; i++) {
          j = 3 - i;
          switch (j) {
            case 3: printf("x");
            case 2: printf("x");   
            case 1: printf("x"); 
            case 0: printf("x");
            default: printf("\n");
          }
        }

       for ( i = 0; i <= 3; i++) {
          for ( j = 3 - i; j >= 0; j--)
             printf("x");
          printf("\n");
       }

    // code C
    int n = 4;
    while (n > 0) {
        printf("%i", n);
         n--;
    }
    printf("\nJunk: ");
    n = 4;
    junk(n);
    printf("\n Junk2:");
    junk2(n);


   return 0;
}
