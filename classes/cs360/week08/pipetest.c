/*  file: pipetest.c
 
    Creates a pipe(2), and then fork(2)s to create a child process; the child 
    inherits a duplicate set of file descriptors that refer to the same pipe.  
    After the fork(2), each process closes the descriptors that it doesn't 
    need for the pipe (see pipe(7)). The parent then writes the string contained
    in the programs command-line argument to the pipe, and the child reads this 
    string one byte at a time from the pipe and echoes it on standard output.
  
    Producer/consumer synchronization is handled by the kernel. From pipe(7):
 
       If  a  process  attempts  to read from an empty pipe, then read(2) will
       block until data is available.  If a process attempts  to  write  to  a
       full  pipe  (see below), then write(2) blocks until sufficient data has
       been read from the pipe to allow the write  to  complete.   Nonblocking
       I/O  is  possible by using the fcntl(2) F_SETFL operation to enable the
       O_NONBLOCK open file status flag.

       The communication channel provided by a pipe is a byte stream: there is
       no concept of message boundaries.

   To run:
 
       $ gcc -o pipetest pipetest.c 
       $ ./pipetest hello
*/

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
   int pipefd[2];  /* need 2 file descriptors for incoming and outgoing ends */ 
   pid_t cpid;
   char buf;       /* read and write a single char (1 byte) at a time */

   if ( argc != 2 ) {
       printf("Usage: ./pipetest somestring\n"); 
       exit(0);
   }

   if (pipe(pipefd) == -1) {     /* create the pipe before the fork */
       perror("pipe");
       exit(EXIT_FAILURE);
   }

   cpid = fork();
   if (cpid == -1) {
       perror("fork");
       exit(EXIT_FAILURE);
   }

   if (cpid == 0) {         /* CHILD reads from pipe */
       close(pipefd[1]);	  /* Close unused write end */

       while (read(pipefd[0], &buf, 1) > 0)
   	   write(STDOUT_FILENO, &buf, 1);

       write(STDOUT_FILENO, "\n", 1);
       close(pipefd[0]);
       _exit(EXIT_SUCCESS);

   } else {	                /* PARENT writes argv[1] to pipe */
       close(pipefd[0]);	  /* Close unused read end */
       write(pipefd[1], argv[1], strlen(argv[1]));
       close(pipefd[1]);	  /* Reader will see EOF */
       wait(NULL);		      /* Wait for child */
       exit(EXIT_SUCCESS);
   }
}
