#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/file.h>
#include <sys/types.h>

volatile sig_atomic_t got_ctrlC = 0;

int main(){
    int parent = getpid();
    int child = fork();
    int cnt, err;

    cnt = 0;

    if(getpid() == 0){
        while(1){
            printf("%d \n", cnt+1);
            sleep(1);
            ++cnt;
        }
    }

    if(getpid() == parent){
        sleep(4);
        printf("Sending SIGSTOP to Child");
        err = kill(child, SIGSTOP);

        if(err < 0){ perror("\nkill: SIGSTOP\n"); } 
        else{ printf("\nRestarted\n"); }

        sleep(4);
        printf("\nResuming the Child with SIGCONT\n");
        err = kill(child, SIGCONT);
    }


    return 0;
}
