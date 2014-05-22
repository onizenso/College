#include <sys/types.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void sighandler(int sig){
    if(sig == SIGUSR1)
        printf("I gotz that signal yo! \n");
    else
        printf("I is jacked! \n");
    fflush(stdout);

}

int status;

int main(void){
    key_t ipckey;
    int shmid;
    int mq_id;
    struct { long type; char text[100]; } mymsg;
    int received;

    sigset_t nmask, omask;
    sigemptyset(&nmask);
    sigemptyset(&omask);
    sigaddset(&nmask, SIGUSR1);
    sigaddset(&nmask, SIGQUIT);

    struct sigaction sa;
    sa.sa_handler = sighandler;
    sigaction(SIGUSR1, &sa, NULL);
    
    int myNum = 27; /* this number and the pathname creates a unique key -
                        modify this number so that all students do not
                        create the same ipckey */


    ipckey=ftok("/home/stu/nramsey/cs360-os/lab03.txt", myNum);
        /* replace this with a pathname 
            to a file in your directory */
        
    if (ipckey == -1) {
        perror("ipckey error: ");
        exit(EXIT_FAILURE);
    }
    else
        printf("My key is %d\n", ipckey);


    shmid = shmget(ipckey, sizeof(int), IPC_CREAT | 0666);
    
    sigprocmask(SIG_BLOCK, &nmask, NULL);
    int proc = fork();
    
    // Child Code
    // -----------------------//
    if(proc == 0){ 
        sleep(2);
        int *shared = shmat(shmid, (void *)0, 0);
        mq_id = msgget(ipckey, IPC_CREAT | 0666);
        
        /*sigpending(&nmask);
        if(sigismember(&nmask, SIGUSR1)) 
            printf("I got that signal yo!\n\n");*/
        
        /* create or open existing queue*/
        printf("Message queue identifier is %d\n", mq_id);

        /* the ipc_nowait flag means do not block 
        received = msgrcv(mq_id, &mymsg, sizeof(mymsg), 0, IPC_NOWAIT); */
        received = msgrcv(mq_id, &mymsg, sizeof(mymsg), 0, 0);
        if ( received > 0)
            printf("%s (%d)\n", mymsg.text, received);
        else
            printf("\nno message to be found and i ain't waiting....\n");

        sigprocmask(SIG_UNBLOCK, &nmask, NULL);
        exit(0);
    }

    // Parent Code
    // ---------------------- //
    else{
        int *shared = shmat(shmid, (void *)0, 0);
        mq_id = msgget(ipckey, IPC_CREAT | 0666);
     
        printf("Message identifier is %d\n", mq_id);

        /* construct and send a message */
        memset(mymsg.text, 0, 100); /* clear out the space first */
        strcpy(mymsg.text, "Hello, world!");
        mymsg.type = 1;
        msgsnd(mq_id, &mymsg, sizeof(mymsg), 0);

        /* construct and send a second message */
        memset(mymsg.text, 0, 100); /* clear out the space first */
        strcpy(mymsg.text, "Hello, again!");
        mymsg.type = 1;
        msgsnd(mq_id, &mymsg, sizeof(mymsg), 0);

        kill(proc, SIGUSR1);
        wait(&status);
        exit(0);
    }
    // --------------------- //
   // --End Parent Code--- //

}
