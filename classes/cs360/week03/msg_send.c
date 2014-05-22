/* filename: msg_send.c

  A program that submits a message to a message queue.
  
  Of the three Sys5 IPC components (shared memory, message queues, semaphores)
  processes do not need to exist simultaneously to share messages--one process 
  can post a message and exit, and the message can be picked up minutes, hours,
  days later by the second process. Once the message is picked up, it is 
  removed from the queue. Message queues are thus like bulletin boards.

  Messages must consist of a long integer followed by the message data. This 
  structure in C is a valid message type that can hold a 100-byte message:

      struct mq_message {
        long type;       // The type or destination 
        char text[100];  // data goes here  
      };

  The receiver of the message uses the message type. When pulling a message 
  from the queue, you either select the first available message or look for a 
  particular message type. The message types to use are application-specific, 
  making queues unique from other forms of IPC in that the kernel has some 
  understanding of the application data being passed by reading the type field.

  Execute this program before the receiver program:

      $ gcc msg_send.c -o send
      $ gcc msg_rcv.c -o receive 
      $ ./send
      $ ./receive
*/


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
     /* create a variable of the required message structure type */
     struct { long type; char text[100]; } mymsg;

     /* Generate the ipc key - ftok converts a pathname and a project id
        to a System V IPC key - everyone who compiles this code will generate 
        the same key. To make your key unique to your account generate a key 
        using the absolute pathname to a file in your home directory - then 
        make sure to generate the same key in your receiver code (myNum must
        be the same also). There are limitations to ftok but it is handy -
        don't use it to generate a key for matters of national security */

     int myNum = 18; /* this number and the pathname creates a unique key -
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

     /* Set up the message queue */
     /*  msgget creates a message object in the kernel's message queue */ 

     mq_id = msgget(ipckey, IPC_CREAT | 0666);

     if ( mq_id < 0 ) {
        perror("msgget");
        exit(EXIT_FAILURE);
     }
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
}
