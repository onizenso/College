/* demonstrate how C handles the heap, stack and data section */

#include <stdio.h>
#include <stdlib.h>

double d = 3.5;

void test ( ){
   double d = 3.5;
   double d2 = 3.5;
   printf ("\naddress of stack dynamic double 1: %p ", d );
   printf ("\naddress of stack dynamic double 2: %p ", d2 );
}

int main()
{

  printf ("address of static double: %p ", d );
  test();
 
  /* the cast to double is done to align the memory properly */
  float * f_array = (float *) malloc(sizeof(float[4])); 
  printf ("\naddress of heap dynamic float array: %p  ", f_array );
  double * d_array = (double *) malloc(sizeof(double[20])); 
  printf ("\naddress of heap dynamic double array: %p  ", d_array );
  printf ("\n" );

  free(f_array);   // free the memory in the heap
  free(d_array);   // free the memory in the heap

  return 0;
}

/* 
starting address: 20af8
starting address: 20af8
*/
