/* d meyers  

 Tests the efficiency of static vs. stack-dynamic local variables. 
 A static matrix and a stack-dynamic matrix are filled with random numbers. 
 Matrix multiplication is performed on both matrices, and accesses are 
 counted accesses for 1 minute. The higher the count the more efficient the
 method:  

 Static accesses/sec  Stack accesses/sec
                58718           53506
                58719           51030
                58720           56559
                58721           59307
                58722           50119
                58723           53352
                58724           50333
                58725           54222
                58726           51906
                58727           52551

 The expectation is that operations on a statically allocated matrix should
 be more efficient than operations on a matrix allocated on the runtime stack.
 The numbers are close because 
 1. on the Sparc architecture 64K of the runtime stack is on the processor chip
 2. accesses to arrays are pipelined and thus extremely efficient
*/

#include <stdio.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>

#define DIMEN 7  // the number of columns in a and rows in b
#define ROW 7    // the number of rows in a
#define COL 7    // the number of columns in b
#ifndef CLK_TCK
#define CLK_TCK 60            /* number clock ticker per second */
#endif


// declare and initialize static matrices
static int c[DIMEN][COL];   // holds the result
static int a[ROW][DIMEN] = {
   { 1,1,1,1,1,1,1 },
   { 2,2,2,2,2,2,2 },
   { 3,3,3,3,3,3,3 },
   { 4,4,4,4,4,4,4 },
   { 5,5,5,5,5,5,5 },
   { 6,6,6,6,6,6,6 },
   { 7,7,7,7,7,7,7 }
};

/* in C, n-dimensions are unwound to 1-dimension so you can also do this:*/
static int b[DIMEN][COL] = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7 ,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7};


void test ( );  

double get_seconds() {     
   struct tms rusage;
   times(&rusage);          /* UNIX utility: time in clock ticks */
   return (double) (rusage.tms_utime)/CLK_TCK;
}

int static_total = 0;
int stack_total = 0;

int main( )
{
  double sec, sec0; 
  int t, i, j, k;
  int n_cnt = 0;
  sec = 0;
  printf("\n\t\tCounting accesses (more is better)\n");
  printf("\tStatic accesses/sec\tStack accesses/sec\n");

int num = 10;
while (num > 0){
  do { 
     sec0 = get_seconds();       /* start timer */ 
   
     /* multiply matrix a with matrix b */
  
     for ( i = 0; i < ROW; i ++ ) {   // for every row i in matrix a
       for ( j = 0; j < COL; j++ )   // for every column j in matrix b
       {
         t = 0;
         for ( k = 0; k < DIMEN; k ++ )  // multiply a_i row with b_j column
            t = t + a[i][k] * b[k][j];   // sum the result in i,j
         c[i][j] = t;
       }
     }
     n_cnt++;
     sec = sec + (get_seconds() - sec0);     // grab time
  } while ( sec < 1.0 );  // loop for 1 second

  printf("\t\t%d", n_cnt);
  static_total += n_cnt;
  test();
  num--;

}
  printf("\t\t===========\t=============");
  printf("\n\t\t%d\t\t%d\n", static_total/10, stack_total/10);
  return 0;
} 
//===========================================================================
void test ( ) {

int c[DIMEN][COL];   // holds the result
int a[ROW][DIMEN] = {
   { 1,1,1,1,1,1,1 },
   { 2,2,2,2,2,2,2 },
   { 3,3,3,3,3,3,3 },
   { 4,4,4,4,4,4,4 },
   { 5,5,5,5,5,5,5 },
   { 6,6,6,6,6,6,6 },
   { 7,7,7,7,7,7,7 }
};

int b[DIMEN][COL] = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7};


  double sec, sec0; 
  int t,i,j,k;
  int n_cnt = 0;
  sec = 0;

  do { 
     sec0 = get_seconds();       /* start timer */ 
   
     /* multiply matrix a with matrix b */
     for ( i = 0; i < ROW; i ++ ) {   // for every row i in matrix a
       for ( j = 0; j < COL; j++ )   // for every column j in matrix b
       {
         t = 0;
         for ( k = 0; k < DIMEN; k ++ )  // multiply a_i row with b_j column
            t = t + a[i][k] * b[k][j];   // sum the result in i,j
         c[i][j] = t;
       }
     }
     n_cnt++;
     sec = sec + (get_seconds() - sec0);     // end timer 
  } while ( sec < 1.0 );  // loop for 1 second

  printf("\t\t%d\n", n_cnt);
  stack_total += n_cnt;
} 
