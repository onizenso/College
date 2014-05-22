/* filename: dining.c
 * a solution to the dining philosophers problem using mutexes 
 *
 *   int n; flag = 1;
 *   n = (flag) ? 10 : 20;  # C ternary conditional operator '?'
 *   meaning: if flag is T then n is assigned value 10 otherwise value 20.
 *
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
 
typedef struct philData {
    int fork_lft, fork_rgt, fork_tmp;
    const char *name;
    pthread_t thread;
    int   fail;
} Philosopher;

union semun {
    int val;
    struct semid_ds *buf;
    struct seminfo *__buf;
    unsigned short *array;
};
 
int IPCNUM = 420;
int semid;
struct sembuf sops[2];
key_t ipckey;

void *PhilPhunction(void *p) {
    int running = 5;  /* this is the number of times each phil gets to eat */
    Philosopher *phil = p;
    int failed;
    int tries_left;
    int fork_lft, fork_rgt, fork_tmp;

    

    while (running > 0) {
        usleep(300000); /* slow down output a bit */
        printf("%s is thinking\n", phil->name);
 
        fork_lft = 0;
        fork_rgt = 1;
        printf("%s is hungry\n", phil->name);
        tries_left = 2;   /* try twice before being forceful */

        do {
            sops[fork_lft].sem_num = 0;
            sops[fork_lft].sem_op = -1;
            sops[fork_lft].sem_flg = SEM_UNDO | IPC_NOWAIT;           
            failed = semop(semid, fork_lft, 1);


           /* mutex_trylock() returns zero if lock acquired else error code;
            * mutex_trylock does not block - mutex_lock blocks and returns
            * id of owner of the lock  - this essentially implements "Try
            * nicely twice before forcefully grabbing it */ 

            failed = (tries_left>0)? semop(semid, sops[fork_lft], 1)//wait for 0  
                                   : semop(semid, sops[fork_lft], 1);//wait try to lock
            if(tries_left>0){              
                sops[fork_lft].sem_num = 0;
                sops[fork_lft].sem_op = 0;
                sops[fork_lft].sem_flg = SEM_UNDO | IPC_MOWAIT;
                semop(semid, sops[fork_lft], 1);            
            }
            else{            
                sops[fork_lft].sem_num = 0;
                sops[fork_lft].sem_op = 1;
                sops[fork_lft].sem_flg = SEM_UNDO | IPC_NOWAIT;
                semop(semid, sops[fork_lft], 1);
            }

            if (failed) {
                sops[fork_lft].sem_num = 0;
                sops[fork_lft].sem_op = -1;
                sops[fork_lft].sem_flg = SEM_UNDO | IPC_NOWAIT;            
                semop(semid, sops[fork_lft], 1);
                
                fork_tmp = fork_lft;
                fork_lft = fork_rgt;
                fork_rgt = fork_tmp;
                tries_left -= 1;
            }

        } while(failed && running);

        if (!failed) {
            usleep(300000); /* slow down output a bit */
            printf("%s is eating\n", phil->name);
            
            sops[fork_lft].sem_num = 0;
            sops[fork_lft].sem_op = -1;
            sops[fork_lft].sem_flg = SEM_UNDO;
            semop(semid, sops[fork_lft], 1); //unlocks the sem fork_lft
            
            sops[fork_rgt].sem_num = 0;
            sops[fork_rgt].sem_op = -1;
            sops[fork_rgt].sem_flg = SEM_UNDO;
            semop(semid, sops[fork_rgt], 1); //unlocks the sem fork_rgt
            running --;
        }
    }
}
 
void Ponder()
{
  const char *nameList[] = {"Kant", "Hegel", "Plato", "Aristotle", "Decartes"};
    Philosopher philosophers[5];
    Philosopher *phil;
    int i;
    int failed;
    int fork_lft, fork_rgt, fork_tmp;
 
    //for (i=0;i<5; i++) {
        /* initialize the mutexes - NULL flag means the defaults are used */
        //failed = pthread_mutex_init(&forks[i], NULL);
   /*     
        if (failed) {
            printf("Failed to initialize mutexes.");
            exit(1);
        }
    }
    */
 
    for ( i = 0; i < 5; i++ ) {
        phil = &philosophers[i];
        phil->name = nameList[i];
        phil->fork_lft = fork_lft;
        phil->fail = pthread_create( &phil->thread, NULL, PhilPhunction, phil);
    }

     
    /* join all the threads with main thread */ 
    for( i=0; i < 5; i++ ) {
        phil = &philosophers[i];
        if ( !phil->fail && pthread_join( phil->thread, NULL) ) {
            printf("error joining thread for %s", phil->name);
            exit(1);
        }
        else
            printf("Joined thread for %s\n", phil->name);
    }
}
 
int main( )
{
    ipckey = ftok("/home/stu/nramsey/cs360-os/week06/dining.c", 420);
    semid = semget(ipckey, 5, 0666 | IPC_CREAT);
    if(semid < 0){
        printf("Error - %s\n", strerror(errno));
        _exit(1);
    }
    
    Ponder();
    
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl");
        exit(1);
    } 
    
    return 0;
}
