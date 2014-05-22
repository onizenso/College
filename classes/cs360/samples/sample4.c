/* filename: sample4.c

   Demonstrate what happens when the signal handler for one signal is 
   interrupted by a second incoming signal. This is accomplished by hitting 
   CTRL-C while in the middle of a system call.

   Compile and execute:
 
       $ gcc -o sample4 sample4.c
       $ ./sample4

   Start typing something at the prompt but hit CTRL-C before finishing. Note 
   what happens. The system call fgets is interrupted and generates its own
   signal EINTR (interrupted system call). Some system calls can be restarted, 
   fgets() is one. Make the change noted, recompile and see what happens now.
   
   The prototype for a signal handler is: 

      void sigint_handler(int sig); 

    Read 
       $ man sigaction 
    for details on flags
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

volatile sig_atomic_t got_ctrlC = 0;

void sigint_handler(int sig)
{
    write(1, "Ahhh! SIGINT!\n", 14);  /* write is safe but printf is not */ 
    got_ctrlC = 1;
}

int main(void)
{
    char s[200];
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    /* if you do NOT want to restart your system call, set sa.sa_flags = 0;  */

    sa.sa_flags = 0;   
    sa.sa_flags = SA_RESTART; 

    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Enter a string:\n");

    if (fgets(s, sizeof s, stdin) == NULL)
        perror("fgets");
    else 
        printf("You entered: %s\n", s);

    return 0;
}
