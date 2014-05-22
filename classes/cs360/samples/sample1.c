/* filename: /examples/week02/sample1.c

  Demonstrate the use of SIGINT, SIGSTOP, SIGCONT and SIGTERM signals

  Compile

      $ gcc -o sample1 sample1.c
      $ ./sample1 

  Open another terminal window. Run top in that window:

       $ top -u [username] 

  Return to the first window. Hit CTRL-C. Ctrl-C generates a SIGINT signal
  to the process linked to the tty/keyboard that you hit Ctrl-C on. Note in 
  top that the process silently dies.
   
  Now execute sample1 in the background. In this run you will manually generate
  signals some signals with the kill shell command to your background process. 
  Note what happens to the status column (S) in top. You should see the status
  change from S (sleep) to T (traced or stopped), back to S and then disappear.

  Note: the S is a little misleading. Your process is not sleeping at all
  times. Top is taking most the CPU cycles thus is in state R (resident). Your 
  other processes are in fact resident at times but the time slice is so quick
  that you do not see it.

       $ ./sample1 &
       Help! 32360 is stuck in an infinite loop!
       [1] 32359                  # hit enter here to grab the keyboard

       $ kill -STOP 32360         # stop but do not terminate the process
       $ kill -CONT 32360         # continue the process
       continued
       $ kill -TERM 32360         # terminate the process
       [1]+  Terminated ./sample1
       $

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   /* the header file for the POSIX interface */

int main(void)
{
    printf("HELP! %d is stuck in an infinite loop!\n",getpid());
    while (1) {
        sleep(2);
    }

    printf("This code is never executed.\n");
    return 0;
}
