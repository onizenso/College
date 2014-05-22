/* filename:    semaphore.h
   project:     strong reader-writer problem   */

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <signal.h>

#define PERMS 0666
#define READER 0 
#define WRITER 1 

/* the following typedef is required under all UNIXs except BSD  */
union semun {
        int     val;            // value for SETVAL 
        struct  semid_ds *buf;  // buffer for IPC_STAT & IPC_SET      
        u_short *array;         // array for GETALL & SETALL       
}; 

int sem_init(int size, int val);  
void reader_unlock(int);
void writer_unlock (int);
void reader_lock (int);
void writer_lock (int);
void removeid (int);
