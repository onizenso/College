/* /examples/week05/reader_writer.c
 *
 *  Uses shared memory, threads and semaphores to implement a solution 
 *  to a strong reader/ writer problem: one writer has exclusive use to shared 
 *  memory; one reader also has exclusive use to access shared memory. Your job 
 *  is to modify this program to create 2 writer threads and 3 reader threads -
 *  all with exclusive use.
 *
 *    $ gcc reader_writer.c -lpthread   # link in POSIX pthread library         
 *  or
 *     $ make
*/
                                                                           
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>

#define PERMS 0666
#define READER 0 
#define WRITER 1 

/*  this definition is required under all UNIXs except BSD to set value    */
union semun {
    int     val;            /* value for SETVAL  */
    struct  semid_ds *buf;  /* buffer for IPC_STAT & IPC_SET */      
    u_short *array;         /* array for GETALL & SETALL   */
}; 


/* these utility functions to make semaphore coding more readable. normally
 * you want to minimize function calls in systems coding - and you still  
 * need to understand the low-level semaphore operations 
 */
int sem_init(int size, int val);  
void reader_unlock(int);
void writer_unlock (int);
void reader_lock (int);
void writer_lock (int);
void writer_wait(int);
void removeid (int);
int fib(int);

/* thread functions return (void*) and pass (void *); you can cast anything 
    to (void *)  */
void *Writer(void *);  //  writer thread
void *Reader(void *);  // reader thread
void ctrlc_handler(int);

int seg_id, semid;
time_t now;    
void *mem_ptr;      

int main( void ) {

  /* create an a shared memory segment */
  seg_id = shmget ( IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666 );

  if ( seg_id == -1 )
       printf("error\n");   

  /* attach to segment and get a pointer to it */
  mem_ptr = shmat ( seg_id, NULL, 0 );

  /* create a semaphore pair, set both to 0 */ 
  semid = sem_init( 2, 0); 

  /* trap for CTRL-C - use sigaction in your code */
  signal(SIGINT, ctrlc_handler);


  /* create one Reader and one Writer thread. The Reader thread performs a 
     loop of read operations, reading only when the Writer has finished. 
     demonstrates the strong-reader preference protocol; e.g. the writer must 
     wait until the Reader finishes */

  pthread_t W1, W2, R1, R2, R3;

  if (  pthread_create( &W1, NULL,  Writer, (void *)"1" ) != 0)
      printf("Error creating thread\n");
  if (  pthread_create( &W2, NULL,  Writer, (void *)"2" ) != 0)
      printf("Error creating thread\n");
  
  if (  pthread_create( &R1, NULL,  Reader, (void *)"1" ) != 0)
      printf("Error creating thread\n");
  if (  pthread_create( &R2, NULL,  Reader, (void *)"2" ) != 0)
      printf("Error creating thread\n");
  if (  pthread_create( &R3, NULL,  Reader, (void *)"3" ) != 0)
      printf("Error creating thread\n");

   /* rejoin from threads */
  if (  pthread_join(W1, NULL) != 0 )
      printf("Error rejoining from thread\n");
  if (  pthread_join(W2, NULL) != 0 )
      printf("Error rejoining from thread\n");

  if (  pthread_join(R1, NULL) != 0 )
      printf("Error rejoining from thread\n");
  if (  pthread_join(R2, NULL) != 0 )
      printf("Error rejoining from thread\n");
  if (  pthread_join(R3, NULL) != 0 )
      printf("Error rejoining from thread\n");

  /* parent cleans up */
  sleep(5);
  removeid( semid);                // remove semaphore set
  shmctl( seg_id, IPC_RMID, NULL);  // remove shared memory

} // end main


/*  Reader function reads from shared memory */
void *Reader( void * num)
{
  int i;
  pid_t tid;
  tid = syscall(SYS_gettid);      
  printf("create reader thread pid: %d tid: %d \n",getpid(), tid);

  /* should make loop random when you have multiple threads-fixed at 3 now */
  for (i=1; i<= 3; i++){
     int zsems = semctl(semid, WRITER, GETZCNT);
     
     if(zsems > 0){
        reader_lock( semid );
        fib(20);
        printf("reader #%s  %s", (char *)num, mem_ptr); 
        reader_unlock( semid );
     }
  }
  pthread_exit(0);
}

int fib(int start){
    if(start == 0)
        return 0;
    if(start == 1)
        return 1;
    return fib(start-1)+fib(start-2);
}


/* Writer function writes time to shared memory */
void *Writer( void * num )
{
   int i;
   pid_t tid;
   tid = syscall(SYS_gettid);      
   printf("create writer thread pid: %d tid: %d \n",getpid(), tid);

  /* make the loop random when you have multiple threads */
  for ( i=1; i<= 3; i++){
    writer_lock(semid);
    time( &now);
    strcpy((char *)mem_ptr, ctime(&now) );  
    printf("writer #%s  %s", (char *)num, mem_ptr); 
    writer_unlock( semid );  
    sleep(1);
  }
  pthread_exit(0);
}

void ctrlc_handler(int sig)
{
  union semun dummy;      
  semctl(semid, 0, IPC_RMID, dummy);
  shmctl( seg_id, IPC_RMID, NULL); 
}


int sem_init( int nsems, int val )
{
   int id;
   union semun initval;
   initval.val = val;

   /* create a semaphore set if one doesn't already exist
      of nsems and mode rw-rw-rw */
   id = semget( IPC_PRIVATE, nsems, (PERMS|IPC_CREAT|IPC_EXCL) ); 
   if ( id == -1)
      printf("error creating semaphore\n"); 

   /*  set semaphore element values to incoming val */ 
   int i;
   for (i=0; i < nsems; i++ ) {
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

   /* increment n_readers so Writer knows if there are waiting Readers */
   get_in_line[0].sem_num = READER;  
   get_in_line[0].sem_flg = SEM_UNDO;  
   get_in_line[0].sem_op  = +1;        

   if ( semop(id, get_in_line, 1) == -1 )
       printf("error updating reader wait list semaphore\n");


   /* between the above semop and the next semop - any number of readers could
      have jumped in - Writers at this point are blocked  */

   /* wait on any writing Writers */
   wait_on_writer[0].sem_num = WRITER;  
   wait_on_writer[0].sem_flg = SEM_UNDO;  
   wait_on_writer[0].sem_op  = 0;          

  if ( semop (id, wait_on_writer, 1) == -1 )
       printf("error locking reader semaphore\n");
}

void writer_lock( int id ) 
/* wait for 0 on n_readers and 0 on n_writers and increment n_writer */
{
   struct sembuf wait[3];   /* 3 semaphore operations performed atomically */

   wait[0].sem_num = READER;  
   wait[0].sem_flg = SEM_UNDO;  
   wait[0].sem_op  = 0;            // wait for n_readers = 0

   wait[1].sem_num = WRITER;  
   wait[1].sem_flg = SEM_UNDO;   
   wait[1].sem_op  = 0;            // wait for n_writers = 0

   wait[2].sem_num = WRITER;  
   wait[2].sem_flg = SEM_UNDO;  
   wait[2].sem_op  = +1;           // n_writers will never be greater than 1

  if (semop (id, wait, 3) == -1 )
       printf("error locking writer semaphore\n");
}

void writer_wait( int id )
{
    struct sembuf writeWait[3];

    writeWait[0].sem_num = READER;
    writeWait[0].sem_flg = SEM_UNDO;
    writeWait[0].sem_op = 0;        //wait for n_readers ( {...}.sem_op=1 waits for 1 reader ) 
    
    writeWait[1].sem_num = WRITER;
    writeWait[1].sem_flg = SEM_UNDO;
    writeWait[1].sem_op = 1;        //wait for n_writers ( {...}.sem_op=1 waits for 1 writer ) 
}


void reader_unlock( int id ) 
/* set operation buffer and call release operation for sem_num */ 
{
   struct sembuf release[1];  /* holds one semaphore operation */

   release[0].sem_num = READER;  
   release[0].sem_flg = SEM_UNDO;  
   release[0].sem_op  = -1;     /* decrement the number of readers */           

   if ( semop(id, release, 1) == -1 )
       printf("error unlocking reader semaphore\n");
}

void writer_unlock( int id ) 
/* set operation buffer and call release operation for sem_num */ 
{
   struct sembuf release[1];  /* one semaphore operation to release sem */

   release[0].sem_num = WRITER;  
   release[0].sem_flg = SEM_UNDO; 
   release[0].sem_op  = -1; 
   if ( semop ( id, release, 1) == -1 )
       printf("error unlocking writer semaphore\n");
}


void removeid( int id ) 
/* remove semaphore set */ 
{
  union semun initval; 
  if ( semctl(id, 0, IPC_RMID, initval) == -1 )
       printf("error removing semaphore\n");
}

/* end reader_writer.c */
