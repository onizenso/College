#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <pthread.h>

volatile sig_atomic_t miss=0;
volatile sig_atomic_t caught=0;
volatile sig_atomic_t ballStat;

void display_status(int *);
void sig_handler(int);

int status;
int counter = 0;
int ballNum;

pid_t ballThrower=1, robot=0;
key_t ipckey;

int main(int argc, char **argv){
    
    if(atoi(argv[1])==0)
        ballNum = 5;
    
    int mq_id, genNum=420;
    ballNum = atoi(argv[1]);
    struct { long type; char text[100]; } mymsg;
    struct sigaction sa;
    sigset_t block_mask, zeromask, pending;

    ballThrower = getpid();

    ipckey=ftok("/home/stu/nramsey/cs360-os/midterm/mid65.c", genNum);

    
    sa.sa_handler = sig_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigemptyset(&block_mask);
    sigemptyset(&zeromask);
    sigaddset(&block_mask, SIGUSR1);
    sigaddset(&block_mask, SIGTERM);

    if(sigaction(SIGUSR1, &sa, NULL) == -1){
        perror("sigaction");
        _exit(1);
    }
    if(sigaction(SIGTERM, &sa, NULL) == -1){
        perror("sigaction");
        _exit(1);
    }
    /* --------------------- ROBOT'S CODE --------------------------//
     * ------------------------------------------------------------*/
    sigprocmask(SIG_BLOCK, &block_mask, NULL);
    robot = fork();
    
    if(robot == 0){ /* Robot's code */      
        while(1){
            sigpending(&pending);
        
            ballStat = sigismember(&pending, SIGUSR1) ? 1 : 0;
        
            sigsuspend(&zeromask);
        }
        exit(0);
    }

    /* ------------------ BALL THROWER'S CODE ----------------------//
     * ------------------------------------------------------------*/
    int i=0;
    if(getpid() == ballThrower){
        while(i < ballNum){
            printf("Ball Thrown...\n");
            i++;
            kill(robot, SIGUSR1);
            usleep(500000);
        }
        kill(robot, SIGTERM);
        wait(&status);
    }
    
    return 0;
}

void sig_handler(int sig){
    if(sig == SIGUSR1){
        if(ballStat != 0){
            write(1, "Ball missed.\n", 14);
            miss+=1;
        }
        else{
            write(1, "Ball Caught.\n", 14);
            caught+=1;
        }
    }
    else if(sig == SIGTERM){
        printf("%d ball(s) missed.\n", miss);
        printf("%d ball(s) caught.\n", caught);
        printf("%d ball(s) thrown.\n", ballNum);
        write(1, "Robot shutting down\n", 21);
        printf("Robot exited with status: %d\n", status);
        _exit(0);
    }
}

void display_status( int * status){
   fflush(stdout);
   if (WIFEXITED(status)) {
        printf("exited, status=%d\n", WEXITSTATUS(status));
   } else if (WIFSIGNALED(status)) {
        printf("killed by signal %d\n", WTERMSIG(status));
   } else if (WIFSTOPPED(status)) {
        printf("stopped by signal %d\n", WSTOPSIG(status));
   } else if (WIFCONTINUED(status)) {
        printf("continued\n");
   }
}
