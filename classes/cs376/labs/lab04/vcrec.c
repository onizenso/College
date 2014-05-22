/* This code is derived from the CMPS 376 networking code by Marc Thomas
 *
 * The purpose of this code is to create a very simple Internet server which
 * binds to a port, does a simple handshake with the client and then echos 
 * everything the client sends to the screen.
 *
 * Command line usage:
 *   $ vcrec [packet_size] &
 *
 *   if packet_size is specified, it must be a positive integer and only that
 *   many bytes will be read from the client.
 *
 * TCP/IP socket functions used by this program:
 * 
 *   socket()        Create a byte stream for client connection requests
 *   bind()          Bind the socket to IP address and request TCP port number
 *   getsockname()   Query what port number the system assigned to the process
 *   listen()        Wait for a client to issue a connection request
 *   accept()        Accept the connection request from a client
 *   send()          Send data to the client
 *   recv()          Receive data from the client
 *   close()         Close the sockets
 *
 * Connection process:
 *
 * vcsend                      vcrec
 * -------------------------   ------------------------- 
 *  
 * socket() (client socket)    socket() (listen socket)
 *                             bind()
 *                             getsockname()
 *                             listen()
 * connect() --------------->  accept() (creates 2nd data socket)
 *
 * (data exchange phase can be response-driven but if more
 *  than one descriptor must be managed use of select() is
 *  strongly recommended)
 * 
 * send() --------------------> recv()
 * recv() <-------------------- send()
 * 
 * close() (client socket)     close() (both data and listen socket)
 */
#ifndef ULIMIT
#define ULIMIT 255
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>      /* for gethostname() */
#include <arpa/inet.h>   /* for IP address structures and functions */


int main(int argc, char *argv[], char *envp[])
{
    int  sock, msgsock;  /* Sockets are integer file descriptors on Linux */
    struct  sockaddr_in  name, caller;
    char  chrline[80];
    char  buf[2048];
    int  i, size, length, ret, k;

    /* Variables for setting up select() */
    fd_set rfds;
    struct timeval tv;
    int retval;

    /* Watch stdin for activity */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    FD_SET(1, &rfds);

    tv.tv_sec = 4;
    tv.tv_usec = 20;

    /* Process the command line for the buffer size, if given */
    if(argc > 1)
    {
        size = atoi(argv[1]);
        /* Validate that the given argument is between 1 and sizeof(buf) - 1 
         * Set to the default size if argument is invalid */
        if(size < 1  ||  size > sizeof(buf) - 1) 
            size = sizeof(buf) - 1;
    }
    else
    {
        size = sizeof(buf) - 1;  /* Default size */
    }


    /* Create the listen socket. This is a TCP socket, so use SOCK_STREAM 
     * Exit if the socket cannot be created */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) 
    {
        perror("receiver: socket() failed. ");
        return -1;
    }


    /* Bind the socket to an IP address and port. We will use the IP address
     * INADDR_ANY, which tells the system to assign the IP address, and the
     * port number 0, which tells the system to assign a random port number.
     *
     * First we have to set the fields in the sockaddr_in object "name" and then
     * we can call bind(). Again, exit if bind() fails. */
    name.sin_family = AF_INET;         /* TCP/IP family */
    name.sin_addr.s_addr = INADDR_ANY; /* INADDR_ANY = assigned by system */
    name.sin_port = htons(0);           /* 0 = assigned by system */
    ret = bind(sock,(struct sockaddr *)&name,sizeof name);
    if(ret < 0)
    {
        perror("receiver: bind() failed. ");
        return -1;
    }

    /* In order to use vcsend to send data to this program, we need to know
     * what port number the system just assigned this program. So this segment
     * calls getsockname() to update the sockaddr_in object "name" with the
     * system assigned values and then print that info to the screen. */
    length = sizeof name;
    ret = getsockname(sock, (struct sockaddr *)&name, (socklen_t *)&length);
    if(ret < 0)
    {
        perror("receiver: getsockname() failed. ");
        return -1;
    }

    sleep(1);  /* pause for clean screen display */
    printf("\nreceiver: process id: %d ", (int)getpid());
    printf("\nreceiver: IP address: %d.%d.%d.%d",
            (ntohl(name.sin_addr.s_addr) & 0xff000000) >> 24,
            (ntohl(name.sin_addr.s_addr) & 0x00ff0000) >> 16,
            (ntohl(name.sin_addr.s_addr) & 0x0000ff00) >>  8,
            (ntohl(name.sin_addr.s_addr) & 0x000000ff));
    printf("\nreceiver: port number: %hu", ntohs(name.sin_port));
    printf("\n");
    fflush(stdout);

    /* Now we will call listen() and wait for a client to connect. The
     * accept() function will block until there is a client or an error. */

    listen(sock,5);    /* up to 5 clients can connect. only 1st is accepted */
    k = sizeof caller;
    msgsock = accept(sock, (struct sockaddr *)&caller, (socklen_t *)&k);

    /* We only reach this point when there is an error or a client. We can 
     * check the value of msgsock (the data socket) to see which has happened */

    if(msgsock == -1)
    {
        perror("receiver: accept() failed. ");
    }
    else
    {
        printf("\nreceiver: Valid connection received.\n");
        printf("receiver: Sending handshake.\n");
        fflush(stdout);

        /* let vcsend know we are ready by sending a single character */
        buf[0]= '0';    
        send(msgsock, buf, 1, 0);

        printf("receiver: Waiting for client....\n");

        while(1) {
            bzero(buf,sizeof buf);  /* zero buffer to remove old data */
            FD_ZERO(&rfds);
            FD_SET(0, &rfds);
            FD_SET(1, &rfds);
            FD_SET(msgsock, &rfds);


            /* recv() will block until the client sends information, the client
             * closes the connection or an error occurs on the data socket. */
            /* Check sock for data from user */
            retval = select(ULIMIT, &rfds, NULL, &rfds, &tv);

            if (retval == -1)
                perror("select()");
            else if (retval)
            {
                printf("Data available, sending message.\n");
                ret = send(msgsock, chrline, length + 1, 0);
                /* FD_ISSET(0, &rfds) will be true. */
            } 
            else
                printf("No data within five seconds.\n");

            if(ret < 0)
            {
                perror("receiver: recv() failed. ");
            }
            if(ret == 0)
            {
                printf("        received-->sender has ended connection \n");
                break;
            }
            else
            {
                printf("        received-->%s \n",buf);
            }

            /* Added sending portion to vcrec */
            printf("enter line> ");
            fflush(stdout);

            /* Read input from user */
            fgets(chrline, sizeof(chrline) - 1, stdin);
            /* Check for the period to end the connection and also convert any
             * newlines into null characters */
            for(i = 0 ; i < (sizeof(chrline) - 1) ; i++)
            {
                if( (chrline[i] == '\n') || (chrline[i] == '\0') )
                    break;
            }
            if(chrline[i] == '\n')
                chrline[i] = '\0';   /* get rid of newline */

            length = strlen(chrline);
            if(chrline[0] == '.')    /* end of stream */
            {
                printf("sender: termination requested \n");
                break; /* Exit out of loop */
            }

            retval = select(msgsock, &rfds, NULL, &rfds, &tv);

            if (retval == -1)
                perror("select()");
            else if (retval)
            {
                printf("Data available, sending message.\n");
                ret = send(msgsock, chrline, length + 1, 0);
                /* FD_ISSET(0, &rfds) will be true. */
            } 
            else
                printf("No data within five seconds.\n");

            if(ret < 0)
            {
                perror("sender: write() failed. ");
                break;  /* Exit out of loop */
            }

        } 
    }

    /* When we exit the recv() loop, the client has ended the connection, so
     * all that remains is closing the sockets. */

    printf("receiver: ending session also and exiting. \n");
    close(msgsock);    /* close data socket */
    close(sock);      /* close listen socket */

    return 0;
}  /* end of main */
