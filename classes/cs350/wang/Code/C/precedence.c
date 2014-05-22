/* cmps 350 ch 7 expressions and assignment statements
   demonstrate operator precedence, associativity, function side-effects */

#include <stdio.h>

int fun( int * );

int main()
{

   int a, b, c, d;
   int n[5] = {0,2,4,6,8};
   int *ip = &n[0];

   /* demonstrate various operator precedence and associativity */
   printf ("\nArray: {0,2,3,6,8}\n");
   printf (" *(ip + 1): %p %d \n", ip, *(ip + 1) );
   printf (" *ip + 1  : %p %d \n", ip, *ip + 1 );
   printf (" ip + 1   : %p %p \n", ip, ip + 1 );

   a = 7; b=3;
   c = a % b * 4;
   printf ("\na(7) mod b(3) * 4 : %d \n", c);

   /* demonstrate undefined behavior */
   int count = 5;
   count= -count++; // <== count incremented then negated is undefined
   printf ("\n(5)-count++: %d \n", count);


   /* demonstrate unexpected behavior of relational operators */
   a = -5; b = -3; c = 0;
   if ( a < b > c)  
       printf ("\nTrue: %d < %d > %d\n", a, b, c );  
   else
       printf ("False: %d < %d > %d\n", a, b, c );  


  /* when using increment and decrement operators, do not depend on the order 
     of evaluation of expressions. It is unspecified whether the value of j 
     in n[j] is evaluated before or after j is incremented. To avoid ambiguity,
     increment the variable in a separate statement. */
  
     int j=0;
     c = n[j] + j++;   // value undefined
     printf ("\n n[j] + j++: %d\n", c );     


   /* demonstrate functional side effects */
   a = 10;
   b = a + fun(&a);  /* assume that fun changes a to 5 and also returns it*/
   printf ("\nb: %d \n", b );

   
   return 0;
}


int fun( int * x){
  return *x = 5;
}

/*
Array: {0,2,3,6,8}
 *(ip + 1): ffbef990 2
 *ip + 1  : ffbef990 1
 ip + 1   : ffbef990 ffbef994

a(7) mod b(3) * 4 : 4

True: -5 < -3 > 0

b: 10
*/
