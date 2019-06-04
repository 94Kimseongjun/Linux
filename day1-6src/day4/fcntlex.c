/*
$ cat > test.txt
abcdefgh
$ ./tcntlex test.txt
 */

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct utimebuf *timebuf = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    char *fname = argv[1]; //"test.txt";
    int fd, newfd;
    int flag;

    if ((fd = open(fname, O_RDWR | O_APPEND)) < 0)
    {
        perror("open( )");
        return 1;
    }

    flag = fcntl(fd, F_GETFL, 0);
    if (flag & O_APPEND)
        printf("fd: O_APPEND flag is set. \n");
    else
        printf("fd: O_APPEND flag is NOT set. \n");

    flag = fcntl(fd, F_GETFD, 0);
    if (flag & FD_CLOEXEC)
        printf("fd: FD_CLOEXEC flag is set. \n");
    else
        printf("fd: FD_CLOEXEC flag is NOT set. \n");

    fcntl(fd, F_SETFD, FD_CLOEXEC);
    flag = fcntl(fd, F_GETFD, 0);
    if (flag & FD_CLOEXEC)
        printf("fd: FD_CLOEXEC flag is set. \n");
    else
        printf("fd: FD_CLOEXEC flag is NOT set. \n");

    return 0;
}