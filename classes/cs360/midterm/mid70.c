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

volatile sig_atomic_t miss; //condition flag, sets missed balls

void display_status(int *);
void sigusr1_handler(int);

int status;
int counter = 0;
pid_t ballThrower=1, robot=0;
key_t ipckey;

int main(int argc, char **argv){
    int mq_id, genNum=420;
    struct { long type; char text[100]; } mymsg;
    struct sigaction sa;
    sigset_t block_mask, oldmask, pending;

    ballThrower = getpid();

    ipckey=ftok("/home/stu/nramsey/cs360-os/midterm/mid65.c", genNum);

    robot = fork();
    
    sa.sa_handler = sigusr1_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigemptyset(&block_mask);
    sigemptyset(&oldmask);
    sigaddset(&block_mask, SIGUSR1);

    if(sigaction(SIGUSR1, &sa, NULL) == -1){
        perror("sigaction");
        _exit(1);
    }
    
    if(robot == 0){ /* Robot's code */      
        sigpending(&pending);
        
        miss = sigismember(&pending, SIGUSR1) ? 0 : 1;
        
        sigprocmask(SIG_BLOCK, &block_mask, &oldmask);
        sigsuspend(&oldmask);
        while(1){
            sleep(2);
            counter++;
            printf("waiting for the ball...\n");
        }
        sigprocmask(SIG_UNBLOCK, &oldmask, NULL);
        exit(11);
    }

    if(getpid() == ballThrower){
        printf("Throwing ball to the robot...\n");
        sleep(2);
        kill(robot, SIGUSR1);
        wait(&status);
    }
    
    return 0;
}

void sigusr1_handler(int sig){
    
    if(miss != 0){
        write(1, "Ball missed.\n", 14);
        printf("Robot exited with status: %d\n", status);
    }
    else
        write(1, "Robot caught the ball.\n", 24);
    exit(0);    
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
