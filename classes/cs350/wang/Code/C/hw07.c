/* filename: hw07.c
   compile with: gcc -lm hw07.c
   Demonstrates concepts surrounding expressions and assignment statements 
   note: this code is not ANSI C so compile with gcc 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bitops ( int x, int y);
void swap( void ** ptr1, void ** ptr2);
void bitPrint(unsigned int n, int numBits);
char *btostr(unsigned int n, int numBits);

enum { ROW=3, COL=4 };

int main() {

  // under ANSI C all variables must be declared before executable code
  // but GNU C lets you get away with it..
  float x;
  int i = 3, j, count,m,num;
  int offset = 0;
  double n;
  int count1, count2;

  // C supports four modifiers for int, float, char, double:
  // short, long, signed, unsigned 

  unsigned int u_int;

  // dynamically allocate a 3x4 matrix of ints 
  int * i_array = (int *) malloc(sizeof(int[ROW][COL])); 

  // ex. of mixed mode assignment with widening coercion of int to float 
  // (a coercion is an implicit conversion)
  x = i;
  printf ("\nWidening coercion of %d to %f \n", i,x );

  // explicit conversion with a cast
  x = 56.0 / (float)i;
  printf ("\nExplicit conversion 56 / 3.0 : %f  \n", x );

  // narrowing coercions can also occur if the range of values is reduced
  short s_short;  // 2 bytes
  int i_int = __INT_MAX__;  // 4 bytes
  s_short = i_int;
  printf ("Narrowing coercion of i_int %d to s_short %d \n", i_int, s_short);

  // determine and display the size of a pointer variable
  printf ("size of pointer variable: %d  \n", sizeof(char *) );

  // use printf %p to display the starting and ending address of the int array
  printf ("\nstarting address of int array: %p  ", i_array );
  printf ("\nending address of int array  : %p  \n", i_array + 11 );

  /* use pointer arithmetic (e.g. not subscript notation) and loops to 
     initialize the array with these values: 

   1  2  3  4
   2  3  4  5  
   4  5  6  7   */

 /* The function for these values is 2^i + j, where i loops through the rows
    and j loops through the columns.
    Note how C handles coercion and mixed mode assignment for the pow funtion:
    double pow(double,double);    */

  for (i=0; i<ROW; i++){
      for (j=0; j<COL; j++){
          /* compute offset */ 
          offset = (i * COL) + j;
          /* find value */ 
          *(i_array + offset) = pow(2,i) + j;
      }
  }

  // use subscript notation to display the values in the matrix 
  for (i=0; i<ROW; i++){
      for (j=0; j<COL; j++){
          /* compute offset */ 
          offset = (i * COL) + j;
          printf (" %d ", i_array[offset] );
      }
      printf ("\n");
  }
  printf ("\n");

  // deallocate the memory 
  free(i_array);

  // test how C handles overflow 
  num = __INT_MAX__;
  printf("\n__INT_MAX__  : %d\n",__INT_MAX__);
  bitPrint(num, 32);
  num++;
  printf("\n__INT_MAX__++: %d\n",num);
  bitPrint(num, 32);
  printf("\n ");


  printf ("\nTest bitwise operators:\n");
  bitops (5,5);
  bitops (101,7);
  bitops (5,10);

  // demonstrate what happens with -count++; e.g. AVOID undefined behavior!!
  count = 5;
  count= -count++;   // under gnu gcc it is -4 ; under digital ANSI C it is 6 
  printf ("\nfor count=5, -count++ is: %d",count);

 // C/C++ support both widening and narrowing coercions in assignments
  m = 2;   // m is an int
  n = 32.345;   // this is a double
  m = n; 
  n = m; 
  printf("\nNarrowing coercion in '=', 32.345 has lost precision: %f\n",n);

  // associativity of C's relational operators is left to right 
  // left operator is evaluated to 0 or 1 and then compared with third operand 
  int a=3, b=2, c=1; 
  printf("\nThe use of anything for T and 0 for F gives you enough rope to hang yourself :"); 
  printf("\n3 < 2 < 1 is %d\n",a < b < c);  // the result is '1'
  printf("\n3==2==0 is %d\n",3 == 2 == 0);  // the result is '1'
  
  // C supports short circuit evaluation of Boolean expressions
  int op1=0;
  while (op1 && (10/op1) );   // this would produce runtime error otherwise

  //  call a function to swap the addresses in two pointers
  // void swap( void ** ptr1, void ** ptr2);
  int n1 = 10, n2 = 20;
  int *ptr1 = &n1;
  int *ptr2 = &n2;
  swap((void **)&ptr1,(void **)&ptr2);
  printf ("\nn1 is 10:  %d ", *ptr1);
  printf ("\nn2 is 20:  %d ", *ptr2);
  printf ("\n");

  // note: conditional target on assignment is not supported in ANSI C 
  // the ternary conditional operator is
  printf("demonstrate ternary conditional operator used in assignment..\n");  
  printf("count1 should be 100\n");  
  int flag = 1;
  count1 = 0; count2 = 0;
  count1 = (flag) ? 100 : 200;
  printf ("count1: %d  count2: %d\n", count1, count2);
 
  // use of comma sequencing operator 
  n1 = n2=30, n1 + n2;  // this will assign  n1 the value of 30 + n2
  printf("Demonstrate comma sequencing operator: %d\n",n1);  
  printf("Every expression in C returns a number: %d\n", (5 > 3) );  
 
  return 0;
}

// demonstrate bitwise operators & | and ^ 

void bitops ( int x, int y){
  printf ("\nX: ");
  bitPrint(x,10);
  printf (" Y: ");
  bitPrint(y,10);
  printf("\n&: "); 
  bitPrint(x&y,10);
  printf(" |: "); 
  bitPrint(x|y,10);
  printf(" ^: "); 
  bitPrint(x^y,10);
  printf ("\n");

}

// if you want to swap pointer addresses in a function use double pointers
void swap( void ** ptr1, void ** ptr2){

  void * tmp_ptr = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp_ptr; 
   
}


void bitPrint(unsigned int n, int numBits)
{
    char *tmp;
    printf("%s ", tmp = btostr(n, numBits));
    free(tmp);    //delete [] tmp;  
}

char *btostr(unsigned int n, int numBits)
{
    unsigned int m;
    char *result, *t;

    result = (char*) malloc(sizeof(char[numBits+1]));
    t = result;

    m = 1<<(numBits-1);
    while(m) {
      *t++ = (n&m) ? '1' : '0';
       m>>=1;
    }
    *t = '\0';

    return result;
}
