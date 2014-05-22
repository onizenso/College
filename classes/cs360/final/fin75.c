#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/signal.h>
#include <string.h>
#include <errno.h>

typedef struct {
   int num;
   double speed;
   int dest;
} Ball_Mold;

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
} ballSemun;

int leftHand=0, rightHand=1;
struct sembuf grab[2], release[1];  
int n_waiting;  /* num processes waiting for the semaphore */
int smopVal;  /* the value of the semaphore */
pid_t lastpid;   /* process that performed last semop */

const int catch0 = 0;
const int catch1 = 1;
const int toss = -1;

int n_toss;

int speed1, speed2, speed3; /* stores ball speeds from command line */

key_t ipckey;
int iNum=420;
static int semid; 

struct sigaction sa;

/*--- Handles Control-C Kill Signal ---*/
void ctrl_c_handler(int dummy){
    if((semctl(semid, 0, IPC_RMID)) < 0){
        perror("semctrl IPC_RMID");
        exit(1);
    }
    else{
        printf("\nHandler:\n");
        printf("\tsemaphores removed.\n");
    }
}

int retval; /* default location for return value of a thread */ 

void *ballThrow (void *);

int fibWait(int n){
   if (n < 2)
    return n;
  else
    return fibWait(n-1) + fibWait(n-2); 
}

int main(int argc, char **argv)
{
    if(n_toss = atoi(argv[0]) < 0){
        printf("Enter number of times to toss the ball.\n");
        _exit(1);
    }
    if(speed1 = atoi(argv[1]) < 0){
        printf("Enter speed of the three balls.\n");
        _exit(1);
    }
    if(speed2 = atoi(argv[2]) < 0){
        printf("Enter speed of the second and third balls.\n");
        _exit(1);
    }
    if(speed3 = atoi(argv[3]) < 0){
        printf("Enter the speed of the third ball.\n");
        _exit(1);
    }
    pthread_t bThread1, bThread2, bThread3;
     
    Ball_Mold ball1, ball2, ball3;

    ball1.num=1;
    ball2.num=2;
    ball3.num=3;

    ball1.speed= speed1;
    ball2.speed= speed2;
    ball3.speed= speed3;

    ball1.dest= leftHand;
    ball2.dest= leftHand;
    ball3.dest= rightHand;

    sa.sa_handler = ctrl_c_handler;
    sigaction(SIGINT, &sa, NULL);

    ipckey = ftok("./fin70.c", iNum);
    semid = semget(ipckey, 1, 0666 | IPC_CREAT);
    if(semid < 0){
       printf("Error - %s\n", (errno));
       _exit(1);
    }

    ballSemun.val = 0;
    semctl(semid, 0, SETVAL, ballSemun);
    semctl(semid, 2, SETVAL, leftHand);
    semctl(semid, 2, SETVAL, rightHand);

    smopVal = semctl(semid, leftHand, GETVAL);
    printf("Sem left hand value: %d -- pid: %d\n", smopVal, lastpid);

    smopVal = semctl(semid, rightHand, GETVAL);
    lastpid = semctl(semid, 0, GETPID);
    printf("Sem right hand value: %d -- pid: %d\n", smopVal, lastpid);
    
    if(pthread_create(&bThread1, NULL, ballThrow, (void*)&ball1) < 0){
           perror("pthread_create");
           _exit(1);
    }
    else
        printf("ball %d created.\n", ball1.num);
    
    if(pthread_create(&bThread2, NULL, ballThrow, (void*)&ball2) < 0){
           perror("pthread_create");
           _exit(1);
    }
    else
        printf("ball %d created.\n", ball2.num);
    
    
    if(pthread_create(&bThread3, NULL, ballThrow, (void*)&ball3) < 0){
           perror("pthread_create");
           _exit(1);
    }
    else
        printf("ball %d created.\n", ball3.num);
    

/*------------- JOINING THREAD ONE -----------------*/
    if ( (pthread_join(bThread1, (void*)&ball1)) < 0 ) {
        perror("pthread_join");
        exit(1);
    }
    else  {
        printf("joined ballThread1 exit code: %d\n",retval);
    }

/*-------------- JOINING THREAD TWO -----------------*/
    if ( (pthread_join(bThread2, (void*)&ball2)) < 0 ) {
        perror("pthread_join");
        exit(1);
    }
    else  {
        printf("joined ballThread2 exit code: %d\n",retval);
    }
    
/*--------------- JOINING THREAD THREE -----------------*/
    if ( (pthread_join(bThread3, (void*)&ball3)) < 0 ) {
        perror("pthread_join");
        exit(1);
    }
    else  
        printf("joined ballThread3 exit code: %d\n",retval);
            
    exit(0);
}

void *ballThrow(void *bPtr){
    pthread_t inner = pthread_self();
    Ball_Mold *tmp = bPtr;
    int num=(*tmp).num, dest=(*tmp).dest;
    double speed=(*tmp).speed;

    /*-Establishing CATCH operations for the hand-*/
    grab[0].sem_num = dest;
    grab[0].sem_flg = IPC_NOWAIT;
    grab[0].sem_op = catch0;

    grab[1].sem_num = dest;
    grab[1].sem_flg = IPC_NOWAIT;
    grab[1].sem_op = catch1;

    /*-Establishing RELEASE operations for the hand-*/
    release[0].sem_num = dest;
    release[0].sem_flg = SEM_UNDO;
    release[0].sem_op = toss;

    smopVal = semop(semid, grab, GETVAL);

    if(smopVal < 0)
        printf("Missed ball, not waitin neither!\n");
    else if(smopVal == 1)
        printf("Ball %d done. Ball already in hand fugger.\n", num);

    n_waiting = semctl(semid, dest, GETZCNT);
    printf("(%u) ball: %d thrown at speed: %f \n", inner, num, speed);
    printf("\t\t %d balls waiting-on-zero for sem %d\n", n_waiting, smopVal);

    fibWait(speed); /*wait for length of time specified by ball speed */
    semop(semid, release, 1);
    semctl(semid, 1, SETVAL, dest);

    pthread_exit((void*)EXIT_SUCCESS);
}
