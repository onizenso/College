/* filename:    main.c     
   project:     "strong reader writer problem" 
   description:  example of passing functions as parameters and concurrent
                 programming using threads  

*/

#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include "semaphore.h"

#define MEM_KEY 99

void *Writer(void *);  //  writer thread
void *Reader(void *);  // reader thread
void cleanup(int);

int seg_id, sem_id;
time_t now;    
void *mem_ptr;         // shared memory location

int main() {

  /* create a shared memory segment */
  seg_id = shmget ( MEM_KEY, ((size_t)100), IPC_CREAT|0777 ); 

  if ( seg_id == -1 )
       printf("error\n");   

  /* attach to it and get a pointer to where it attaches */
  mem_ptr = shmat ( seg_id, NULL, 0 );


  /* create a semaphore pair, set both to 0*/ 
  sem_id = sem_init( 2, 0); 

  /* trap for CTRL-C */
  signal(SIGINT, cleanup);


  /* create three Reader and and two Writer threads. each Reader thread
     performs a loop of read operations. demonstrates the strong-reader 
     preference protocol; e.g. Writer #2 must wait until R2 and R3 finish */

  pthread_t W1, W2, R1, R2, R3;

  /* PASSING FUNCTIONS AS PARAMETERS IN C:
 
  void *Writer(void *); <= the return type and parameter types in this function 
  prototype must match the third parameter in the prototype for pthread_create:

  int pthread_create(pthread_t *thread,  const  pthread_attr_t *attr, 
  void *(*start_routine, void*),void *arg);   */


  if (  pthread_create( &W1, NULL,  Writer, (void *)"1" ) != 0)
      printf("Error creating thread\n");

  if (  pthread_create( &R1, NULL,  Reader, (void *)"1" ) != 0)
      printf("Error creating thread\n");

  if (  pthread_create( &W2, NULL,  Writer, (void *)"2" ) != 0)
      printf("Error creating thread\n");

  if (  pthread_create( &R2, NULL,  Reader, (void *)"2" ) != 0)
      printf("Error creating thread\n");

  if (  pthread_create( &R3, NULL,  Reader, (void *)"3" ) != 0)
      printf("Error creating thread\n");


   /* rejoin from threads */
  if (  pthread_join(W1, NULL) != 0 )
      printf("Error rejoining from thread\n");

  if (  pthread_join(R1, NULL) != 0 )
      printf("Error rejoining from thread\n");

  if (  pthread_join(W2, NULL) != 0 )
      printf("Error rejoining from thread\n");

  if (  pthread_join(R2, NULL) != 0 )
      printf("Error rejoining from thread\n");

  if (  pthread_join(R3, NULL) != 0 )
      printf("Error rejoining from thread\n");


  /* parent cleans up */
  sleep(5);
  removeid( sem_id);                    // remove semaphore set
  shmctl( seg_id, IPC_RMID, NULL);  // remove shared memory

} // end main


/*  Reader function reads from shared memory */
void *Reader( void * num)
{
  int i;
  for (i=1; i<= 3; i++){
     reader_lock( sem_id );
     printf("reader #%s  %s", (char *)num, mem_ptr); 
     sleep(1);  
     reader_unlock( sem_id );
  }
}


/* Writer function writes to shared memory */
void *Writer( void * num )
{
   writer_lock(sem_id);
   time( &now);
   strcpy((char *)mem_ptr, ctime(&now) );  
   printf("writer #%s  %s", (char *)num, mem_ptr); 
   writer_unlock( sem_id );  
}

void cleanup(int id)
/* call only if a CTRL-C pressed */
{
  union semun dummy;      
  semctl(sem_id, 0, IPC_RMID, dummy);
  shmctl( seg_id, IPC_RMID, NULL); 
}
