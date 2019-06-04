/**********************************************************************
 * ex_unlink.c                                                        *
 * exmple source – test unlink                                        *
 **********************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = 0;
    fd = open("demo", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1)
    {
        perror("error open");
        return 1;
    }

    unlink("demo");

    char buf[10] = "Hello";
    int re = write(fd, buf, 10);
    if (re == 10)
    {
        printf("write ok\n");
    }
    else
    {
        printf("write fail\n");
    }
    close(fd);
    return 0;
}