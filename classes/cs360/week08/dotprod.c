/* filename: dotprod.c

       $ gcc dotprod.c -lpthread
       $ ./a.out

   a threaded program to compute the dot product of two vectors; e.g.,
        a = <2,3,4>  and  b = <-1,3,5>
        _   _ 
        a . b = (2*-1)+(3*3)+(4*5) = -2+9+20 = 27.

   A mutex enforces mutual exclusion on the shared structure: lock before 
   updating and unlock after updating.

   The main program creates threads which do all the work and then print out 
   result upon completion. Before creating the threads, the input data is 
   created. The main thread needs to wait for all threads to complete, it 
   waits for each one of the threads. We specify a thread attribute value that 
   allow the main thread to join with the threads it creates. Note also that 
   we free up handles when they are no longer needed.
	 
   Each thread works on a different set of data. The offset is specified by 
   the loop variable 'i'. The size of the data for each thread is indicated by 
   VECLEN.
	
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
   int      *a;
   int      *b;
   int     sum; 
   int     veclen; 
} Dotdata;

#define NUMTHRDS 4
#define VECLEN 100
Dotdata dotstr; 
pthread_t callThd[NUMTHRDS];
pthread_mutex_t mutexsum;     /* use a mutex to protect the dot product */

/* thread function */
void *dotprod(void *arg)
{
   int i, start, end, len ;
   long offset;
   int mysum, *x, *y;
   offset = (long)arg;
     
   len = dotstr.veclen;
   start = offset*len;
   end   = start + len;
   x = dotstr.a;
   y = dotstr.b;

   mysum = 0;
   for (i=start; i < end ; i++) 
   {
      mysum += (x[i] * y[i]);
   }
   pthread_mutex_lock (&mutexsum);
   dotstr.sum += mysum;
   pthread_mutex_unlock (&mutexsum);
   pthread_exit((void*) 0);
}


int main (int argc, char *argv[])
{
   long i;
   int *a, *b;
   void *status;
   pthread_attr_t attr;

   /* Assign storage and initialize values in the vectors */
   a = (int*) malloc (NUMTHRDS*VECLEN*sizeof(int));
   b = (int*) malloc (NUMTHRDS*VECLEN*sizeof(int));
   for (i=0; i < VECLEN*NUMTHRDS; i++)
   {
      a[i]=1.0;
      b[i]=a[i];
    }

   dotstr.veclen = VECLEN; 
   dotstr.a = a; 
   dotstr.b = b; 
   dotstr.sum=0;

   pthread_mutex_init(&mutexsum, NULL);
         
   /* Create threads to perform the dotproduct  */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(i=0; i < NUMTHRDS; i++)
    {
        pthread_create(&callThd[i], &attr, dotprod, (void *)i);
	}

 	 pthread_attr_destroy(&attr);

   /* Wait on the other threads */
	 for(i=0; i<NUMTHRDS; i++)
   {
	      pthread_join(callThd[i], &status);
	 }

   /* After joining, print out the results and cleanup */
   printf ("Sum =  %d \n", dotstr.sum);
   free (a);
   free (b);
   pthread_mutex_destroy(&mutexsum);
   pthread_exit(NULL);
}   
