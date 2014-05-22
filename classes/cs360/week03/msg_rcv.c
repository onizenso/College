/* filename: msg_rcv.c

  Demonstrate the second half SysV IPC message queues by retrieving a message.
  This program assumes msg_send.c has been executed and put a msg in the queue.

  The procedure to get the IPC key and the message queue identifier is similar 
  to the sender's code. The call to msgget does not specify any flags because 
  the sender has already created the queue. If the application were such that 
  the receiver might be started before the sender, then both processes would
  need to specify permissions and the IPC_CREAT flag so that whichever process
  started first would create the queue.

  The call 'msgrcv' is the heart of the code. This call pulls a message off 
  the queue. The first three arguments give the message queue identifier, a 
  pointer to the memory space that will hold the message, and the size of the 
  buffer. The fourth parameter is the type parameter, and it allows you to be 
  selective about which messages you get:

  * If the type is 0, the first message in the queue is returned.

  * If the type is a positive int, the first message in the queue with the same 
    type is returned.

  * If the type is a negative int, the first message in the queue with the 
    lowest value that is less than or equal to the absolute value of the 
    specified type is returned. For example, if 2 and then 1 were to be added to
    the queue, calling msgrcv with a type of -2 would return the 1 because it is
    the smallest, even though it was second in the queue.

   The fifth parameter to msgrcv is the blocking flag again. Sample output:
  $ ./send
  My key is 704654099
  Message identifier is 2
  $ ./receve
  My key is 704654099
  Message identifier is 2
  Hello, world! (104)

  The output shows that both sender and receiver came up with the same IPC key 
  because they referenced the same file and identifier. The server created the 
  IPC instance, which the kernel assigned the value of 2, and the receiver 
  learned this. It should then come as no surprise that the client pulls 
  "Hello, world!" back from the message queue.

  This example is a simple application. Multiple processes can submit messages
  and multiple receivers can grab messages. The message type field allows 
  proccesses to direct messages to particular readers.  */

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    key_t ipckey;
    int mq_id;
    struct { long type; char text[100]; } mymsg;
    int received;

    /* Generate the ipc key - use the same file and key used in msg_send.c */
    ipckey = ftok("./lab03.txt", 18);            /* replace this with a pathname 
                                            to a file in your home directory 
                                            and the same number from msg_send */
    if (ipckey == -1 ) {
        perror("ipckey error: ");
        exit (EXIT_FAILURE);
    }
    else
        printf("My key is %d\n", ipckey);

    /* get an ID to the message queue using the ipckey*/
    mq_id = msgget(ipckey, IPC_CREAT | 0666); /* create or open existing queue*/
    printf("Message queue identifier is %d\n", mq_id);

    /* the ipc_nowait flag means do not block 
    received = msgrcv(mq_id, &mymsg, sizeof(mymsg), 0, IPC_NOWAIT); */
    received = msgrcv(mq_id, &mymsg, sizeof(mymsg), 0, 0);
    if ( received > 0)
       printf("%s (%d)\n", mymsg.text, received);
    else
       printf("\nno message to be found and i ain't waiting....\n");
       
  
    /* uncomment this if you want to remove the message queue  
    if (( msgctl(mq_id, IPC_RMID, NULL)) < 0) {
          perror("msgctl");
          exit(EXIT_FAILURE);
    } else {
          printf("queue %d removed\n", mq_id );
    } 
    */
    exit(EXIT_SUCCESS);
}

