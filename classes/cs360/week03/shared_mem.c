/* filename: shared_mem.c

 Demonstate the use of SysV IPC shared memory mechanism by having a parent and 
 child read and write to a shared memory segment.

 Shared memory is a powerful and yet easy to implement component of the SysV 
 IPC suite. As the name implies, a block of memory is shared between processes.
 The program below calls fork(2) to split itself into a parent process and a 
 child process, communicating between the two using a shared memory segment.

    $ gcc shared_mem.c -o shared_mem

    $./shared_mem
    child  set 1, reads: 1
    parent set 2, reads: 2
    parent set 4, reads: 4
    child  set 3, reads: 4

    $./shared_mem
    parent set 2, reads: 2
    child  set 1, reads: 1
    parent set 4, reads: 4
    child  set 3, reads: 4

 The output will vary. It is a race condition as to whether instructions 
 in the parent or instructions in the child process will be scheduled by the 
 OS first. This code uses sleep in both the parent and the child to simulate
 some producer/consumer activity. This is simply done to demonstrate how shared
 memory works. NEVER use sleep to synchronize processes. Lab04 will introduce
 semaphores, which is what you will eventually use to synchronize.

 Note: under some flavors of Unix the parent and the child may have a different
 pointer address to the shared memory segment. It is a logical 'shared memory 
 segment' and the IPC interface takes care of sharing the areas. This would
 cause a problem with linked lists, thus for linked lists you would need to use
 relative addressing. The address in Linux is the same, so not a problem.

 The parameters to shmget are key, size, and flags. The size of the shared 
 memory area in this example is a single integer. The use of IPC_PRIVATE for 
 the IPC key means a unique IPC ID is guaranteed to be created. The process
 is thus responsible to distribute the ID. In the example, shmid is known by 
 both the parent and child because they are 'cloned' copies of each other. 

 NOTE AGAIN: 
 In this simple example, one process pauses while the other is writing to the 
 shared memory segment. In coming labs you will use semaphores (the third 
 component of the SysV IPC suite) to enforce mutual exclusion (locking one 
 process out while another process has access to the resource) and 
 synchronization (enforcing the order of access).

 Using sleep to control the order in which the parent and the child access
 shared memory is never a good idea, but for now it will have to do.

*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int status;

int main(void) {

    int ipckey=ftok("./foo", 21);   /* may or may not use this */
    int shmid; /* shared memory segment id - visible to both parent and child */

    /* create a shared memory segment-only do this once-the child inherits it
      shmget returns the identifier of the shared memory segment - IPC_PRIVATE
      means you are sharing memory with yourself and your child only 

      shmget returns the ID associated with the shared memory, not an address*/ 
    /* shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666); */
    shmid = shmget(ipckey, sizeof(int), IPC_CREAT | 0666); 

    if (fork() == 0) { /* child  */
        /* Attach to shared memory and print the pointer */
        int* shared = shmat(shmid, (void *) 0, 0);
        printf("\t\tchild  pointer:  %p\n", shared); 
        *shared=1;   /* modify shared memory segment */
        printf("child  set 1, reads: %d\n", *shared);
        *shared=3;   /* modify shared memory segment */
        sleep(2);
        printf("child  set 3, reads: %d\n", *shared);
        exit(0);

    } else { /* Parent */
        /* Attach to shared memory and print the pointer */
        int *shared = shmat(shmid, (void *) 0, 0);
        printf("\t\tParent pointer: %p\n", shared); 
        *shared=2;  /* modify shared memory segment */
        printf("parent set 2, reads: %d\n", *shared);
        sleep(1);
        *shared=4;  
        printf("parent set 4, reads: %d\n", *shared);
        sleep(5);
        wait(&status); /* wait for the child to die */
        shmdt(shared);
        /*  uncomment this to remove the shared mem */
        /* shmctl(shmid, IPC_RMID, 0);  */
    }
}
