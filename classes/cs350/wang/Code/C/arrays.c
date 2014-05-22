#include <stdlib.h>
#include <stdio.h>

/* filename:    arrays.c 

 Demonstrate the various ways of allocating arrays.

 Demonstrate accessing elements in n-dimen arrays w/o subscript notation.

 Note: some of this code is not ANSI-C compliant; for example, in ANSI C
 all variables must be declared before any executable code. ANSI C does
 not support just-in-time declaration.      */


/* In ANSI C the only way to initialize a static array with a variable is to
  use a 'define' to set the dimensions */
#define n 7     /* the number of columns in a and rows in b  */
#define arow 7  /* the number of rows in a  */
#define bcol 7  /* the number of columns in b */

static int i_array[5] = {1,2,3,4,4};      

/* the number of columns is required in parameter list of 2-dimen array */
void print_array(int [][n]);

void stuff();


/* declare and initialize 7x7 matrix */
static int a[arow][n] = {
   { 1,1,1,1,1,1,1 },
   { 2,2,2,2,2,2,2 },
   { 3,3,3,3,3,3,3 },
   { 4,4,4,4,4,4,4 },
   { 5,5,5,5,5,5,5 },
   { 6,6,6,6,6,6,6 },
   { 7,7,7,7,7,7,7 }
};

/* declare and initialize another 7x7 matrix */
static int b[n][bcol] = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7};

/* a matrix to hold the result */
static int c[n][bcol];   

// MAIN 
int main( int argc, char *argv[] )
{
  int t,i,j,k;
 
  /* multiply matrix a with matrix b */

  for ( i = 0; i < arow; i ++ )    // for every row i in matrix a 
    for ( j = 0; j < bcol; j++ )   // for every column j in matrix b
    { 
      t = 0;
      for ( k = 0; k < n; k ++ )  // multiply a_i row with b_j column 
         t = t + a[i][k] * b[k][j];   // sum the result in i,j 
      c[i][j] = t;
    }

  printf("multiply matrix a with matrix b, store result in c:\n");
  print_array(a);
  print_array(b);
  print_array(c);


  /* declare, init and print a 3-dimensional array */
  /* 3-dimen arrays are in x,y,z order; e.g. row,col,depth */ 
  int cube[2][3][4];
  int x,y,z;
  printf("2x3x4 dimensional array:\n");
  for ( x = 0; x < 2; x++ ) 
     for ( y = 0; y < 3; y++ )  {
        for ( z = 0; z < 4; z ++ ) { 
            // insert the offset as the value into the cube 
           cube[x][y][z] = (x*(3*4))+(4*y)+ z;
           printf("%4d ", cube[x][y][z]);
        }
        printf("\n");
      }
   printf("\n");

  /* declare a 4x5 2-dimensional array with a single pointer to access it */
  int * iptr = (int *) malloc(sizeof(int[4][5]));

  printf("\ntreat the 4x5 array like a single dimensional array:\n");
  int offset = 0;
  int r,c;
  int * tmp = iptr;
  /* rows = 4  columns = 5 */
  for (r = 0; r < 4; r++) {
     for (c= 0; c < 5; c++) {
        offset = r*5+c;
        tmp += offset;
        *tmp = offset;
         printf("%4d ", *tmp );
         // the next two lines would also work
         // iptr[offset] = offset; 
         // printf("%4d ", iptr[offset] );
     }
     printf("\n");
  }


  /* declare a "jagged" array; e.g. an array of pointers */
  int *jagged[3];
  /* create some arrays to load into the jagged array  */
  int ar0[5] =  {1,2,3,4,5};
  int ar1[2] =  {1,2};
  int ar2[4] =  {1,2,3,4};
  // create the "jagged" array
  jagged[0] = ar0;
  jagged[1] = ar1;
  jagged[2] = ar2;
  /* display the second element from array 0: */
  printf("\nThe 2nd element in 1st jagged array s/b 2: %4d \n", jagged[0][1]);


  return 0;
} 

/* print array in row-major order  */
void print_array(int array[][n] ) {
  int i,j;
  for (i = 0; i < n; i ++ ) {
     for (j = 0; j < bcol; j ++ )  {
        printf("%4d ", array[i][j]);
     }
     printf("\n");
  }
  printf("\n");
}

void stuff()
{
  int size;
  int COL = 6;
  int ROW = 5;
  int matrix[ROW][COL]; 
  int * address = (int *)matrix;          // set ptr to lower-bound

  /* access the [3][2] element in that array without subscript notation ;
  this is the 21st element, thus must add 20 to lower bound: 3*6+2 = 20 */

  int i = 3;
  int j = 2;
  address = address + (i * COL) +j;
  *address = 5;
  /* test by accessing that location in subscript notation */
  printf("\n%i\n",matrix[i][j]);

  /* array allocation methods */

  int * f_array = (int *) malloc(sizeof(int[5]));  // fixed heap dynammic

  printf("Enter size for heap dynamic array: ");
  scanf ("%d",&size); 
  int * h_array = (int *) malloc(sizeof(int[size]));  // heap dynammic

  free(h_array);
 
  static int s_array[5] = {1,2,3,4,4};           // also static 

  int i_array[5] = {1,2,3,4,4};                  // fixed stack-dynamic 
                                 
  printf("Enter size for stack dynamic array: ");
  scanf ("%d",&size); 
  int sd_array[size];                               // stack-dynamic 

  // note: ANSI C does not support stack-dynamic arrays but GNU C does

}

