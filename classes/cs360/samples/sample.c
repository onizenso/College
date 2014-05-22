/* filename:  /examples/week02/sample.c     
*
*   Demonstrate use of these signals: 
*      SIGCHLD (a signal from child to parent)
*      SIGTERM (this exit signal can be blocked unlike kill -9) 
*
*   The child kills its parent, becomes an orphan and is inherited by init
*   (PID 1). The child then tries to kill init and then finally kills itself.
*   Note that the orphan cannot be stopped by Ctrl-C since init blocks Ctrl-C.
* 
*   Compile 
*
*     $ gcc -o sample sample.c
*
*   Trace the signals passed between the OS and the processes:
* 
*      $ strace -e trace=signal -f ./sample  2> outfile    # -f traces child
*
*  View the strace output file.  
*/

#include <sys/wait.h>
#include <stddef.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int secs = 1;   

int main()
{
   int i, err, status, counter;
   pid_t parent, child;

   /* if you want to ignore signals from your children - signal() is the quick 
      and dirty way;  we are not doing so because we want the child to kill its
      parent 
   signal(SIGCHLD, SIG_IGN);  */ 
 
   parent = getpid(); 
   printf("Parent: %d\n", parent); 

   /* duplicate yourself - fork returns PID of the child to the parent 
      and 0 to the child or -1 to the  parent on failure */
   child = fork(); 


   /* I AM THE CHILD */
   if ( child == 0 )   
   { 
      printf("Child:  %d\n", getpid()); 

      pid_t me = getpid();
      pid_t parent = getppid();
      err = kill(parent,SIGCHLD);  // send a signal to parent just for kicks 
      if ( err < 0 ) {
          printf("\nError with SIGCHLD\n");
      }
      else
          printf("\nSent SIGCHLD to parent. %d.\n", getppid());

      alarm(6);  /* set an alarm in 7 seconds to kill yourself */
      counter = 6;

      while (1) {
         parent = getppid();
         sleep(1); 
         printf("me: %d parent: %d counter: %d\n", me, parent, counter);
         err = kill(parent,SIGTERM);
         if ( err < 0 ) 
            printf("\nSIGTERM ignored by %d\n", parent);
         else
            printf("\nSIGTERM accepted by %d\n", parent);
         counter--;

      }
      exit(0);
   }

   /* I AM THE PARENT */
   if ( getpid() == parent ) 
   {
      while (1) {
         sleep(secs);  /* do this to slow output to the screen down a bit */
         printf("\nFrom parent: patricide? oh no...\n");
      }
      exit (EXIT_SUCCESS);
   }
}
