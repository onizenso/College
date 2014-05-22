/* file: /examples/week02/sample3.c     
*
*   Demonstrate sending signals to a child with the kill system call. In linux
*   (for efficiency) the fork is cloned as a copy-on-write; i.e., until a 
*   modification is done by either parent or child, both share the same memory 
*   addresses for data. Clever.
*
*  Open top in one terminal window:
*       $ top -u [username]               # hit 'q' to end top
*
*  Open a second terminal window. Compile and execute. 
*
*       $ gcc -o sample3 sample3.c
*       $ ./sample3
*
*  Watch the process status column. From top man page:
*
*  S  --  Process Status
*         The status of the task which can be one of:
*             D = uninterruptible sleep
*             R = running
*             S = sleeping
*             T = traced or stopped
*             Z = zombie
*
*   Tasks  shown as running should be more properly thought of as aready
*   to run  --  their task_struct is simply represented  on  the  Linux
*   run-queue.   Even  without  a true SMP machine, you may see numerous
*   tasks in this state depending  on  top's  delay  interval  and  nice
*   value.  
*/

#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void display_status( int * );

int main()
{
   int parent = getpid(); 
   int child = fork();
   int status, err; 

   /* CHILD */
   if ( child == 0 ) {
      while (1)  {                      /* put the child in an infinite loop */
        sleep(1);                       /* slow things down a bit */
        printf("Help! i'm stuck!\n");
      } 
      exit(0);
   }

   /* PARENT */
   if ( getpid() == parent ) 
   {
      sleep(4);
      printf("\nSend a SIGSTOP to the child.\n");
      err = kill(child,SIGSTOP); 
      if ( err < 0 ) 
           perror("\nkill:SIGSTOP ");
      else 
          printf("\nStopped.\n");

      sleep(4);
      printf("\nSend a SIGCONT to the child.\n");
      err = kill(child,SIGCONT); 
      if ( err < 0 ) 
           perror("\nkill:SIGCONT\n");
      else 
          printf("\nRestarted.\n");


      sleep(5);
      printf("\nSend a SIGHUP to the child.\n");
      err = kill(child,SIGHUP); 
 
      wait(&status);   // wait to reap the return code
      display_status(&status);

      exit (EXIT_SUCCESS);
   }
}

void display_status( int * status){
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
