/*
 * SEI CERT C coding standard
 * RULE 50: 
 * POS38-C: Beware of race conditinos when using fork and file descriptors.
 * 
 * https://wiki.sei.cmu.edu/confluence/display/c/POS38-C.+Beware+of+race+conditions+when+using+fork+and+file+descriptors
 * 
 * If the file accessed has contents "abc", 
 * the output of this program could be either
 *
 * $ ./racecondition
   root process:a
   parent: b
   child: c

   or

   root process: a
   child: b
    parent: c
 */
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char c;
    pid_t pid;

    int fd = open("tttt.txt", O_RDWR);
    if( fd == -1) {
        // error
    }

    read(fd, &c, 1);
    printf("root process: %c\n", c);

    pid = fork();
    if( pid == -1 ) {
        // handle error
    }
    if( pid == 0) { /* child */
        read(fd, &c, 1);
        printf("child: %c\n", c);
    }
    else {          /* parent */
        read(fd, &c, 1);
        printf("parent: %c\n", c);
    }
}