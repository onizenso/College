/* filename: sem_test.c
   Demonstrate using semaphores to protect critical sections of code.

 USAGE: sem_test <process name>  # process name is whatever name you wish 

     CTRL-C     # to stop program

 Read this in its entirety before executing the code. This program does not 
 remove your semaphores. You need to do it manually as shown here.

   $ gcc sem_test.c
   $ ./a.out proc1 & ./a.out proc2 &
   $ ipcs  # list your semaphores when finished
   $ ipcrm -s {semaphore id}  # remove your semaphores 

 Of the three components in the SysV IPC suite--message queues, shared memory 
 and semaphores--semaphores are the most difficult to use because they always
 involve process synchronization. You use semaphores to keep multiple 
 processes from accessing shared resources at the wrong time.  

 Synchronization does not need to involve message passing. So why not use 
 a single bit flag to indicate that a process is using a certain resource? 
 Assume two processes need to access a piece of hardware, but only one of them 
 at a time may use it. Each could agree on a spot to hold a reference counter. 
 If one process reads the counter and sees 1, it is understood that another 
 process is using the hardware. If the value of the counter is 0, then the 
 process is free to use the hardware resource as long as the counter is set to 
 1 for the duration of the hardware operation and reset to 0 at the end.

 There are two problems with this scenario. The first is that setting up the 
 shared counter and agreeing upon its location can be problematic. Second,  
 the get and set operations needed to lock the hardware resource are not 
 atomic, so are not in themselves synchronized; i.e, if one process were to 
 read the counter as 0 but become preempted by another process before it had 
 the chance to set the counter to 1, the second process might be able to read 
 and set the counter. Both processes would think they could use the hardware. 
 There is no way to know if the other process (or processes) also set the 
 counter. You have a race condition. Semaphores solve both these problems by 
 providing a common interface to applications and by implementing an atomic 
 test or set operation.

 The SysV implementation of semaphores is more general than the above scenario
 and also more complicated (the POSIX standard is easier but less widely used).
 First, the value of a semaphore can be not just 0 or 1, but 0 or any positive 
 integer:

 struct sem {
      int semval;  # semaphore value - this is any non-negative or zero integer 
      int sempid;  # PID for last operation that performed op on this sem
 };

 Second, multiple semaphore operations can be performed atomically, much like 
 the msgrcv type parameter in shared message queues. The operations are sent 
 as a set of instructions to the kernel. Either all are run or none are run. 
 The instructions go in a struct called sembuf; see /usr/include/sys/sem.h:

 struct sembuf {    
    unsigned short int sem_num;  # denotes a semaphore in the set: 0,1,2,... 
    short int sem_op;    # the semaphore operation 
    short int sem_flg;   # the operation flag 
  };    

  Details:
  1. sem_num: denotes which semaphore from the set to perform the ops on 
  2. sem_op: A signed int containing the instruction or test to be performed.
  3. sem_flg: A combination of the familiar IPC_NOWAIT flag, which indicates 
     if the test should return immediately or block until it passes, and 
     SEM_UNDO, which causes the semaphore operations to be undone if the 
     process should exit prematurely.

 Values for sem_op:

 * If sem_op is 0, sem_num is tested to see if its value is 0; if so, the 
   next test runs. If sem_num is not 0, either the operation blocks until the 
   semaphore becomes 0 if IPC_NOWAIT is not set, or the rest of the tests are 
   skipped if IPC_NOWAIT is set.

 * If sem_op is a positive integer, the value of sem_op is added to the value 
   of the semaphore.

 * If sem_op is a negative integer and the value of the semaphore is greater 
   than or equal to the absolute value of sem_op, then the absolute value is 
   subtracted from the value of the semaphore.

 * If sem_op is a negative integer and the value of the semaphore is less than 
   the absolute value of sem_op, then the execution of tests immediately stops 
   if IPC_NOWAIT is true, or blocks until the semaphore's value becomes greater
   than the absolute value of sem_op if false.

 The code below demonstrates the use of semaphores. The program can be run 
 several times simultaneously, but it ensures that only one process is in the 
 critical section at a time. The simplest case of semaphores is used: the 
 resource is free if the value of the semaphore is 0.
 
 The program starts off by creating a new semaphore set from the kernel with
 semset. A semaphore set is a group of semaphores sharing a common IPC 
 instance. The number of semaphores in the set cannot be changed. If the 
 semaphore set has been created, the second parameter to semget is effectively 
 ignored. If semget returns a negative integer indicating failure, the reason 
 is printed, and the program exits.

 Just before the main while loop, sem_num and sem_flg are initialized, because 
 they stay consistent throughout this. SEM_UNDO is specified so that if the 
 holder of the semaphore exits before the semaphore can be released, all the 
 other applications are not locked out.

 Within the loop, the status of each sem op is displayed, prefaced by process 
 name. Before entering the critical section, the process locks the semaphore. 
 Two semaphore instructions are specified. The first is 0, which means that the
 process waits until the semaphore value returns to 0. The second is 1, which 
 means that after the semaphore returns to 0, 1 is added to the semaphore. The 
 process calls semop to run the instructions, passing it the semaphore ID, the 
 address of the data structure, and the number of sembuf instructions to use.

 After semop returns, the process knows it has locked the semaphore and prints 
 a message to indicate this. The critical section then runs, which in this 
 case is a pause for a random number of seconds. Finally, the semaphore is 
 released by running a single sembuf command with a semop value of -1, 
 which has the effect of subtracting 1 from the semaphore and returning its 
 value to 0. More debugging output is printed, the application pauses randomly,
 and execution continues. Sample output of two instances of this application:

    $ gcc sem_test.c -o sem_test

    $ ./sem_test a &  ./sem_test b &

   [a] Waiting for the semaphore to be released
   [a] I have the semaphore
   [b] Waiting for the semaphore to be released
   [a] Released semaphore
   [b] I have the semaphore
   [a] Waiting for the semaphore to be released
   [b] Released semaphore
   [a] I have the semaphore
   [a] Released semaphore
   [a] Waiting for the semaphore to be released
   [a] I have the semaphore

   $ fg  // bring process to the foreground then hit CTRL-C
   $ fg  // bring other process to the foreground then hit CTRL-C

 Two instances of the program are executed, with their respective names 'a' 
 and 'b' read in from the command line. First, 'a' obtains the semaphore, and 
 while holding it, 'b' tries to obtain a lock. As soon as 'a' releases the 
 semaphore, 'b' is given the lock. The situation reverses itself with 'a' 
 waiting for 'b' to finish. Finally, 'a' gets the semaphore again after 
 releasing it, because 'b' was not waiting.

 The last item to note about semaphores is that they are really just advisory 
 locks. This means that the semaphores themselves do not prevent two processes 
 from using the same resource simultaneously; rather, they are there to advise 
 anyone willing to ask if the resource is already in use.                */

#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <string.h> /* For strerror(3c) */
#include <errno.h> /* For errno */
#include <unistd.h> /* rand(3c) */
#include <stdio.h>
#include <stdlib.h>  /* exit(3) */

/* you need this if you want to modify the default values of a semaphore */
union semun {
  int  val;    
  struct semid_ds *buf;   
  unsigned short  *array; 
  struct seminfo  *__buf; 
} my_semun; 


int main (int argc, char **argv)   /* argc holds command line argument count */
{                                  /* argv holds the arguments */

    int n_waiting;              /* number waiting for the semaphore */
    char name[10];              /* give your process a name to distinguish it */
    if ( argc == 2 ) {          /* read in process name from command line */
      strcpy(name,argv[1]);     /* argv[0] is the name of the executable 
                                   argv[1] is the first command line arg */
      printf("process name: %s\n",name);
    } else {
      printf("USAGE: sem_test <process name> \n");
      exit(EXIT_FAILURE);
    } 
    char pathname[30];
    int semid;
    struct sembuf sops[2];  /* will hold two operations */

    /* Generate a pseudo-unique ipc key */
    key_t ipckey;
    getcwd(pathname,30);
    strcat(pathname,"foo");  /* foo must exist in your directory */
    ipckey = ftok(pathname, 42);  
                                        
    int nsems = 1;  /* the number of semaphores you want in the set */
    /* create and set perms on the set; 4 is read, 2 is alter, 6 is BOTH */
    semid = semget(ipckey, nsems, 0666 | IPC_CREAT);
    if (semid < 0) {
          printf("Error - %s\n", strerror(errno));
          _exit(1);
    }

    my_semun.val = 1;
    semctl(semid, 0, SETVAL, my_semun);
    int sem_value = semctl(semid, 0, GETVAL);
    printf("Sem#0 value: %d\n",sem_value);

    /* now set it back */
    my_semun.val = 0;
    semctl(semid, 0, SETVAL, my_semun);

    /* initialize sembuf struct for semaphore operations */
    sops[0].sem_num = 0;  /* operation applies to the first semaphore in  set */
    sops[0].sem_flg = SEM_UNDO; /* undo action if premature exit */

    sops[1].sem_num = 0;        /* op 2 also applies to the first semaphore */
    sops[1].sem_flg = SEM_UNDO; 

    while(1)  
    {

        /* these two semaphore operations are be executed atomically */
        sops[0].sem_op = 0; /* 1st operation: wait until sem value is zero */
        sops[1].sem_op = 1; /* 2nd operation: add 1 to semaphore value */

        /* perform the two operations */
        semop(semid, sops, 2); 

        /* use semctl to get actual value of semaphore */
        n_waiting = semctl(semid, 0, GETZCNT);
        printf("%s: %d waiting for semaphore \n", name, n_waiting);

        printf("[%s] I have the semaphore\n", name);
        sleep(rand() % 3); /* critical section, take a nap for 0-2 seconds */

        /* define second operation */
        sops[0].sem_op = -1; /* decrement semaphore value by 1 */

        semop(semid, sops, 1);
        printf("[%s] Released semaphore\n", name);

        sleep(rand() % 3); /* Sleep 0-2 seconds */
    }

  
    exit(EXIT_SUCCESS);
}
