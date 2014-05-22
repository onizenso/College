/* filename: reader_writer.c
   project:  use shared memory, threads and semaphores to implement a solution 
   to the strong reader/writer problem  */

     $ gcc reader_writer.c -lpthread   # link in pthread library
*/

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define PERMS 0666
#define READER 0 
#define WRITER 1 

/* this definition is required under all UNIXs except BSD  */
union semun {
        int     val;            // value for SETVAL 
        struct  semid_ds *buf;  // buffer for IPC_STAT & IPC_SET      
        u_short *array;         // array for GETALL & SETALL       
}; 

#define MEM_KEY 99

/* some utility functions to make semaphore use less painful */
int sem_init(int size, int val);  
void reader_unlock(int);
void writer_unlock (int);
void reader_lock (int);
void writer_lock (int);
void removeid (int);

/* thread functions must return void* and pass void */
void *Writer(void *);  //  writer thread
void *Reader(void *);  // reader thread
void ctrlc_handler(int);

int seg_id, sem_id;
time_t now;    
void *mem_ptr;         // shared memory location

int main() {

  /* create a shared memory segment */
  seg_id = shmget ( MEM_KEY, ((size_t)100), IPC_CREAT|0777 ); 

  if ( seg_id == -1 )
       printf("error\n");   

  /* attach to it and get a pointer to it */
  mem_ptr = shmat ( seg_id, NULL, 0 );

  /* create a semaphore pair, set both to 0*/ 
  sem_id = sem_init( 2, 0); 

  /* trap for CTRL-C */
  signal(SIGINT, cleanup);


  /* create three Reader and and two Writer threads. each Reader thread
     performs a loop of read operations. demonstrates the strong-reader 
     preference protocol; e.g. Writer #2 must wait until R2 and R3 finish */

  pthread_t W1, W2, R1, R2, R3;

 
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

void ctrlc_handler(int sig)
{
  union semun dummy;      
  semctl(sem_id, 0, IPC_RMID, dummy);
  shmctl( seg_id, IPC_RMID, NULL); 
}


int sem_init( int sem_size, int val )
{
   int id;
   union semun initval;
   initval.val = val;

   /* create a semaphore set if one doesn't already exist
      of sem_size and mode rw-rw-rw */
   id = semget( IPC_PRIVATE, sem_size, (PERMS|IPC_CREAT|IPC_EXCL) ); 
   if ( id == -1)
      printf("error creating semaphore\n"); 

   /*  set semaphore element values to incoming val */ 
   int i;
   for (i=0; i < sem_size; i++ ) {
      if (semctl(id, i, SETVAL, initval) == -1)
         printf("error setting semaphore value\n");
   }
   /* return the semaphore id */
   return id;
}

void reader_lock( int id ) 
/* sets the operation buffer for wait and lock operations used by Reader
   threads. a Reader waits only if a Writer is writing, otherwise jumps
   in. the operation to update the number of waiting Readers and the
   operation to wait on a Writer are not atomic  */ 
{
   struct sembuf get_in_line[1];
   struct sembuf wait_on_writer[1];

   /* increment n_readers so a waiting Writer knows there are waiting Readers */
   get_in_line[0].sem_num = READER;  
   get_in_line[0].sem_flg = SEM_UNDO;  
   get_in_line[0].sem_op  = +1;        

   if ( semop ( id, get_in_line, 1) == -1 )
       printf("error updating reader wait list semaphore\n");


   /* wait on any writing Writers */
   wait_on_writer[0].sem_num = WRITER;  
   wait_on_writer[0].sem_flg = SEM_UNDO;  
   wait_on_writer[0].sem_op  = 0;          

  if ( semop ( id, wait_on_writer, 1) == -1 )
       printf("error locking reader semaphore\n");
}

void writer_lock( int id ) 
/* wait for 0 on n_readers and 0 on n_writers and increment n_writer */
{
   struct sembuf wait[3];

   wait[0].sem_num = READER;  
   wait[0].sem_flg = SEM_UNDO;  
   wait[0].sem_op  = 0;            // wait for n_readers = 0

   wait[1].sem_num = WRITER;  
   wait[1].sem_flg = SEM_UNDO;   
   wait[1].sem_op  = 0;            // wait for n_writers = 0

   wait[2].sem_num = WRITER;  
   wait[2].sem_flg = SEM_UNDO;  
   wait[2].sem_op  = +1;           // increment n_writers

  if ( semop ( id, wait, 3) == -1 )
       printf("error locking writer semaphore\n");
}


void reader_unlock( int id ) 
/* set operation buffer and call release operation for sem_num */ 
{
   struct sembuf release[1];

   release[0].sem_num = READER;  
   release[0].sem_flg = SEM_UNDO;  
   release[0].sem_op  = -1;                 // decrement reader count 

   if ( semop ( id, release, 1) == -1 )
       printf("error unlocking reader semaphore\n");
}

void writer_unlock( int id ) 
/* set operation buffer and call release operation for sem_num */ 
{
   struct sembuf release[1];

   release[0].sem_num = WRITER;  
   release[0].sem_flg = SEM_UNDO; 
   release[0].sem_op  = -1; 
   if ( semop ( id, release, 1) == -1 )
       printf("error unlocking writer semaphore\n");
}


void removeid( int id ) 
/* remove entire semaphore set */ 
{
  union semun initval; 
  if ( semctl(id, 0, IPC_RMID, initval) == -1 )
       printf("error removing semaphore\n");
}
