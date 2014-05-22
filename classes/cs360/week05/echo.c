/* filename: echo.c
 *
 *  Demonstrate classic producer/consumer problem; the parent thread (the 
 *  producer) reads one character at a time from a file into a shared variable
 *         volatile int ichar;  
 *  The consumer copies the value to this variable
 *         volatile int ochar = 'a'; 
 *  The consumer then echos it to stdout and to a file. With no synchronization,
 *  the consumer will stutter or completely miss characters. The output is also
 *  not deterministic - output varies across executions. 
 *
 *  This is a problem of concurrency. When two threads access shared resources 
 *  without synchronization it is a race condition as to which thread gets 
 *  there first or next. Without synchronization, the consumer may read a value
 *  multiple times (empty buffer) or the producer overwrite a value before the 
 *  consumer had a chance to read it. 
 *
 *      $ gcc -o echo echo.c -lpthread   # link in POSIX pthread library  
 *      $ ./echo 
*/

#include <pthread.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

#define PROD 0
#define CONS 1
#define UNLOCK 0
#define LOCK 1

/* thread function prototypes */
void *consumer(void * dummy); 

   /*  A note on the differences between forks and threads. Variables inside 
   main and above the fork are visiable to a forked child but not shared after 
   the fork. Threads have the same visibility as functions; a thread has no 
   visability unless the variable is global. These globals are not only 
   visible but shared by all threads since threads share user space.
   */

union semun {
    int val;
    struct semid_ds *buf;
    u_short *array;
};

const int LIMIT = 50;      /* for testing just read 50 chars from the file */
int count = 0;

volatile int ichar = 'i';  /* incoming char */
volatile int ochar = 'o';  /* outgoing char */

int semid;
key_t ipckey;   

int main(void) 
{
    ipckey=ftok("/home/stu/nramsey/cs360-os/week05/echo.c", 420);
    if(ipckey)
   
    semid=semget(ipckey, 2, 0666 | IPC_CREAT);
    if(semid < 0){
        printf("Error - %s\n", strerror(errno));
        _exit(1);
    }

    if(semctl(semid, PROD, SETVAL, 1) == -1)
        printf("error setting semaphore value\n");

    struct sembuf startProd[2];
    startProd[PROD].sem_num = LOCK;
    startProd[PROD].sem_flg = SEM_UNDO;
    startProd[PROD].sem_op = UNLOCK;
    
    startProd[CONS].sem_num = UNLOCK;
    startProd[CONS].sem_flg = SEM_UNDO;
    startProd[CONS].sem_op = -1;

    struct sembuf endProd[1];
    endProd[PROD].sem_num = CONS;
    endProd[PROD].sem_flg = SEM_UNDO;
    endProd[PROD].sem_op = CONS;
    
    FILE * inf;
    pthread_t C;  /* main is the producer; C is the consumer */
    int dummy;
    /* Create a thread that executes this function:
          void *consumer(void * dummy);  */
    if (  pthread_create(&C, NULL,  consumer, (void *)&dummy) != 0 )
        printf("Error creating thread\n");

    ochar = 'p';
    pid_t tid = syscall(SYS_gettid);      
    printf("producer thread pid: %d tid: %d \n",getpid(), tid);
    inf = fopen("poem.in", "r");
    if (inf == NULL ) {
        fprintf(stderr, "error opening input file.\n");
        exit(1);
    }
   
    /* ----------------\
     |  CRITICAL CODE  |
    \* ---------------*/
    while (1)
    {
       semop(semid, startProd, 2);

       ochar = fgetc(inf);
       if (count == LIMIT){ break; }
        
       usleep(150000);   /* slow the entire process down */
       count++;
       semop(semid, endProd, 1);
   }
   fclose(inf);
   if((semctl(semid, 0, IPC_RMID)) < 0){
       perror("semctrl IPC_RMID");
       _exit(1);
   }else{
       puts("semaphore removed");
       system("ipcs -s");
   }
   sleep(2);
   return 0;
}

void * consumer(void * dummy)
{
    struct sembuf startCon[2];
    startCon[PROD].sem_num = UNLOCK;
    startCon[PROD].sem_flg = SEM_UNDO;
    startCon[PROD].sem_op = LOCK;
    
    startCon[CONS].sem_num = LOCK;
    startCon[CONS].sem_flg = SEM_UNDO;
    startCon[CONS].sem_op = -1;

    struct sembuf endCon[1];
    endCon[PROD].sem_num = PROD;
    endCon[PROD].sem_flg = SEM_UNDO;
    endCon[PROD].sem_op = CONS;
    
   pid_t tid = syscall(SYS_gettid);      
   printf("consumer thread pid: %d tid: %d \n",getpid(), tid);
   
   FILE * outf;
   outf = fopen("poem.out", "w");
   if (outf == NULL) {
      fprintf(stderr, "error opening output file.\n");
      exit(1);
   }
   
   /* ----------------\
    |  CRITICAL CODE  |
   \* ---------------*/
   while (1)
   {
       if (count == LIMIT) break;
       semop(semid, startCon, 2);
       putc(ochar,stdout); 
       fflush(stdout);
       putc(ochar,outf);
       if (count == LIMIT) 
           break;
       usleep(100000); /* slow output down */ 
       semop(semid, endCon, 1);
   }
   putc('\n',stdout); 
   fflush(stdout);
   fclose(outf);  
}
