/* demonstrates some cool security violations you can achieve with pointers */

#include <stdio.h>
#include <stdlib.h>

void dbl_ptrs( int* *, int* *);  // passing pointers by ref (double pointers)
void remove_all_files( void *);    // void pointers are really useful 
void bitPrint(unsigned int n, int numBits);
char *btostr(unsigned int n, int numBits);

int main()
{
  /* simple pointer remove_all_files */
  int num = 1;
  int *iptr = &num;

  /* this increments num - dereferencing takes precedence over ++ */ 
   ++(*iptr);
  printf ("num: %d\n",*iptr);

  /* this increments iptr by the size of an int (4 bytes) */ 
  printf ("Before: %p\n",iptr);
  iptr++;
  printf ("After:  %p\n",iptr);

  /* sample output: 
  num: 2
  Before: ffbefa6c
  After:  ffbefa70  */

  /* note: pointer division or mult is illegal:  ip = ip / 2;  */
 
  /* this code demonstrates double pointers */
  int i; 
  int x = 10;
  int y = 15;
  int* xptr = &x;
  int* yptr = &y;
  dbl_ptrs( &xptr, &yptr);  
  printf ("x=10 ; value at xptr: %i \n", *xptr );
  printf ("y=15 ; value at yptr: %i \n", *yptr );

 
  double * f_array = (double *) malloc(sizeof(double[4])); 
  int * i_array = (int *) malloc(sizeof(int[4]));    
  printf ("starting address of double array: %p  \n", f_array );
  printf ("starting address of int array: %p  \n", i_array );

  for (i=0; i<4; i++){
     f_array[i] = 3.33 + i;
     i_array[i] = 100 + i;
  }
/*
  for (int i=0; i<4; i++){
     printf (" value: %d \n", i_array[i] );
  }  */
  remove_all_files( f_array );

  /* deallocate the memory */
  free(f_array);
  free(i_array);

  return 0;
}

void remove_all_files ( void * pxv)
{
  int i;
  double * pxf = (double *)pxv;
  int * pxi = (int *)pxv;
  printf ("address: %p  ", pxf );

  for (i=0; i<4; i++){
     printf (" value: %f \n", *pxf );
     pxf++;
  }

  pxi = (int *)pxf;  
  pxi = pxi + 64;
  
  /* 
  for (i=0; i<40; i++){
     printf ("address: %p  ", pxi );
     bitPrint(*pxi, 32);
     printf (" \n");
     pxi++;
  } */

}

/* pass two pointers by reference and swap their values */
void dbl_ptrs( int** dptr1, int** dptr2){
  int * tmp_ptr;
  tmp_ptr = *dptr1;  //  tmmp_ptr now holds the address of dptr1
  *dptr1 = *dptr2;   //  dptr1 now points to what dptr2 was pointing to 
  *dptr2 = tmp_ptr;  //  dptr2_ptr now points to what dptr1 was pointing to

}

void bitPrint(unsigned int n, int numBits)
{
    char *tmp;
    printf("%s ", tmp = btostr(n, numBits));
    /* in C++ the following line is:    delete [] tmp; */
    free(tmp);
}

char *btostr(unsigned int n, int numBits)
{
    unsigned int m;
    char *result, *t;

    /* in C++ the following line is:  result = new char [numBits+1];  */
    result = (char *) malloc(sizeof(char[numBits+1])); 
    t = result; 
    m = 1<<(numBits-1);
    while(m) {
      *t++ = (n&m) ? '1' : '0';
       m>>=1;
    }
    *t = '\0';

    return result;
}
