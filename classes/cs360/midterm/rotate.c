#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main (void) {

     key_t ipckey;
     int mq_id;
 
     struct { long type; char text[100]; } rotate;
     int genNum = 420;

     ipckey=ftok("/home/stu/nramsey/cs360-os/midterm/mid65.c", genNum);
   
     if (ipckey == -1) {
        perror("ipckey error: ");
        exit(EXIT_FAILURE);
     }

     mq_id = msgget(ipckey, IPC_CREAT | 0666);
     printf("MQID is %d and IPCKey is %d \n", mq_id, ipckey);

     if ( mq_id < 0 ) {
        perror("msgget");
        exit(EXIT_FAILURE);
     }
     char choice;
     while(1)
     {
        printf("Would you like to rowtate Ball Thrower? (y|n)");
        scanf("%s", &choice); 
        if(choice == 'y' || choice == 'Y')
        {
            memset(rotate.text, 0, 100); 
            strcpy(rotate.text, "Arm rowtateing 10%.\n");
            rotate.type = 1;
            msgsnd(mq_id, &rotate, sizeof(rotate), 0);
            printf("MQID is %d and IPCKey is %d \n", mq_id, ipckey);
        }
        else if(choice == 'n' || choice == 'N')
        {
            printf("Hoh khay. Bye for now.\n");
            exit(0);
        }
        else{
            printf("Invalid input smart one.\n");
            exit(1);
        }
     }
    //--------- Used in Phase 85% and above ------------//
     /* if(rotate.text[0] != 0)
      * {
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateing, again: 20%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
      
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateingi again: 30%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
     
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateing, again: 40%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);

      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateing, again: 50%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
      
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateingi again: 60%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
     
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateing, again: 70%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);

      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateing, again: 80%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
      
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtateingi again: 90%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
     
      * memset(rotate.text, 0, 100); 
      * strcpy(rotate.text, "Zeh Arm is now rowtated to originawl pozish: 100%\n");
      * rotate.type = 1;
      * msgsnd(mq_id, &rotate, sizeof(rotate), 0);
      * }
    */

}
