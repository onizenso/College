/* programmer:  d meyers
   filename:    forks.c     
   project:     demonstrates ipc (interprocess control) and forking    */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void cleanup(int);

#define READER 0
#define WRITER 1

int main()
{
   int i;
   int parent = getpid(); 
   signal(SIGINT, cleanup); // trap signal and call cleanup
   printf("from parent: uid %d , euid %d ", getuid(), geteuid()); 
   printf(" pid: %d ppid: %d \n", getpid(), getppid());

   /* fork a writer process  */
   int writer = fork(); 
   // code for fork only
   if ( writer == 0 ) {
      for ( i=1; i <=3; i++) { 
        printf("writer fork uid: %d euid: %d  pid: %d  ppid: %d\n", getuid(), geteuid(), getpid(), getppid());
        sleep(3);   
      }
   }
   /* fork a reader processes */
   if ( getpid() == parent ) 
   {
   int reader = fork(); 
      // code for reader only   
      if ( reader == 0 ) {
        printf("reader fork uid: %d euid: %d  pid: %d  ppid: %d\n", getuid(), geteuid(), getpid(), getppid());
        sleep(3); 
       } 
   } 

  /* parent waits */
  if ( getpid() == parent){
      printf("parent waiting for 7 seconds....\n");
      sleep(7);
  }
}

void cleanup(int id)
{
   printf("Signal trapped. cleaning up....\n");
}
