/*  cs360/Code/readwrite.c
 *
 *  Usage: ./readwrite <infile> <outfile> <bytes> 
 *
 *  Example:
 *     $ ./readwrite in out 20   # copy 20 bytes from in to out 
 *
 *  Demonstrates 
 *    o  use of system calls open(), read(), write()
 *    o  reading/writing to files or stdin/stdout 
 *    o  use of command-line arguments
 *
 *  To compile:   
 *      $ gcc -o readwrite readwrite.c
 *  
 *  For cmdline arguments:
 *   argv[0] holds name of executable; argv[1] holds first cmdline arg, etc.
 *   argc holds the number of cmdline args 
 * 
 *  You need to use read(),write() since printf and scanf are not atomic calls 
 *  Use printf for debugging purposes only.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DEBUG 0     /* flip this if you want verbose output */
#define MAXSZ 1024 /* this is the maximum number of bytes you can read */

int stdinYES = 0;  
char * infile;  /* the input filename */
char * outfile; /* the output filename */
int num_bytes;  /* the number of bytes you want to copy */
int infd;       /* file descriptor for infile */
int outfd;      /* file descriptor for outfile */

void cleanup();

int main( int argc, char * argv[])
{
  char buf[MAXSZ+1];  /* buf[] is for reads/writes - add one byte to hold \0 */
  int sz;

  if ( argc == 4) {  

     /* malloc grabs memory from heap */
     infile = (char *) malloc(sizeof(argv[1]));  

     strncpy(infile,argv[1],sizeof(argv[1]));  /* use strncpy to control size */
     if (strncmp(infile,"stdin",5)== 0) 
         stdinYES = 1;
     if (DEBUG) printf("Input Filename: %s\n",infile);

     outfile = (char *) malloc(sizeof(argv[2]));  
     strcpy(outfile,argv[2]);
     if (DEBUG) printf("Output Filename: %s\n",outfile);

     /* convert a string to an integer */
     num_bytes = atoi(argv[3]);

     /* convert an int to a string to display it with write */
     char str[10];
     sprintf(str,"%d\0",num_bytes);
     write(1,str,strlen(str));
  }

  else {
     printf("\nUsage: ./fileio [infile | stdin] outfile bytes\n");
     exit(EXIT_SUCCESS);
  }    

  /*   The open() system call returns a file descriptor. The various flags 
   *   control how the file is opened. O_CREAT creates the file if it does not 
   *   exist; if the file does exist O_TRUNC sets its size to 0; O_WRONLY
   *   opens the file in write only mode; 0644 sets file permissions to 644; 
   *   another useful flag is O_APPEND which appends to an existing file
   */


  /* open the output file for writing - truncate if already created */

  outfd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC , 0644);
  if (outfd < 0) {
     perror("open outfile");
     cleanup();
  }
  if (DEBUG) printf("File handle for outfile: %d\n",outfd);

  /* open the input file for reading unless stdin flag is set */
  if (stdinYES) 
     infd = 0;
  else {
     infd = open(infile, O_RDONLY);
     if (infd < 0) { 
        perror("open infile");
        cleanup();
     }
  }
  if (DEBUG) printf("File handle for infile: %d\n",infd);
  if (num_bytes > MAXSZ) num_bytes = MAXSZ; 
  sz = read(infd, buf, num_bytes);  /* returns the number of bytes read */
  if (DEBUG) printf("ACTUAL SIZE READ: %d\n",sz);
  if (sz < 0) { 
     perror("read");
  } 
  buf[sz] = '\0';   /* always mark the end of a string with \0 */

  if (DEBUG) printf("\n%s\nWe just read %d bytes.\n",buf,sz);

  if (write(outfd,buf,sz) < 0)   {  /* write to output file */
     perror("write");
  } 

  if (close(infd) < 0) { 
     perror("close infile");
  } 
  if (close(outfd) < 0) { 
     perror("close outfile");
  } 

  free(infile);  /* free what you allocate to prevent memory leaks */ 
  free(outfile);

  exit(EXIT_SUCCESS);
}

void cleanup() {
  close(infd);
  close(outfd);
  free(infile);  
  free(outfile);
  exit(EXIT_FAILURE);
}
