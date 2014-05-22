/* filename: /week04/shared_mem.c
* 
* This file is a simplified version of shared_mem.c from week 03. If you do not
* understand how shared memory works, review the solution to week03 lab and 
* the week 03 examples. Your job in lab 04 is to add semaphores to protect the 
* critical sections of code in this file.  You know things have gone awry
* at line 4:
*  
*    $ gcc shared_mem.c -o shared_mem
*    $./shared_mem
*  1 child  set 1, reads: 1
*  2 parent set 2, reads: 2
*  3 parent set 4, reads: 4
*  4 child  set 3, reads: 4 // parent modified memory in the middle of printf 
*
* Note that you are using semaphores to enforce mutual exclusion of a critical
* section of code. You are not using semaphores to enforce synchronization.
* Thus, you will still need sleeps in your code. If you want to use semaphores
* to replace sleeps, feel free to do so. Next week we will use semaphores for
* synchronize things. 
*
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int status;

union semun { /* sets up semaphores */
  int  val;
  struct semid_ds *buf;
  unsigned short  *array;
  struct seminfo  *__buf;
} semattack;


int main(int argc, int **argv) {

    key_t ipckey;
    int semid;
    struct sembuf sem[2];

    // Generating ipc key
    ipckey = ftok("/home/stu/nramsey/cs360-os/week04/sem_test.c", 420);
    
    semid = semget(ipckey, 1, 0666 | IPC_CREAT);
    if(semid < 0){
        printf("Error - %s\n", strerror(errno));
        _exit(1);
    }

    sem[0].sem_num = 0;
    sem[1].sem_num = 0;
    sem[0].sem_flg = SEM_UNDO;
    sem[1].sem_flg = SEM_UNDO;
    
    int child={0}, parent={1};
    
    int shmid; 
    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

    if (fork() == child) { /* Child  */
        sem[0].sem_op = 0;
        sem[1].sem_op = 1;
        semop(semid, sem, 2);
        printf("[%s] I have the semaphore! \n", argv[2]);
        sleep(rand() % 3);

/* Attach to shared memory and print the pointer */
        int* shared = shmat(shmid, (void *) 0, 0);
        /* Used for debugging shared memory allocation  *
         * printf("\t\tchild  pointer:  %p\n", shared); */
        *shared=1;   /* modify shared memory segment */
        printf("child  set 1, reads: %d\n", *shared);
        *shared=3;   /* modify shared memory segment */
        sleep(2);
        printf("child  set 3, reads: %d\n", *shared);
        
        sem[0].sem_op = -1;
        semop(semid, sem, 1);
        printf("[%s] Released the semaphore! \n", argv[2]);
        exit(0);

    } else { /* Parent */
        sem[0].sem_op = 0;
        sem[1].sem_op = 1;
        semop(semid, sem, 2);
        printf("[%s] I have the semaphore! \n", argv[1]);

        
        sleep(rand() % 3);


        /* Attach to shared memory and print the pointer */
        int *shared = shmat(shmid, (void *) 0, 0);
        /* printf("\t\tParent pointer: %p\n", shared); */
        *shared=2;  /* modify shared memory segment */
        printf("parent set 2, reads: %d\n", *shared);
        sleep(1);
        *shared=4;  
        printf("parent set 4, reads: %d\n", *shared);
        sleep(5);
        
        sem[0].sem_op = -1;
        semop(semid, sem, 1);
        printf("[%s] Released the semaphore! \n", argv[1]);
        
        wait(&status); /* wait for the child to die */
        if ((semctl(semid, 0, IPC_RMID)) < 0) {
            perror("semctrl IPC_RMID");
            _exit(1);
        } else {
            puts("Semaphore removed\n");
            system("ipcs -s");
        }    
        shmdt(shared);
        shmctl(shmid, IPC_RMID, 0);  /* remove the segment */
    }
}
