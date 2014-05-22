/* lab01.c     
 * Demonstrate fork system call
 * 
 *  Compile and run with strace, logging stderr to outfile:
 *
 *    $ gcc lab01.c
 *    $ strace -f ./a.out  2> outfile        
 *
 *  Let it run without interruption (15 seconds) and view the outfile.
 *
 *  Run it again,
 *
 *     $ ./a.out
 *
 * and from another terminal, run top on the child's pid:
 *
 *    $ top -p [pid]
 *
 * Notes: The <unistd.h> header file defines the POSIX API 
 *
 */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int secs = 15;

int main()
{
   int i;

      /* do this so you can identify yourself later */
   int parent = getpid(); 

       /* display info from the parent process */
   printf("my info: userid %d , effective userid %d ", getuid(), geteuid()); 
   printf("my pid: %d parent pid: %d \n", getpid(), getppid());

      /* clone yourself - fork returns PID of the child to the parent 
      and 0 to the child or -1 to the parent on failure */

   printf("\nI'm duplicating myself..\n");
   int status;
   int child = fork();  /* returns PID of child to the parent, 0 to child */

   if ( child == 0 )   /* 0 means you are the child */
   {
      printf("i share %d with my parent at address %p \n", secs, &secs); 
      printf("Child Info: uid %d , euid %d ", getuid(), geteuid()); 
      printf(" pid: %d ppid: %d \n", getpid(), getppid());
      for ( i=1; i <=3; i++) 
      { 
          printf(" ... goo goo , gaa gaa ...\n");
          sleep(3);   
      }

      return exit(66);
   }

         /* check if you are the parent - this statement would also work:
         if ( getpid() == parent )   */
   if ( child != 0 ) 
   {
      pid_t r = wait(&status);
      if(WIFEXITED(status))
          printf("exited, status=%d\n", WEXITSTATUS(status));
       
      printf("\nI share %d with my child at address %p \n", secs, &secs); 
      for ( i=1; i <=3; i++) { 
         printf("Go to Sleep,\n");
         sleep(2); 
      } 
      printf("\nLittle Baby . ...\n");

      sleep( secs );
      exit (EXIT_SUCCESS);
   }
}
